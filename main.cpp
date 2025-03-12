#include <iostream>
#include <string>
#include <format>

#include "board.cpp"

int main() {
    Board board = Board_new();
    std::cout << std::to_string(board) << std::endl;
    
    for (int i = 0; i < 64; i++) {
        Piece piece = Board_getSquare(board, i);
        std::cout << std::string(1, Piece_toChar(piece)) + " \n"[(i + 1) % 8 == 0] << std::flush;
    }

    std::cout << "done" << std::endl;
    return 0;
}