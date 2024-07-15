#include <lunaix/tty/tty.h>
#include <stdint.h>

#define TTY_WIDTH 80
#define TTY_HEIGHT 25

vga_atrributes *buffer = 0xB8000;

vga_atrributes theme_color = VGA_COLOR_BLACK;

uint32_t TTY_COLUMN = 0;
uint16_t TTY_ROW = 0;

void tty_set_theme(vga_atrributes fg, vga_atrributes bg) {
    
}

void tty_put_char(char chr) {

}

void tty_put_str(char* str) {

}

void tty_scroll_up() {
    // TODO use memcpy
}

void tty_clear() {

}