#include <cstdint>
#include <map>

template<typename T>
uint8_t GetLettersInNum (T n)
{
	uint8_t letters;
	std::map<uint8_t, uint8_t> unit, ten, teen;		// Param1: Number, Param2: Corresponding letter count
	
	unit[1] = 3;
	unit[2] = 3;
	unit[3] = 5;
	unit[4] = 4;
	unit[5] = 4;
	unit[6] = 3;
	unit[7] = 5;
	unit[8] = 5;
	unit[9] = 4;
	
	ten[2] = 6;
	ten[3] = 6;
	ten[4] = 5;
	ten[5] = 5;
	ten[6] = 5;
	ten[7] = 7;
	ten[8] = 7;
	ten[9] = 6;
	
	teen[11] = 6;
	teen[12] = 6;
	teen[13] = 8;
	teen[14] = 8;
	teen[15] = 7;
	teen[16] = 7;
	teen[17] = 9;
	teen[18] = 8;
	teen[19] = 8;
	
	return letters;
}
