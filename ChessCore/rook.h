#pragma once

#include "chesspiece.h"

class Rook: public ChessPiece {
public:
	Rook(const ChessPlayer& owner);
	void print() const noexcept override;
};