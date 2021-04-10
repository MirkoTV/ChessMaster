#include <iostream>

#include "chessgame.h"

ChessGame::ChessGame() {
	this->board.print();
}

void ChessGame::print() const noexcept {
	std::cout << "I am a new game!\n";
}