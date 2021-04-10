#include <iostream>

#include "chessboard.h"

ChessBoard::ChessBoard() {
	this->piece.print();
}

void ChessBoard::print() const noexcept {
	std::cout << "I am a board\n";
}