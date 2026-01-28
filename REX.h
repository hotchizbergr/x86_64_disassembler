#pragma once

#include <Windows.h>

class REX
{
public:
	REX();
	REX& operator=(const BYTE& rex);
	//REX& operator=(const REX& rhs);

	bool GetW() const;
	bool GetR() const;
	bool GetX() const;
	bool GetB() const;

private:
	bool w;
	bool r;
	bool x;
	bool b;
};

inline bool REX::GetW() const
{
	return w;
}

inline bool REX::GetR() const
{
	return r;
}

inline bool REX::GetX() const
{
	return x;
}

inline bool REX::GetB() const
{
	return b;
}