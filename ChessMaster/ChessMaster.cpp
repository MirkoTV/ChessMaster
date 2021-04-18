#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <tuple>

#include "nopieceexception.h"
#include "nopieceownershipexception.h"
#include "invalidmovementexception.h"
#include "movementgeneratescheckexception.h"

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

void printBoard(const ChessGame& game) noexcept {
    int board_x_size = game.get_board_x_size();
    int board_y_size = game.get_board_y_size();

    std::cout << "     0     1     2     3     4     5     6     7        \n";
    for (int j = 0; j < board_x_size; j++) {
        std::cout << "  -------------------------------------------------\n";
        std::cout << j << " ";
        for (int i = 0; i < board_y_size; i++) {
            std::cout << "|";
            if (game.get_piece_at(i, j) == nullptr) {
                std::cout << "     ";
            }
            else {
                std::cout << " " << game.get_piece_at(i, j)->to_string_by_player() << " ";
            }
        }
        std::cout << "| " << j << "\n";
    }
    std::cout << "  -------------------------------------------------\n";
    std::cout << "     0     1     2     3     4     5     6     7        \n";
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
        printBoard(game);

        if (isPlayerATurn) {
            system("Color 0E");
        }
        else {
            system("Color 0B");
        }

        if (isPlayerATurn && game.is_player_a_in_check()) {
            std::cout << "Player A is right now checked!\n";
        }
        else if (game.is_player_b_in_check()){
            std::cout << "Player B is right now checked!\n";
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
        catch (const MovementGeneratesCheckException& e) {
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