#include <ncurses.h>

#include "extra_colours.h"

/**
 * get_char
 *
 * Move the cursor to a given coordinate and returns the char at that location.
 *
 * @param y The y coordinate of the char
 * @param x The x coordinate of the char
 *
 * @return The char at y,x
 */
char get_char(int y, int x) {
    chtype raw_data = mvinch(y, x);
    return raw_data & A_CHARTEXT; // mask to get only the char
}

/**
 * set_area_colour_by_pair
 *
 * Sets the colour of a given rectangle using a given pair and coordinates.
 *
 * @param y1 The top left y coordinate of the area.
 * @param x1 The top left x coordinate of the area.
 * @param y2 The bottom right y coordinate of the area.
 * @param x2 The bottom right x coordinate of the area.
 * @param pair The id of the colour pair
 *
 * @param foreground The text colour of the area.
 * @param background The background colour of the area.
 *
 * @return -1 If the coordinates are invalid, and 0 if successful
 */
int set_area_colour(int y1, int x1, int y2, int x2, int pair) {
    // if the top left coordinates are larger than the bottom right, the coords
    // are invalid
    if (y1 > y2 || x1 > x2) {
        return -1;
    }   

    attron(COLOR_PAIR(pair));

    // iterate through all cells and set the colour
    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            // don't change the char
            mvaddch(i, j, get_char(i, j));
        }
    }
    attroff(COLOR_PAIR(pair));   

    return 0;
}

/**
 * set_bottom_bar_text
 *
 * Sets the text on the bottom bar.
 */
void set_bottom_bar_text(char* text) {
    attron(COLOR_PAIR(COLOR_PAIR_BAR));
    mvprintw(LINES-1, 0, "%s", text);
    attroff(COLOR_PAIR(COLOR_PAIR_BAR));
}

/**
 * init_display
 *
 * Sets up the default window view of Faalz.
 */
void init_display() {
    init_pair(COLOR_PAIR_BAR, COLOR_WHITE, COLOR_GREY);

    // set top and bottom bars to grey and add default message
    set_area_colour(0, 0, 0, COLS-1, COLOR_PAIR_BAR);
    set_area_colour(LINES-1, 0, LINES-1, COLS-1, COLOR_PAIR_BAR);

    set_bottom_bar_text("Hello");
}

