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
	ChessGame(const std::string& playerAName, const std::string& playerBName);
	void print() const noexcept;
};