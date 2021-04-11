#include <iostream>

#include "chessboard.h"

ChessBoard::ChessBoard() {
}

void ChessBoard::print() const noexcept {
	std::cout << "I am a board\n";

	std::cout << "These are the player A pieces\n";
	for (int i = 0; i < NUMBER_OF_PLAYER_PIECES; i++) {
		this->playerAPieces[i]->print();
	}

	std::cout << "These are the player B pieces\n";
	for (int i = 0; i < NUMBER_OF_PLAYER_PIECES; i++) {
		this->playerAPieces[i]->print();
	}
}