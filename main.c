/*
 * Faalz
 *
 * This is a file explorer utility that I'm making as a personal project so
 * that I can visually navigate my filesystem in the terminal.
 */

#include <ncurses.h>

#include "display.h"

int main() {
    // init
    initscr();
    noecho();
    cbreak();
    start_color();

    init_display();

    // set up input loop
    bool running = true;
    while (running) {
        int in;
        in = getch();

        switch (in) {
            // q = quit
            case 'q':
                running = false;
                break;

            default:
                break;
        }

        refresh();
    }

    return 0;
}


