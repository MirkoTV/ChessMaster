#include <iostream>

#include "chessgame.h"

ChessGame::ChessGame()
	: ChessGame::ChessGame("Player A", "Player B") {
}

ChessGame::ChessGame(const std::string& playerAName, const std::string& playerBName) 
	: playerA{ ChessPlayer{ playerAName } }, playerB{ ChessPlayer{ playerBName } } {

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