#pragma once

#include "chessplayer.h"

class ChessPiece {
	const ChessPlayer* owner;
public:
	ChessPiece(const ChessPlayer& owner);
	virtual void print() const noexcept;
	virtual std::string to_string_by_player();
	virtual std::string to_string();
};