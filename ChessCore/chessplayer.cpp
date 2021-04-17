#include <iostream>
#include <string>

#include "chessplayer.h"

ChessPlayer::ChessPlayer(const std::string& name)
	: ChessPlayer::ChessPlayer(name, false) {}

ChessPlayer::ChessPlayer(const std::string& name, const bool& bottom_to_top_pieces_direction)
	: name{ name }, bottom_to_top_pieces_direction{ bottom_to_top_pieces_direction } {}

void ChessPlayer::print() const noexcept {
	std::cout << "I am a the player!" << this->name << "\n";
}

std::string ChessPlayer::getNameTag() const noexcept {
	return this->name.substr(0, 1);
}

bool ChessPlayer::has_bottom_to_top_pieces_direction() const noexcept {
	return this->bottom_to_top_pieces_direction;
}