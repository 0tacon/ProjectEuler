#include <cstdint>
#include <cmath>

bool IsDivisible (uint64_t a, uint64_t b)
{
	if (a <= b) return false;
	else if (fmod(static_cast<double>(a), static_cast<double>(b)) == 0.0 ) return true;
	else return false;
}

bool IsNotDivisible (uint64_t a, uint64_t b)
{
	bool n = !(IsDivisible (a,b));
	return n;
}
