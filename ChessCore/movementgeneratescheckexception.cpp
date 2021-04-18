#include "movementgeneratescheckexception.h"

const char* MovementGeneratesCheckException::what() const throw() {
    return "You cannot perform this movement since you will be checked";
}