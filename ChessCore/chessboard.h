#pragma once

#include <list>

#include "dll.h"
#include "chesspiece.h"

#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"

class ChessBoard {
	std::shared_ptr<ChessPiece> pieces[8][8];

	std::list<std::shared_ptr<ChessPiece>> playerAPieces;
	std::list<std::shared_ptr<ChessPiece>> playerBPieces;

	int kingAPos[2] = { 4, 0 };

	int kingBPos[2] = { 4, 7 };

	bool movePlayerPiece(int initialX, int initialY, int finalX, int finalY);

	bool isPlayerAInCheck();
	bool isPlayerBInCheck();
public:
	ChessBoard();
	ChessBoard(const ChessPlayer& playerA, const ChessPlayer& playerB);
	void print() const noexcept;
	bool movePlayerAPiece(int initialX, int initialY, int finalX, int finalY);
	bool movePlayerBPiece(int initialX, int initialY, int finalX, int finalY);
};