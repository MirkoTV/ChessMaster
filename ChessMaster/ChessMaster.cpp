#include <iostream>

#include "chesscore.h"
#include "chessboard.h"
#include "chesspiece.h"

int main()
{
    const char* result = init_chess_core();
    std::cout << "Hello World!\n";

    std::cout << result << "\n";

    ChessPiece piece;

    piece.print();

    ChessBoard board;

    board.print();
}
