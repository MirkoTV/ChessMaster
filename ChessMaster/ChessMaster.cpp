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



    int initialX;
    int initialY;
    int finalX;
    int finalY;

    std::cout << "It is player " << playerAName << ". Please introduce x, y initial position:\n";
    std::cout << "X: ";
    std::cin >> initialX;
    std::cout << "Y: ";
    std::cin >> initialY;

    std::cout << "It is player " << playerAName << ". Please introduce x, y final position:\n";
    std::cout << "X: ";
    std::cin >> finalX;
    std::cout << "Y: ";
    std::cin >> finalY;

    game.movePlayerAPiece(initialX, initialY, finalX, finalY);

    game.print();
}
