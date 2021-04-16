#pragma once

#include "chessplayer.h"

class ChessPiece {
	const ChessPlayer* owner;
public:
	ChessPiece(const ChessPlayer& owner);
	virtual void print() const noexcept;
	virtual std::string to_string_by_player();
	virtual std::string to_string();
	virtual bool is_king() const noexcept;
	virtual bool can_capture_piece_at(int posX, int posY) = 0;
};