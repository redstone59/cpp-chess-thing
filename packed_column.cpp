#include "piece.cpp"

// A `PackedColumn` stores 8 `Piece`s side by side.
// 
// For the PackedColumn with value `1126523444`:
// ```
//    Index:    0    1    2    3    4    5    6    7
//      Row:    1    2    3    4    5    6    7    8
//    Piece: 0100 0011 0010 0101 0110 0010 0011 0100
// Notation:    r    n    b    q    k    b    n    r
// ```
// 
typedef uint32_t PackedColumn;

PackedColumn PackedColumn_new() {
    return 0;
}

Piece PackedColumn_getIndex(PackedColumn& column, int index) {
    int shiftDistance = 4 * (7 - index);
    return static_cast<Piece>((column >> shiftDistance) & 0b1111);
}

void PackedColumn_setIndex(PackedColumn& column, int index, Piece piece) {
    int shiftDistance = 4 * (7 - index);
    PackedColumn mask = ~(0b1111 << shiftDistance);
    PackedColumn shiftedPiece = static_cast<PackedColumn>(piece) << shiftDistance;
    column = (column & mask) | shiftedPiece;
}

std::string PackedColumn_toString(PackedColumn& column) {
    std::string resultant = "";

    for (int i = 0; i < 8; i++) {
        Piece piece = PackedColumn_getIndex(column, i);
        resultant += Piece_toChar(piece);
    }

    return resultant;
}