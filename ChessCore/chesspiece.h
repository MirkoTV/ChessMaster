#pragma once

#include "chessplayer.h"

class ChessPiece {
	const ChessPlayer* owner;
public:
	ChessPiece(const ChessPlayer& owner);
	virtual void print() const noexcept;
};