#pragma once

#include <string>
#include <random>
#include <ncurses.h>

int randIntRange(int min, int max);
const cchar_t wchar2cchar(const wchar_t& c);
std::wstring char2str(const wchar_t& c);
