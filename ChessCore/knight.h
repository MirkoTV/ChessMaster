#pragma once

#include "chesspiece.h"

class Knight: public ChessPiece {
public:
	Knight(const ChessPlayer& owner);
	void print() const noexcept override;
	std::string to_string() override;
	bool can_capture_piece_at(int posX, int posY) override;
};