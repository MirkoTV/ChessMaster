#pragma once

#include "chesspiece.h"

class Queen: public ChessPiece {
public:
	Queen(const ChessPlayer& owner);
	void print() const noexcept override;
};