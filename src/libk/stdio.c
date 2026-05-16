#include "../../include/libk/stdio.h"

volatile uint16_t* VGA_MEM = (volatile uint16_t*)0xB8000;
uint32_t VGA_WIDTH = 80;
uint32_t VGA_HEIGHT = 25;

uint32_t cursorPosX = 0;
uint32_t cursorPosY = 0;

void scrollUp() {
    for (uint32_t y = 1; y < VGA_HEIGHT; y++) {
        for (uint32_t x = 0; x < VGA_WIDTH; x++) {
            VGA_MEM[(y - 1) * VGA_WIDTH + x] = VGA_MEM[y * VGA_WIDTH + x];
        }
    }

    for (uint32_t x = 0; x < VGA_WIDTH; x++) {
        VGA_MEM[(VGA_HEIGHT - 1) * VGA_WIDTH + x] = (0x0F << 8) | ' ';
    }
}

void putchar(char c, uint16_t color) {
    if (c == '\n') {
        cursorPosX = 0;
        cursorPosY++;
    } else {
        VGA_MEM[cursorPosY * VGA_WIDTH + cursorPosX] = (color << 8) | c;
        cursorPosX++;
    }

    if (cursorPosX >= VGA_WIDTH) {
        cursorPosX = 0;
        cursorPosY++;
    }

    if (cursorPosY >= VGA_HEIGHT) {
        scrollUp();
        cursorPosY = VGA_HEIGHT - 1;
    }
}

void cprintk(const char *s, uint16_t color) {
    while (*s) {
        putchar(*s++, color);
    }
}

void printk(const char *s) { 
    while (*s) {
        putchar(*s++, VGA_COLOR(COL_WHITE, COL_BLACK));
    }
}