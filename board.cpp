#include "packed_column.cpp"
#include <format>

int getSquareFromCoordinates(int column, int row) {
    return 8 * column + row;
}

class Board {
private:
    PackedColumn _columns[8];
public:
    Board create();
    Piece getSquare(int square);
    void setSquare(int square, Piece& piece);
    std::string toString();
};


Piece Board::getSquare(int square) {
    
}

void Board::setSquare(int square, Piece& piece) {
    if (Piece_isEmpty(piece)) return;
    
}

Board Board::create() {
    Board board;
    
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
        Board::setSquare(63 - j, startingPosition[j]);
    }
    
    return board;
}

std::string Board::toString() {
    std::string resultant = "";

    for (int i = 0; i < 8; i++) {
        PackedColumn currentColumn = _columns[7 - i];
        resultant += std::format("{} {}\n", 8 - i, PackedColumn_toString(currentColumn));
    }
    resultant += "  abcdefgh";

    return resultant;
}