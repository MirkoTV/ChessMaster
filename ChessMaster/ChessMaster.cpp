#include <iostream>

#include "chesscore.h"
#include "chessboard.h"

int main()
{
    const char* result = init_chess_core();
    std::cout << "Hello World!\n";

    std::cout << result << "\n";

    ChessBoard board;

    board.print();
}
