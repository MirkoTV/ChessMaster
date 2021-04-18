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
	bool movePlayerAPiece(int initialX, int initialY, int finalX, int finalY);
	bool movePlayerBPiece(int initialX, int initialY, int finalX, int finalY);
	std::vector<std::tuple<int, int>> getPossibleMovementsForPlayerA(int posX, int posY);
	std::vector<std::tuple<int, int>> getPossibleMovementsForPlayerB(int posX, int posY);
	bool is_player_a_in_check();
	bool is_player_b_in_check();
	int get_board_x_size() const noexcept;
	int get_board_y_size() const noexcept;
	const std::shared_ptr<ChessPiece> get_piece_at(int i, int j) const noexcept;
	bool has_player_a_possible_movements() const noexcept;
	bool has_player_b_possible_movements() const noexcept;
};