#include <iostream>

#include "pawn.h"

Pawn::Pawn(const ChessPlayer& owner)
	:ChessPiece(owner) {}

void Pawn::print() const noexcept {
	std::cout << "I am a pawn\n";
}

std::string Pawn::to_string() {
	return " PA ";
}