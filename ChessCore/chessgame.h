#pragma once

#include "dll.h"
#include "chessplayer.h"
#include "chessboard.h"

class CHESSCORE_EXPORT ChessGame{
	ChessPlayer playerA;
	ChessPlayer playerB;

	ChessBoard board;
public:
	ChessGame();
	void print() const noexcept;
};