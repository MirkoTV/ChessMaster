#pragma once

#ifdef CHESSCORE_EXPORTS
#define CHESSCORE_EXPORT __declspec(dllexport)
#else 
#define CHESSCORE_EXPORT __declspec(dllimport)
#endif