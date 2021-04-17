#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <tuple>

#include "chesscore.h"
#include "chessgame.h"

void printTitle() {
    static const char ok_lines[] =
    {
        "                                                                                                                      \n"
        "                                                                                                                      \n"
        "  ********************************************************************************************************************\n"
        "  *                                                                                                                  *\n"
        "  *           *******       **                                                                                       *\n"
        "  *         ***********     **                                                                                       *\n"
        "  *       ***               **                 *******                 *********                *********            *\n"
        "  *      ***                **               ***********             ****      ****           ****      ****         *\n"
        "  *      ***                ** *****        ****      ****         ****                     ****                     *\n"
        "  *      ***                ****   **       **************           ***********              ***********            *\n"
        "  *       ***               ***     **      ****                        ***********              ***********         *\n"
        "  *         ***********     **      **       ****                  *****       ****         *****       ****         *\n"
        "  *           *******       **      **        *******                 *********                *********             *\n"
        "  *                                                                                                                  *\n"
        "  *                                                                                                                  *\n"
        "  *                                                                                                                  *\n"
        "  *                                   Welcome to a new ChessMaster Game!                                             *\n"
        "  *                                        Hit Enter to continue...                                                  *\n"
        "  *                                                                                                                  *\n"
        "  *                                                                                                                  *\n"
        "  ********************************************************************************************************************\n"
    };

    std::cout << ok_lines;
}

void clearConsole() {
    // Windows Only
    std::system("cls");
}

int main()
{
    system("Color 0F");
    printTitle();
    std::cin.get();
    clearConsole();

    ChessGame game;
    game.print();

    bool isPlayerATurn = true;
    while (true) {
        if (isPlayerATurn) {
            system("Color 0E");
        }
        else {
            system("Color 0B");
        }
        int initialX;
        int initialY;
        int finalX;
        int finalY;


        std::cout << "It is player " << (isPlayerATurn ? "A" : "B") << " turn. Please introduce x, y initial position:\n";
        std::cout << "X: ";
        std::cin >> initialX;
        std::cout << "Y: ";
        std::cin >> initialY;

        std::vector<std::tuple<int, int>> possibleMovements = game.getPossibleMovements(initialX, initialY);

        std::cout << "Possible movements for this piece are:\n";
        for (auto const &pos : possibleMovements) {
            std::cout << "- " << std::get<0>(pos) << ", " << std::get<1>(pos) << "\n";
        }

        std::cout << "It is player " << (isPlayerATurn ? "A" : "B") << " turn. Please introduce x, y final position:\n";
        std::cout << "X: ";
        std::cin >> finalX;
        std::cout << "Y: ";
        std::cin >> finalY;

        if (isPlayerATurn) {
            game.movePlayerAPiece(initialX, initialY, finalX, finalY);
        }
        else {
            game.movePlayerBPiece(initialX, initialY, finalX, finalY);
        }
        
        isPlayerATurn = !isPlayerATurn;
        
        clearConsole();
        game.print();
    }
}