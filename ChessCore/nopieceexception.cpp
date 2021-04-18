#include "nopieceexception.h"

const char* NoPieceException::what() const throw() {
    return "No piece found at that position";
}