#pragma once

#include "dll.h"
#include "chesspiece.h"

class ChessBoard {
	ChessPiece piece;
public:
	ChessBoard();
	void print() const noexcept;
};