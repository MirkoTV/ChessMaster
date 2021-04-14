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
	std::cout << "I am a new game!\n";

	this->playerA.print();
	this->playerB.print();

	this->board.print();
}