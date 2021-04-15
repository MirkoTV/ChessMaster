#include <iostream>
#include <string>

#include "chessplayer.h"

ChessPlayer::ChessPlayer(const std::string& name)
	: name{name} {}

void ChessPlayer::print() const noexcept {
	std::cout << "I am a the player!" << this->name << "\n";
}

std::string ChessPlayer::getNameTag() const noexcept {
	return this->name.substr(0, 1);
}