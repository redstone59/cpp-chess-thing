#include "piece.cpp"
#include <iostream>
#include <format>

// Ordered by 
typedef uint32_t Board;

int getSquareFromCoordinates(int column, int row) {
    return 8 * column + row;
}

Piece Board_getSquare(Board& board, int square) {
    int shiftDistance = 4 * (64 - square);
    return static_cast<Piece>((board >> shiftDistance) & 0b1111);
}

void Board_setSquare(Board& board, int square, Piece& piece) {
    if (Piece_isEmpty(piece)) return;
    int shiftDistance = 4 * (64 - square);
    Board mask = ~(0b1111 << shiftDistance);
    Board pieceInSquare = static_cast<Board>(piece) << shiftDistance;
    board &= mask;
    board |= pieceInSquare;
}

Board Board_new() {
    Board board = 0;
    
    Piece startingPosition[] = {
        PIECE('R'), PIECE('N'), PIECE('B'), PIECE('Q'), PIECE('K'), PIECE('B'), PIECE('N'), PIECE('R'),
        PIECE('P'), PIECE('P'), PIECE('P'), PIECE('P'), PIECE('P'), PIECE('P'), PIECE('P'), PIECE('P'),
                 0,          0,          0,          0,          0,          0,          0,          0,
                 0,          0,          0,          0,          0,          0,          0,          0,
                 0,          0,          0,          0,          0,          0,          0,          0,
                 0,          0,          0,          0,          0,          0,          0,          0,
        PIECE('p'), PIECE('p'), PIECE('p'), PIECE('p'), PIECE('p'), PIECE('p'), PIECE('p'), PIECE('p'),
        PIECE('r'), PIECE('n'), PIECE('b'), PIECE('q'), PIECE('k'), PIECE('b'), PIECE('n'), PIECE('r')
    };

    for (int j = 0; j < 64; j++) {
        std::cout << std::format("Square {:>2}: {}", j, Piece_toChar(startingPosition[j])) << std::endl;
        Board_setSquare(board, j, startingPosition[j]);
    }
    
    return board;
}

std::string Board_toString(Board& board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int square = getSquareFromCoordinates(i, j);
        }
    }

    return "";
}