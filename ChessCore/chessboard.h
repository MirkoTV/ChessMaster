#pragma once

#include <list>
#include <vector>
#include <tuple>

#include "dll.h"
#include "chesspiece.h"
#include "chessplayer.h"

#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"

class ChessBoard {
	std::shared_ptr<ChessPiece> pieces[8][8];

	const ChessPlayer* playerA;
	const ChessPlayer* playerB;

	std::list<std::shared_ptr<ChessPiece>> playerAPieces;
	std::list<std::shared_ptr<ChessPiece>> playerBPieces;

	std::vector <std::tuple<const ChessPlayer*, int, int, int, int>> movements;

	int kingAPos[2] = { 4, 0 };

	int kingBPos[2] = { 4, 7 };

	bool movePlayerPiece(int initialX, int initialY, int finalX, int finalY, const ChessPlayer* player);

	bool is_forward_movement(std::shared_ptr<ChessPiece>& piece, int& initialX, int& initialY, int& finalX, int& finalY) const;
	bool is_valid_movement(int initialX, int initialY, int finalX, int finalY) const;
	bool existsPieceInTheMiddle(int initialX, int initialY, int finalX, int finalY) const;
	std::vector<std::tuple<int, int>> getPossibleMovements(int posX, int posY, const ChessPlayer* player) const;

public:
	ChessBoard();
	ChessBoard(const ChessPlayer& playerA, const ChessPlayer& playerB);
	bool is_player_a_in_check();
	bool is_player_b_in_check();
	bool movePlayerAPiece(int initialX, int initialY, int finalX, int finalY);
	bool movePlayerBPiece(int initialX, int initialY, int finalX, int finalY);
	std::vector<std::tuple<int, int>> getPossibleMovementsForPlayerA(int posX, int posY);
	std::vector<std::tuple<int, int>> getPossibleMovementsForPlayerB(int posX, int posY);
	int get_board_x_size() const noexcept;
	int get_board_y_size() const noexcept;
	const std::shared_ptr<ChessPiece> get_piece_at(int i, int j) const noexcept;
	bool has_player_a_possible_movements() noexcept;
	bool has_player_b_possible_movements() noexcept;
};