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
	: ChessBoard::ChessBoard(ChessPlayer{ "Player A" }, ChessPlayer{ "Player B", true }) {}

ChessBoard::ChessBoard(const ChessPlayer& playerA, const ChessPlayer& playerB) {
	this->pieces[0][0] = std::make_shared<Rook>(playerA);
	this->pieces[1][0] = std::make_shared<Knight>(playerA);
	this->pieces[2][0] = std::make_shared<Bishop>(playerA);
	this->pieces[3][0] = std::make_shared<Queen>(playerA);
	this->pieces[this->kingAPos[0]][this->kingAPos[1]] = std::make_shared<King>(playerA);
	this->pieces[5][0] = std::make_shared<Bishop>(playerA);
	this->pieces[6][0] = std::make_shared<Knight>(playerA);
	this->pieces[7][0] = std::make_shared<Rook>(playerA);

	this->pieces[0][1] = std::make_shared<Pawn>(playerA);
	this->pieces[1][1] = std::make_shared<Pawn>(playerA);
	this->pieces[2][1] = std::make_shared<Pawn>(playerA);
	this->pieces[3][1] = std::make_shared<Pawn>(playerA);
	this->pieces[4][1] = std::make_shared<Pawn>(playerA);
	this->pieces[5][1] = std::make_shared<Pawn>(playerA);
	this->pieces[6][1] = std::make_shared<Pawn>(playerA);
	this->pieces[7][1] = std::make_shared<Pawn>(playerA);

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

	this->pieces[0][6] = std::make_shared<Pawn>(playerB);
	this->pieces[1][6] = std::make_shared<Pawn>(playerB);
	this->pieces[2][6] = std::make_shared<Pawn>(playerB);
	this->pieces[3][6] = std::make_shared<Pawn>(playerB);
	this->pieces[4][6] = std::make_shared<Pawn>(playerB);
	this->pieces[5][6] = std::make_shared<Pawn>(playerB);
	this->pieces[6][6] = std::make_shared<Pawn>(playerB);
	this->pieces[7][6] = std::make_shared<Pawn>(playerB);
							  
	this->pieces[0][7] = std::make_shared<Rook>(playerB);
	this->pieces[1][7] = std::make_shared<Knight>(playerB);
	this->pieces[2][7] = std::make_shared<Bishop>(playerB);
	this->pieces[3][7] = std::make_shared<Queen>(playerB);
	this->pieces[this->kingBPos[0]][this->kingBPos[1]] = std::make_shared<King>(playerB);
	this->pieces[5][7] = std::make_shared<Bishop>(playerB);
	this->pieces[6][7] = std::make_shared<Knight>(playerB);
	this->pieces[7][7] = std::make_shared<Rook>(playerB);

	this->playerAPieces.push_back(this->pieces[0][0]);
	this->playerAPieces.push_back(this->pieces[1][0]);
	this->playerAPieces.push_back(this->pieces[2][0]);
	this->playerAPieces.push_back(this->pieces[3][0]);
	this->playerAPieces.push_back(this->pieces[this->kingAPos[0]][this->kingAPos[1]]);
	this->playerAPieces.push_back(this->pieces[5][0]);
	this->playerAPieces.push_back(this->pieces[6][0]);
	this->playerAPieces.push_back(this->pieces[7][0]);

	this->playerAPieces.push_back(this->pieces[0][1]);
	this->playerAPieces.push_back(this->pieces[1][1]);
	this->playerAPieces.push_back(this->pieces[2][1]);
	this->playerAPieces.push_back(this->pieces[3][1]);
	this->playerAPieces.push_back(this->pieces[4][1]);
	this->playerAPieces.push_back(this->pieces[5][1]);
	this->playerAPieces.push_back(this->pieces[6][1]);
	this->playerAPieces.push_back(this->pieces[7][1]);

	this->playerBPieces.push_back(this->pieces[0][6]);
	this->playerBPieces.push_back(this->pieces[1][6]);
	this->playerBPieces.push_back(this->pieces[2][6]);
	this->playerBPieces.push_back(this->pieces[3][6]);
	this->playerBPieces.push_back(this->pieces[this->kingBPos[0]][this->kingBPos[1]]);
	this->playerBPieces.push_back(this->pieces[5][6]);
	this->playerBPieces.push_back(this->pieces[6][6]);
	this->playerBPieces.push_back(this->pieces[7][6]);
				
	this->playerBPieces.push_back(this->pieces[0][7]);
	this->playerBPieces.push_back(this->pieces[1][7]);
	this->playerBPieces.push_back(this->pieces[2][7]);
	this->playerBPieces.push_back(this->pieces[3][7]);
	this->playerBPieces.push_back(this->pieces[4][7]);
	this->playerBPieces.push_back(this->pieces[5][7]);
	this->playerBPieces.push_back(this->pieces[6][7]);
	this->playerBPieces.push_back(this->pieces[7][7]);
}

