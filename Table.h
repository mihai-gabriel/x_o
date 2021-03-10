//
// Created by mihai on 10/03/2021.
//

#ifndef XO_TABLE_H
#define XO_TABLE_H

#include <cstdint>

const uint32_t table_size = 3;

class Table {
public:
    Table(); // initialize table with '-' everywhere
    ~Table() = default;

    void draw_table() const; // display table
    void display_game_status(bool valid_move) const;

    bool check_draw() const;

    bool is_empty(int line, int column) const; // check for empty position

    bool check_position(int position) const;

    void pos_to_coords(int position, int &line, int &column);

    bool game_finish();

    bool make_move(int position); // alternates between x and 0

    void announce_winner() const;

private:
    char table[table_size][table_size]{};
    char last_move = '0';
    char on_move = 'x';
    char winner = '-';
};

#endif //XO_TABLE_H
