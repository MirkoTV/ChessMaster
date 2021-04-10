#include <iostream>

#include "chessgame.h"

ChessGame::ChessGame()
	: playerA { ChessPlayer { "Player A" } }, playerB{ ChessPlayer { "Player B" } }  {
	this->playerA.print();
	this->playerB.print();

	this->board.print();
}

void ChessGame::print() const noexcept {
	std::cout << "I am a new game!\n";
}