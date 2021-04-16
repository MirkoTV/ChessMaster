#include <iostream>

#include "king.h"

King::King(const ChessPlayer& owner)
	:ChessPiece(owner) {}

void King::print() const noexcept {
	std::cout << "I am a king\n";
}

std::string King::to_string() {
	return "KI";
}

bool King::is_king() const noexcept {
	return true;
}