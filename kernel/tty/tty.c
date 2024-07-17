#include <lunaix/tty/tty.h>
#include <stdint.h>

#define TTY_WIDTH 80
#define TTY_HEIGHT 25

vga_atrributes *buffer = 0xB8000;

vga_atrributes theme_color = VGA_COLOR_BLACK;

uint32_t tty_column = 0;
uint16_t tty_row = 0;

void tty_set_theme(vga_atrributes fg, vga_atrributes bg) {
    theme_color = (bg << 4 | fg) << 8;
}

void tty_put_char(char chr) {
    if (chr == '\r') {
        tty_column = 0;
    } else if (chr == '\n') {
        tty_column = 0;
        tty_row++;
    } else {
        *(buffer + tty_row * TTY_WIDTH + tty_column) = (theme_color | chr);
        tty_column++;
        if (tty_column >= TTY_WIDTH) {
            tty_row++;
            tty_column = 0;
        }

        if (tty_row >= TTY_HEIGHT) {
            tty_scroll_up();
            tty_row--;
        }
    }
}

void tty_put_str(char* str) {
    while (*str != '\0') {
        tty_put_char(*str);
        str++;
    }
}

void tty_scroll_up() {
    // TODO use memcpy
}

void tty_clear() {
    for (uint32_t row = 0; row < TTY_HEIGHT; ++row) {
        for (uint32_t col = 0; col < TTY_WIDTH; ++col) {
            *(buffer + row * TTY_WIDTH + col) = VGA_COLOR_BLACK;
        }
    }
}