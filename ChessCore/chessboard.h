#pragma once

#include "dll.h"
#include "chesspiece.h"

class CHESSCORE_EXPORT ChessBoard{
	ChessPiece piece;
public:
	ChessBoard();
	void print() const noexcept;
};