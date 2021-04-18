#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <tuple>

#include "nopieceexception.h"
#include "nopieceownershipexception.h"
#include "invalidmovementexception.h"

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

void wait_to_hit_enter() {
    std::cout << "Please hit enter to continue...\n";
    std::cin.get();
    std::cin.get();
}

int main()
{
    system("Color 0F");
    printTitle();
    std::cin.get();
    

    ChessGame game;
    

    bool isPlayerATurn = true;
    while (true) {
        clearConsole();
        game.print();

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

        std::vector<std::tuple<int, int>> possibleMovements;
        try {
            if (isPlayerATurn) {
                possibleMovements = game.getPossibleMovementsForPlayerA(initialX, initialY);
            }
            else {
                possibleMovements = game.getPossibleMovementsForPlayerB(initialX, initialY);
            }
        }
        catch (const NoPieceException& e) {
            std::cout << e.what() << "\n";
            wait_to_hit_enter();

            continue;
        }
        catch (const NoPieceOwnershipException& e) {
            std::cout << e.what() << "\n";
            wait_to_hit_enter();

            continue;
        }
        catch (...) {
            std::cout << "An Unexpected error ocurred. Please contact with your administrator.";
            wait_to_hit_enter();

            continue;
        }

        if (possibleMovements.size() == 0) {
            std::cout << "Opps, Looks like you cannot move this piece anywhere...\n";
            wait_to_hit_enter();

            continue;
        }

        std::cout << "Possible movements for this piece are:\n";
        for (auto const &pos : possibleMovements) {
            std::cout << "- " << std::get<0>(pos) << ", " << std::get<1>(pos) << "\n";
        }

        std::cout << "It is player " << (isPlayerATurn ? "A" : "B") << " turn. Please introduce x, y final position:\n";
        std::cout << "X: ";
        std::cin >> finalX;
        std::cout << "Y: ";
        std::cin >> finalY;

        try {
            if (isPlayerATurn) {
                game.movePlayerAPiece(initialX, initialY, finalX, finalY);
            }
            else {
                game.movePlayerBPiece(initialX, initialY, finalX, finalY);
            }

            isPlayerATurn = !isPlayerATurn;
        }
        catch (const NoPieceException& e) {
            std::cout << e.what() << "\n";
            wait_to_hit_enter();

            continue;
        }
        catch (const NoPieceOwnershipException& e) {
            std::cout << e.what() << "\n";
            wait_to_hit_enter();

            continue;
        }
        catch (const InvalidMovementException & e) {
            std::cout << e.what() << "\n";
            wait_to_hit_enter();

            continue;
        }
        catch (...) {
            std::cout << "An Unexpected error ocurred. Please contact with your administrator.";
            wait_to_hit_enter();

            continue;
        }
    }
}