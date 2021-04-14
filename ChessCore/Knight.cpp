#include <iostream>

#include "knight.h"

Knight::Knight(const ChessPlayer& owner)
	:ChessPiece(owner) {}

void Knight::print() const noexcept {
	std::cout << "I am a knight\n";
}