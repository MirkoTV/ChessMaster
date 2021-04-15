#pragma once

#include <string>

class ChessPlayer {
	std::string name;
public:
	ChessPlayer(const std::string& name);
	void print() const noexcept;
	std::string getNameTag() const noexcept;
};