#include "nopieceownershipexception.h"

const char* NoPieceOwnershipException::what() const throw() {
    return "You are not the owner of this piece.";
}