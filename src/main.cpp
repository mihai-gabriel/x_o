#include <iostream>
#include "Table.h"


void show_introduction();

void get_user_input(char &pos);


void game() {
    Table g_table;
    char position = 0;
    bool valid_move = true, g_end = false;

    show_introduction();

    while (!g_end) {
        g_table.display_game_status(valid_move);

        get_user_input(position); // ref: position
        if (position == 'q') break;
        position -= '0'; // get the integer digit from ASCII digit

        valid_move = g_table.make_move(position); // implicit conversion from char to int
        if (valid_move)
            g_end = g_table.game_finish();
        system("cls");
    }

    g_table.announce_winner();
}

int main() {
    game();
    return 0;
}

void show_introduction() {
    std::cout << "Welcome!\nTable format:\n1 2 3\n4 5 6"
              << " --> Each digit corresponds \n7 8 9     to a position.\n"
              << "\nEnter 'q' to exit. Have Fun!" << std::endl;
}

void get_user_input(char &pos) {
    std::cout << "Position (1 - 9): " << std::endl;
    std::cin >> pos;
}
