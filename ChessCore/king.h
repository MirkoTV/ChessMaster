#pragma once

#include "chesspiece.h"

class King: public ChessPiece {
public:
	King(const ChessPlayer& owner);
	void print() const noexcept override;
};