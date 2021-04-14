#include <iostream>

#include "chessboard.h"

#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"

constexpr int BOARD_X_SIZE = 8;
constexpr int BOARD_Y_SIZE = 8;

/*TODO: Do we really need this no params constructor?, forced to instantiate ChessGame*/
ChessBoard::ChessBoard() 
	: ChessBoard::ChessBoard(ChessPlayer{ "Player A" }, ChessPlayer{ "Player B"}) {}

ChessBoard::ChessBoard(const ChessPlayer& playerA, const ChessPlayer& playerB) {
	this->pieces[0][0] = std::make_unique<Rook>(playerA);
	this->pieces[1][0] = std::make_unique<Knight>(playerA);
	this->pieces[2][0] = std::make_unique<Bishop>(playerA);
	this->pieces[3][0] = std::make_unique<Queen>(playerA);
	this->pieces[4][0] = std::make_unique<King>(playerA);
	this->pieces[5][0] = std::make_unique<Bishop>(playerA);
	this->pieces[6][0] = std::make_unique<Knight>(playerA);
	this->pieces[7][0] = std::make_unique<Rook>(playerA);

	this->pieces[0][1] = std::make_unique<Pawn>(playerA);
	this->pieces[1][1] = std::make_unique<Pawn>(playerA);
	this->pieces[2][1] = std::make_unique<Pawn>(playerA);
	this->pieces[3][1] = std::make_unique<Pawn>(playerA);
	this->pieces[4][1] = std::make_unique<Pawn>(playerA);
	this->pieces[5][1] = std::make_unique<Pawn>(playerA);
	this->pieces[6][1] = std::make_unique<Pawn>(playerA);
	this->pieces[7][1] = std::make_unique<Pawn>(playerA);

	this->pieces[0][2] = nullptr;
	this->pieces[1][2] = nullptr;
	this->pieces[2][2] = nullptr;
	this->pieces[3][2] = nullptr;
	this->pieces[4][2] = nullptr;
	this->pieces[5][2] = nullptr;
	this->pieces[6][2] = nullptr;
	this->pieces[7][2] = nullptr;

	this->pieces[0][3] = nullptr;
	this->pieces[1][3] = nullptr;
	this->pieces[2][3] = nullptr;
	this->pieces[3][3] = nullptr;
	this->pieces[4][3] = nullptr;
	this->pieces[5][3] = nullptr;
	this->pieces[6][3] = nullptr;
	this->pieces[7][3] = nullptr;

	this->pieces[0][4] = nullptr;
	this->pieces[1][4] = nullptr;
	this->pieces[2][4] = nullptr;
	this->pieces[3][4] = nullptr;
	this->pieces[4][4] = nullptr;
	this->pieces[5][4] = nullptr;
	this->pieces[6][4] = nullptr;
	this->pieces[7][4] = nullptr;

	this->pieces[0][5] = nullptr;
	this->pieces[1][5] = nullptr;
	this->pieces[2][5] = nullptr;
	this->pieces[3][5] = nullptr;
	this->pieces[4][5] = nullptr;
	this->pieces[5][5] = nullptr;
	this->pieces[6][5] = nullptr;
	this->pieces[7][5] = nullptr;

	this->pieces[0][6] = std::make_unique<Pawn>(playerB);
	this->pieces[1][6] = std::make_unique<Pawn>(playerB);
	this->pieces[2][6] = std::make_unique<Pawn>(playerB);
	this->pieces[3][6] = std::make_unique<Pawn>(playerB);
	this->pieces[4][6] = std::make_unique<Pawn>(playerB);
	this->pieces[5][6] = std::make_unique<Pawn>(playerB);
	this->pieces[6][6] = std::make_unique<Pawn>(playerB);
	this->pieces[7][6] = std::make_unique<Pawn>(playerB);

	this->pieces[0][7] = std::make_unique<Rook>(playerB);
	this->pieces[1][7] = std::make_unique<Knight>(playerB);
	this->pieces[2][7] = std::make_unique<Bishop>(playerB);
	this->pieces[3][7] = std::make_unique<Queen>(playerB);
	this->pieces[4][7] = std::make_unique<King>(playerB);
	this->pieces[5][7] = std::make_unique<Bishop>(playerB);
	this->pieces[6][7] = std::make_unique<Knight>(playerB);
	this->pieces[7][7] = std::make_unique<Rook>(playerB);
}

void ChessBoard::print() const noexcept {
	std::cout << "I am a board\n";

	std::cout << "These pieces in the board are\n";
	for (int j = 0; j < BOARD_Y_SIZE; j++) {
		for (int i = 0; i < BOARD_X_SIZE; i++) {
			if (this->pieces[i][j] == nullptr) {
				std::cout << "NULL\n";
			}
			else {
				this->pieces[i][j]->print();
			}
		}
	}
}