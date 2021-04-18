#pragma once

#include "chessplayer.h"

class ChessPiece {
	const ChessPlayer* owner;
	bool is_moved = false;
public:
	ChessPiece(const ChessPlayer& owner);
	const ChessPlayer* get_owner();
	void mark_as_moved() noexcept;
	bool get_is_moved() const noexcept;
	virtual void print() const noexcept;
	virtual std::string to_string_by_player();
	virtual std::string to_string();
	virtual bool is_king() const noexcept;
	virtual bool is_knight() const noexcept;
	virtual bool is_pawn() const noexcept;
	virtual bool can_capture_piece_at(int posX, int posY) = 0;
	virtual bool is_valid_movement(int initialPosX, int initialPosY, int finalPosX, int finalPosY, bool isFinalPosTaken) = 0;
};