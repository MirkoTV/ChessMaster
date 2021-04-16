#pragma once

#include "chesspiece.h"

class King: public ChessPiece {
public:
	King(const ChessPlayer& owner);
	void print() const noexcept override;
	std::string to_string() override;
	bool is_king() const noexcept override;
};