void ChessBoard::print() const noexcept {
	std::cout << "These pieces in the board are\n";
	for (int j = 0; j < BOARD_Y_SIZE; j++) {
	std::cout << "-------------------------------------------------\n";
		for (int i = 0; i < BOARD_X_SIZE; i++) {
			std::cout << "|";
			if (this->pieces[i][j] == nullptr) {
				std::cout << "     ";
			}
			else {
				std::cout << " " << this->pieces[i][j]->to_string_by_player() << " ";
			}
		}
		std::cout << "|\n";
	}
	std::cout << "-------------------------------------------------\n";

	std::cout << "King A position is: [" << this->kingAPos[0] << ", " << this->kingAPos[1] << "]\n";
	std::cout << "King B position is: [" << this->kingBPos[0] << ", " << this->kingBPos[1] << "]\n";
}

bool ChessBoard::movePlayerAPiece(int initialX, int initialY, int finalX, int finalY) {
	bool result = this->movePlayerPiece(initialX, initialY, finalX, finalY);

	if (this->isPlayerAInCheck()) {
		std::cout << "############### Player A is in check!\n";
	}

	if (result && this->pieces[finalX][finalY]->is_king()) {
		this->kingAPos[0] = finalX;
		this->kingAPos[1] = finalY;
	}

	return result;
}

bool ChessBoard::movePlayerBPiece(int initialX, int initialY, int finalX, int finalY) {
	bool result = this->movePlayerPiece(initialX, initialY, finalX, finalY);

	if (this->isPlayerBInCheck()) {
		std::cout << "############### Player B is in check!\n";
	}

	if (result && this->pieces[finalX][finalY]->is_king()) {
		this->kingBPos[0] = finalX;
		this->kingBPos[1] = finalY;
	}

	return result;
}

/* Private Methods */

bool ChessBoard::movePlayerPiece(int initialX, int initialY, int finalX, int finalY) {

	if (!this->pieces[initialX][initialY]->is_valid_movement(initialX, initialY, finalX, finalY, this->pieces[finalX][finalY] != nullptr)) {
		std::cout << "############ This piece cannot be moved to this new position\n";
		return false;
	}

	this->pieces[finalX][finalY] = this->pieces[initialX][initialY];
	this->pieces[initialX][initialY] = nullptr;

	return true;
}

bool ChessBoard::isPlayerAInCheck() {
	bool result = false;

	for (auto const& playerBPiece : this->playerBPieces) {
		result = playerBPiece->can_capture_piece_at(this->kingAPos[0], this->kingBPos[1]);

		if (result) break;
	}

	return result;
}

bool ChessBoard::isPlayerBInCheck() {
	bool result = false;

	for (auto const& playerAPiece : this->playerAPieces) {
		result = playerAPiece->can_capture_piece_at(this->kingAPos[0], this->kingBPos[1]);

		if (result) break;
	}

	return result;
}

std::vector<std::tuple<int, int>> ChessBoard::getPossibleMovements(int posX, int posY) {
	std::vector<std::tuple<int, int>> result;

	for (int j = 0; j < BOARD_Y_SIZE; j++) {
		for (int i = 0; i < BOARD_X_SIZE; i++) {
			bool isPositionTaken = this->pieces[i][j] != nullptr;

			if (isPositionTaken && this->pieces[posX][posY]->get_owner() == this->pieces[i][j]->get_owner()) continue;

			if (!this->pieces[posX][posY]->is_valid_movement(posX, posY, i, j, isPositionTaken)) continue;

			if (this->pieces[posX][posY]->is_pawn() &&
				!ChessBoard::is_forward_movement(this->pieces[posX][posY], posX, posY, i, j)) continue;

			if (ChessBoard::existsPieceInTheMiddle(posX, posY, i, j)) continue;
			
			result.push_back(std::tuple<int, int>(i, j));
		}
	}

	return result;
}

bool ChessBoard::existsPieceInTheMiddle(int initialX, int initialY, int finalX, int finalY) {
	bool result = false;

	if (initialX == finalX) {
		for (int j = initialY + 1; j < finalY; j++) {
			result = this->pieces[initialX][j] != nullptr;

			if (result) break;
		}
	}
	else if (initialY == finalY) {
		for (int i = initialX +1 ; i < finalX; i++) {
			result = this->pieces[i][initialX] != nullptr;

			if (result) break;
		}
	}
	else if (abs(finalX - initialX) == abs(finalY - initialY)) {
		int diagonalDiff = abs(finalX - initialX);
		for (int i = 1; i < diagonalDiff; i++) {
			result = this->pieces[initialX + i * (finalX > initialX ? 1 : -1)][initialY + i * (finalY > initialY ? 1 : -1)] != nullptr;

			if (result) break;
		}
	}

	return result;
}

bool ChessBoard::is_forward_movement(std::shared_ptr<ChessPiece>& piece, int& initialX, int& initialY, int& finalX, int& finalY) {
	return (piece->get_owner()->has_bottom_to_top_pieces_direction() && finalY < initialY) ||
		(!piece->get_owner()->has_bottom_to_top_pieces_direction() && finalY > initialY);
}