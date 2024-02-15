#include <ncurses.h>
#include <iostream>

int main() {
	std::string block = "██";
	setlocale(LC_ALL, "");
	initscr();
    //cbreak(); // Disable line buffering
    noecho(); // Don't echo input

    // Display a prompt
    printw("Press 'q' to quit...\n");
    refresh(); // Refresh the screen to show the prompt

    // Read user input in a loop
    int ch;
    while ((ch = getch()) != 'q') {
		printw("%s\n", block.c_str());
		refresh();
    }

    // End ncurses
    endwin();

    return 0;
}
