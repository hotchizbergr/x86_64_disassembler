#include "Util.h"
#include <iostream>
#include <iomanip>

void Util::Print(int leadingZeros, int value, bool lf)
{
	std::cout << std::uppercase << std::hex << std::setfill('0') <<
		std::setw(leadingZeros) << static_cast<unsigned>(value);
	if (lf) std::cout << '\n';
}