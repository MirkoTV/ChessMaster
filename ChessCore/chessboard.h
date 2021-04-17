#pragma once

#include <list>
#include <vector>
#include <tuple>

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
	bool is_forward_movement(std::shared_ptr<ChessPiece>& piece, int& initialX, int& initialY, int& finalX, int& finalY);
	bool is_valid_movement(int initialX, int initialY, int finalX, int finalY);
	bool existsPieceInTheMiddle(int initialX, int initialY, int finalX, int finalY);

public:
	ChessBoard();
	ChessBoard(const ChessPlayer& playerA, const ChessPlayer& playerB);
	void print() const noexcept;
	bool movePlayerAPiece(int initialX, int initialY, int finalX, int finalY);
	bool movePlayerBPiece(int initialX, int initialY, int finalX, int finalY);
	std::vector<std::tuple<int, int>> getPossibleMovements(int posX, int posY);
};