#pragma once

#include "dll.h"
#include "chesspiece.h"

#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"

class ChessBoard {
	std::unique_ptr<ChessPiece> pieces[8][8];

public:
	ChessBoard();
	ChessBoard(const ChessPlayer& playerA, const ChessPlayer& playerB);
	void print() const noexcept;
};