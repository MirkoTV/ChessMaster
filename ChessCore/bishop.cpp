#include <iostream>

#include "bishop.h"

Bishop::Bishop(const ChessPlayer& owner)
	:ChessPiece(owner) {}

void Bishop::print() const noexcept  {
	std::cout << "I am a bishop\n";
}