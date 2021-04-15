#include <iostream>

#include "queen.h"

Queen::Queen(const ChessPlayer& owner)
	:ChessPiece(owner) {}

void Queen::print() const noexcept {
	std::cout << "I am a queen\n";
}

std::string Queen::to_string() {
	return " QU ";
}