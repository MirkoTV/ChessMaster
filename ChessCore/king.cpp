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

bool King::can_capture_piece_at(int posX, int posY) {
	return false;
}

bool King::is_valid_movement(int initialPosX, int initialPosY, int finalPosX, int finalPosY, bool isFinalPosTaken) {
	return abs(finalPosX - initialPosX) <=1 && abs(finalPosY - initialPosX) <= 1;
}