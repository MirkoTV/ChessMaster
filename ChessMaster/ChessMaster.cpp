#include <iostream>
#include <string>

#include "chesscore.h"
#include "chessgame.h"

int main()
{
     const char* result = init_chess_core();
     std::cout << result << "\n\n";
    
    std::cout << "*********************** Welcome to a new ChessMaster Game! ***********************\n\n";
    
    std::string playerAName;
    std::string playerBName;

    std::cout << "Please introduce Player A Name (Player A): ";
    std::getline(std::cin >> std::ws, playerAName);
    std::cout << "Please introduce Player B Name (Player B): ";
    std::getline(std::cin >> std::ws, playerBName);


    ChessGame game { playerAName, playerBName };

    game.print();
}
