#pragma once

#include "dll.h"
#include "chessboard.h"

class CHESSCORE_EXPORT ChessGame{
	ChessBoard board;
public:
	ChessGame();
	void print() const noexcept;
};