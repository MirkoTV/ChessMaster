#include <iostream>

#include "king.h"

King::King(const ChessPlayer& owner)
	:ChessPiece(owner) {}

void King::print() const noexcept {
	std::cout << "I am a king\n";
}