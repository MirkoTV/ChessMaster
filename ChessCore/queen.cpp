#include <iostream>

#include "queen.h"

Queen::Queen(const ChessPlayer& owner)
	:ChessPiece(owner) {}

void Queen::print() const noexcept {
	std::cout << "I am a queen\n";
}

std::string Queen::to_string() {
	return "QU";
}

bool Queen::can_capture_piece_at(int posX, int posY) {
	return false;
}

bool Queen::is_valid_movement(int initialPosX, int initialPosY, int finalPosX, int finalPosY) {
	return true;
}