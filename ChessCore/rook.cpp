#include <iostream>

#include "rook.h"

Rook::Rook(const ChessPlayer& owner)
	:ChessPiece(owner) {}

void Rook::print() const noexcept {
	std::cout << "I am a rook\n";
}