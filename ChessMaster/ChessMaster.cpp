#include <iostream>

#include "chesscore.h"
#include "chessgame.h"

int main()
{
    const char* result = init_chess_core();
    std::cout << "Hello World!\n";

    std::cout << result << "\n";

    ChessGame game;

    game.print();
}
