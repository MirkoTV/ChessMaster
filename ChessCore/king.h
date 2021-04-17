#pragma once

#include "chesspiece.h"

class King: public ChessPiece {
public:
	King(const ChessPlayer& owner);
	void print() const noexcept override;
	std::string to_string() override;
	bool is_king() const noexcept override;
	bool can_capture_piece_at(int posX, int posY) override;
	bool is_valid_movement(int initialPosX, int initialPosY, int finalPosX, int finalPosY, bool isFinalPosTaken) override;
};