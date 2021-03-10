//
// Created by mihai on 10/03/2021.
//

#include <iostream>
#include <utility>
#include "Table.h"
#include "utils.h"


Table::Table() {
    for (int i = 0; i < table_size; ++i) {
        for (int j = 0; j < table_size; ++j) {
            table[i][j] = '-';
        }
    }
}

void Table::draw_table() const {
    for (int i = 0; i < table_size; ++i) {
        for (int j = 0; j < table_size; ++j) {
            std::cout << table[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Table::display_game_status(bool valid_move) const {
    if (!valid_move)
        std::cout << "Invalid move!" << std::endl;
    std::cout << "Current table state (" << this->on_move << " to move):" << std::endl;
    this->draw_table();
}

void Table::announce_winner() const {
    if (this->winner != '-') {
        this->draw_table();
        std::cout << "Game Result: ";
        if (this->winner == 'd')
            std::cout << "Draw" << std::endl;
        else
            std::cout << this->winner << " won." << std::endl;
        std::cout << "The program will end in 3 seconds." << std::endl;
        sleep(3000);
    }
}

bool Table::check_draw() const {
    for (int i = 0; i < table_size; ++i) {
        for (int j = 0; j < table_size; ++j) {
            if (table[i][j] == '-') return false;
        }
    }
    return true;
}

bool Table::is_empty(int line, int column) const {
    return table[line][column] == '-';
}

bool Table::check_position(int position) const {
    return !(position < 1 || position > 9);
}

void Table::pos_to_coords(int position, int &line, int &column) {
    line = static_cast<int>((position - 1) / table_size);
    column = (position - 1) % table_size;
}

bool Table::game_finish() {
    for (int i = 0; i < table_size; ++i) {
        // check for columns and lines
        if (((table[i][0] == table[i][1] && table[i][0] == table[i][2]) && (table[i][0] != '-')) ||
            ((table[0][i] == table[1][i] && table[0][i] == table[2][i]) && (table[0][i] != '-'))) {
            winner = last_move;
            return true;
        }
    }

    // check for main diagonal
    if ((table[0][0] == table[1][1] && table[0][0] == table[2][2]) && (table[0][0] != '-')) {
        winner = last_move;
        return true;
    }

    // check for second diagonal
    if ((table[0][2] == table[1][1] && table[0][2] == table[2][0]) && (table[0][2] != '-')) {
        winner = last_move;
        return true;
    }

    // if the game is not won, check for a draw
    if (check_draw()) {
        winner = 'd';
        return true;
    }

    return false;
}

bool Table::make_move(int position) {
    int line, column;

    // Validate position
    if (!this->check_position(position))
        return false;

    // Convert position into coords
    pos_to_coords(position, line, column); // ref: line, column

    // Check if the place from coords is empty
    if (!this->is_empty(line, column))
        return false;

    // Finally make the move, keep track of current and last moves
    if (last_move == 'x') {
        table[line][column] = '0';
        std::swap(on_move, last_move);
    } else {
        table[line][column] = 'x';
        std::swap(on_move, last_move);
    }

    return true;
}



