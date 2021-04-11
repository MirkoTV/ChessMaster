#pragma once

#include "dll.h"
#include "chesspiece.h"

#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"

constexpr size_t NUMBER_OF_PLAYER_PIECES { 16 };

class ChessBoard {
	std::unique_ptr<ChessPiece> playerAPieces[NUMBER_OF_PLAYER_PIECES] = {
		std::make_unique<King>(),
		std::make_unique<Queen>(),
		std::make_unique<Bishop>(),
		std::make_unique<Bishop>(),
		std::make_unique<Knight>(),
		std::make_unique<Knight>(),
		std::make_unique<Rook>(),
		std::make_unique<Rook>(),
		std::make_unique<Pawn>(),
		std::make_unique<Pawn>(),
		std::make_unique<Pawn>(),
		std::make_unique<Pawn>(),
		std::make_unique<Pawn>(),
		std::make_unique<Pawn>(),
		std::make_unique<Pawn>(),
		std::make_unique<Pawn>()
	};
	std::unique_ptr<ChessPiece> playerBPieces[NUMBER_OF_PLAYER_PIECES] = {
		std::make_unique<King>(),
		std::make_unique<Queen>(),
		std::make_unique<Bishop>(),
		std::make_unique<Bishop>(),
		std::make_unique<Knight>(),
		std::make_unique<Knight>(),
		std::make_unique<Rook>(),
		std::make_unique<Rook>(),
		std::make_unique<Pawn>(),
		std::make_unique<Pawn>(),
		std::make_unique<Pawn>(),
		std::make_unique<Pawn>(),
		std::make_unique<Pawn>(),
		std::make_unique<Pawn>(),
		std::make_unique<Pawn>(),
		std::make_unique<Pawn>()
	};

public:
	ChessBoard();
	void print() const noexcept;
};