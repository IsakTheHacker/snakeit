#pragma once

#include <string>
#include <random>
#include "deps.h"

#include "globals.h"

#define SAFE_ATTRON(pair) if (Globals::supportsColor) attron(pair)
#define SAFE_ATTROFF(pair) if (Globals::supportsColor) attroff(pair)

int randIntRange(int min, int max);
const cchar_t wchar2cchar(const wchar_t& c);
std::wstring char2str(const wchar_t& c);
