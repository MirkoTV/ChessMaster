#include "invalidmovementexception.h"

const char* InvalidMovementException::what() const throw() {
    return "You cannot move this piece to that position";
}