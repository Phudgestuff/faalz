#ifndef DISPLAY_H
#define DISPLAY_H

#include <ncurses.h>

char get_char(int y, int x);
int set_area_colour(int y1, int x1, int y2, int x2, int foreground, int background);
void set_bottom_bar_text(char* text);
void init_display();

#endif
