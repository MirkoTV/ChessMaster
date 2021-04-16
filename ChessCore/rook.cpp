#include <iostream>

#include "rook.h"

Rook::Rook(const ChessPlayer& owner)
	:ChessPiece(owner) {}

void Rook::print() const noexcept {
	std::cout << "I am a rook\n";
}

std::string Rook::to_string() {
	return "RO";
}

bool Rook::can_capture_piece_at(int posX, int posY) {
	return false;
}

bool Rook::is_valid_movement(int initialPosX, int initialPosY, int finalPosX, int finalPosY) {
	return true;
}