#include <iostream>

#include "chesspiece.h"

ChessPiece::ChessPiece(const ChessPlayer& owner)
	:owner{ &owner } {}

void ChessPiece::print() const noexcept {
	std::cout << "I am a piece\n";
}