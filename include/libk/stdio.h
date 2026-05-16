#ifndef STDIO_H
#define STDIO_H

#include <stdint.h>

extern volatile uint16_t* VGA_MEM;
extern uint32_t VGA_WIDTH;
extern uint32_t VGA_HEIGHT;

#define COL_BLACK        0x0
#define COL_BLUE         0x1
#define COL_GREEN        0x2
#define COL_CYAN         0x3
#define COL_RED          0x4
#define COL_MAGENTA      0x5
#define COL_BROWN        0x6
#define COL_LIGHT_GRAY   0x7
#define COL_DARK_GRAY    0x8
#define COL_LIGHT_BLUE   0x9
#define COL_LIGHT_GREEN  0xA
#define COL_LIGHT_CYAN   0xB
#define COL_LIGHT_RED    0xC
#define COL_LIGHT_MAGENTA 0xD
#define COL_YELLOW      0xE
#define COL_WHITE        0xF

#define VGA_COLOR(fg, bg) ((bg << 4) | (fg))

void putchar(char c, uint16_t color);
void printk(const char* s);
void cprintk(const char* s, uint16_t color);

#endif // STDIO_H