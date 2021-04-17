#pragma once

#include <string>

class ChessPlayer {
	std::string name;
	bool bottom_to_top_pieces_direction = false;
public:
	ChessPlayer(const std::string& name);
	ChessPlayer(const std::string& name, const bool& bottomToTopPiecesDirection);
	void print() const noexcept;
	std::string getNameTag() const noexcept;
	bool has_bottom_to_top_pieces_direction() const noexcept;
};