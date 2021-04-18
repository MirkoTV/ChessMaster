#include <iostream>

#include "chessgame.h"

ChessGame::ChessGame()
	: ChessGame::ChessGame("A", "B") {
}

ChessGame::ChessGame(const std::string& playerAName, const std::string& playerBName) 
	: playerA{ ChessPlayer{ playerAName } }, playerB{ ChessPlayer{ playerBName, true } } {

	this->board = ChessBoard{ this->playerA, this->playerB };
}

bool ChessGame::movePlayerAPiece(int initialX, int initialY, int finalX, int finalY) {
	return this->board.movePlayerAPiece(initialX, initialY, finalX, finalY);
}

bool ChessGame::movePlayerBPiece(int initialX, int initialY, int finalX, int finalY) {
	return this->board.movePlayerBPiece(initialX, initialY, finalX, finalY);
}

std::vector<std::tuple<int, int>> ChessGame::getPossibleMovementsForPlayerA(int posX, int posY) {
	return this->board.getPossibleMovementsForPlayerA(posX, posY);
}

std::vector<std::tuple<int, int>> ChessGame::getPossibleMovementsForPlayerB(int posX, int posY) {
	return this->board.getPossibleMovementsForPlayerB(posX, posY);
}

bool ChessGame::is_player_a_in_check() {
	return this->board.is_player_a_in_check();
}

bool ChessGame::is_player_b_in_check() {
	return this->board.is_player_b_in_check();
}

int ChessGame::get_board_x_size() const noexcept{
	return this->board.get_board_x_size();
}

int ChessGame::get_board_y_size() const noexcept{
	return this->board.get_board_y_size();
}

const std::shared_ptr<ChessPiece> ChessGame::get_piece_at(int i, int j) const noexcept {
	return this->board.get_piece_at(i, j);
}