#include <iostream>

#include "bishop.h"

Bishop::Bishop(const ChessPlayer& owner)
	:ChessPiece(owner) {}

void Bishop::print() const noexcept  {
	std::cout << "I am a bishop\n";
}

std::string Bishop::to_string() {
	return "BI";
}

bool Bishop::can_capture_piece_at(int posX, int posY) {
	return false;
}

bool Bishop::is_valid_movement(int initialPosX, int initialPosY, int finalPosX, int finalPosY, bool isFinalPosTaken) {
	return abs(finalPosX - initialPosX) == abs(finalPosY - initialPosY);
}