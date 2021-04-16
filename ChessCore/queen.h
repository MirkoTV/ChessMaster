#pragma once

#include "chesspiece.h"

class Queen: public ChessPiece {
public:
	Queen(const ChessPlayer& owner);
	void print() const noexcept override;
	std::string to_string() override;
	bool can_capture_piece_at(int posX, int posY) override;
	bool is_valid_movement(int initialPosX, int initialPosY, int finalPosX, int finalPosY) override;
};