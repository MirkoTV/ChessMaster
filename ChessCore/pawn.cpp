#include <iostream>

#include "pawn.h"

Pawn::Pawn(const ChessPlayer& owner)
	:ChessPiece(owner) {}

void Pawn::print() const noexcept {
	std::cout << "I am a pawn\n";
}

std::string Pawn::to_string() {
	return "PA";
}

bool Pawn::can_capture_piece_at(int posX, int posY) {
	return false;
}

bool Pawn::is_valid_movement(int initialPosX, int initialPosY, int finalPosX, int finalPosY, bool isFinalPosTaken) {
	return (finalPosX == initialPosX && abs(finalPosY - initialPosY) == 1) ||
		(!this->get_is_moved() && !isFinalPosTaken && finalPosX == initialPosX && abs(finalPosY - initialPosY) ==  2) ||
		(isFinalPosTaken && abs(finalPosX - initialPosX) == 1 && abs(finalPosY - initialPosY) == 1);
}

bool Pawn::can_move_forward_only() const noexcept {
	return true;
}