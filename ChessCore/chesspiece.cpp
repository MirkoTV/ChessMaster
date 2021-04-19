#include <iostream>

#include "chesspiece.h"

ChessPiece::ChessPiece(const ChessPlayer& owner)
	:owner{ &owner } {}

const ChessPlayer* ChessPiece::get_owner() {
	return this->owner;
}

void ChessPiece::print() const noexcept {
	std::cout << "I am a piece\n";
}

bool ChessPiece::get_is_moved() const noexcept {
	return this->is_moved;
}

void ChessPiece::mark_as_moved() noexcept {
	this->is_moved = true;
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

bool ChessPiece::can_move_forward_only() const noexcept {
	return false;
}

bool ChessPiece::can_jump() const noexcept {
	return false;
}