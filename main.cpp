#include <iostream>
#include <string>
#include <format>

#include "board.cpp"

int main() {
    Board board = Board_new();
    std::cout << std::to_string(board) << std::endl;
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Piece piece = Board_getSquare(board, 8 * i + j);
            std::cout << std::string(1, Piece_toChar(piece)) + " " << std::flush;
        }
        std::cout << std::endl;
    }

    std::cout << "done" << std::endl;
    return 0;
}