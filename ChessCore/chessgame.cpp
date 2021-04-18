#include <iostream>

#include "chessgame.h"

ChessGame::ChessGame()
	: ChessGame::ChessGame("A", "B") {
}

ChessGame::ChessGame(const std::string& playerAName, const std::string& playerBName) 
	: playerA{ ChessPlayer{ playerAName } }, playerB{ ChessPlayer{ playerBName, true } } {

	this->board = ChessBoard{ this->playerA, this->playerB };
}

void ChessGame::print() const noexcept {
	this->board.print();
}

bool ChessGame::movePlayerAPiece(int initialX, int initialY, int finalX, int finalY) {
	return this->board.movePlayerAPiece(initialX, initialY, finalX, finalY);
}

bool ChessGame::movePlayerBPiece(int initialX, int initialY, int finalX, int finalY) {
	return this->board.movePlayerBPiece(initialX, initialY, finalX, finalY);
}

std::vector<std::tuple<int, int>> ChessGame::getPossibleMovementsForPlayerA(int posX, int posY) {
	return this->board.getPossibleMovementsForPlayerA(posX, posY);
}

std::vector<std::tuple<int, int>> ChessGame::getPossibleMovementsForPlayerB(int posX, int posY) {
	return this->board.getPossibleMovementsForPlayerB(posX, posY);
}

bool ChessGame::is_player_a_in_check() {
	return this->board.is_player_a_in_check();
}

bool ChessGame::is_player_b_in_check() {
	return this->board.is_player_b_in_check();
}