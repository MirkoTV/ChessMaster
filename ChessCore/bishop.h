#pragma once

#include "chesspiece.h"

class Bishop: public ChessPiece {
public:
	Bishop(const ChessPlayer& owner);
	void print() const noexcept override;
	std::string to_string() override;
};