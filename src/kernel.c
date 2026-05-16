#include "../include/libk/stdio.h"

void kernel_main() {
    printk("Welcome to ");

    cprintk("Arc", VGA_COLOR(COL_CYAN, COL_BLACK));
    cprintk("OS", VGA_COLOR(COL_LIGHT_CYAN, COL_BLACK));

    printk("!");

    while (1);
}