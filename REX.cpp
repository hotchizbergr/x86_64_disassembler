#include "REX.h"

REX::REX()
	: w(false)
	, r(false)
	, x(false)
	, b(false)
{
}

REX& REX::operator=(const BYTE& rex)
{
	w = rex & 0x08;
	r = rex & 0x04;
	x = rex & 0x02;
	b = rex & 0x01;

	return *this;
}