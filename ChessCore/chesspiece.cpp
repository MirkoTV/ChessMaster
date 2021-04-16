#include <iostream>

#include "chesspiece.h"

ChessPiece::ChessPiece(const ChessPlayer& owner)
	:owner{ &owner } {}

void ChessPiece::print() const noexcept {
	std::cout << "I am a piece\n";
}

std::string ChessPiece::to_string_by_player() {
	return this->to_string() + this->owner->getNameTag();
}

std::string ChessPiece::to_string() {
	return "PI";
}

bool ChessPiece::is_king() const noexcept {
	return false;
}