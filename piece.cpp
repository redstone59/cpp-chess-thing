#include <stdint.h>
#include <cctype>
#include <string>

#define PIECE_TYPE(piece)                                \
    (piece == 'p' || piece == 'P') ? PieceType::PAWN   : \
    (piece == 'b' || piece == 'B') ? PieceType::BISHOP : \
    (piece == 'n' || piece == 'N') ? PieceType::KNIGHT : \
    (piece == 'r' || piece == 'R') ? PieceType::ROOK   : \
    (piece == 'q' || piece == 'Q') ? PieceType::QUEEN  : \
    (piece == 'k' || piece == 'K') ? PieceType::KING   : PieceType::ERROR
#define PIECE(piece) Piece_new(PIECE_TYPE(piece), isupper(piece))

typedef uint8_t Piece;

enum PieceType {
    ERROR, // Should never be accessed
    PAWN,
    BISHOP,
    KNIGHT,
    ROOK,
    QUEEN,
    KING
};

Piece Piece_new(PieceType type, bool isBlack) {
    Piece piece = static_cast<Piece>(type);
    if (isBlack)
        piece |= 0b1000;
    return piece;
}

bool Piece_isEmpty(Piece& piece) {
    return piece == 0b0000;
}

bool Piece_isBlack(Piece& piece) {
    return (piece & 0b1000) > 0;
}

PieceType Piece_type(Piece& piece) {
    return static_cast<PieceType>(piece & 0b0111);
}

char Piece_toChar(Piece& piece) {
    if (Piece_isEmpty(piece)) return ' ';
    char pieceChar = "pbnrqk"[Piece_type(piece) - 1];
    return Piece_isBlack(piece) ? std::toupper(pieceChar) : pieceChar;
}