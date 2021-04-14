#pragma once

#include "chesspiece.h"

class Pawn: public ChessPiece {
public:
	Pawn(const ChessPlayer& owner);
	void print() const noexcept override;
};