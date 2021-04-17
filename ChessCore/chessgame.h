#pragma once
#include <vector>
#include <tuple>

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
	bool movePlayerAPiece(int initialX, int initialY, int finalX, int finalY);
	bool movePlayerBPiece(int initialX, int initialY, int finalX, int finalY);
	std::vector<std::tuple<int, int>> getPossibleMovements(int posX, int posY);
};