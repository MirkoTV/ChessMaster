#include <iostream>

#include "knight.h"

Knight::Knight(const ChessPlayer& owner)
	:ChessPiece(owner) {}

void Knight::print() const noexcept {
	std::cout << "I am a knight\n";
}

std::string Knight::to_string() {
	return "KN";
}

bool Knight::is_knight() const noexcept {
	return true;
}

bool Knight::can_capture_piece_at(int posX, int posY) {
	return false;
}

bool Knight::is_valid_movement(int initialPosX, int initialPosY, int finalPosX, int finalPosY, bool isFinalPosTaken) {
	return (abs(finalPosY - initialPosY) == 2 && abs(finalPosX - initialPosX) == 1) ||
		(abs(finalPosX - initialPosX) == 2 && abs(finalPosY - initialPosY) == 1);
}