#pragma once

#include "chesspiece.h"

class Pawn: public ChessPiece {
public:
	Pawn(const ChessPlayer& owner);
	void print() const noexcept override;
	std::string to_string() override;
	bool can_capture_piece_at(int posX, int posY) override;
	bool is_valid_movement(int initialPosX, int initialPosY, int finalPosX, int finalPosY, bool isFinalPosTaken) override;
	bool can_move_forward_only() const noexcept override;
};