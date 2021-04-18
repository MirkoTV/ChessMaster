#pragma once

#include "dll.h"

#include <iostream>
#include <exception>

struct CHESSCORE_EXPORT MovementGeneratesCheckException : public std::exception
{
    const char* what() const throw ();
};