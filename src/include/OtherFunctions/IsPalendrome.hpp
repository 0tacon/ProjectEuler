#include <iostream>
#include <cstdint>
#include <vector>

bool IsPalendrome ( uint64_t num )
{
	uint8_t digits;
	uint64_t temp = num;
	std::vector<uint8_t> vect;
	
	if ( num<10000000 && num>999999 ) digits = 7;
	else if ( num<1000000 && num>99999 ) digits = 6;
	else if ( num<100000 && num>9999 ) digits = 5;
	else if ( num<10000 && num>999 ) digits = 4;
	else if ( num<1000 && num>99 ) digits = 3;
	else if ( num<100 && num>9 ) digits = 2;
	else if ( num<10 && num>0 ) digits = 1;
	else if ( num==0 ) digits = 0;
	else
	{
		std::cout << "\nError: Number is too large, only 7 digit (or less) numbers can be used";
		return false;
	}
	
	for ( uint8_t i = 0 ; i < digits ; i++ )
	{
		vect.push_back(temp%10);
		temp = (temp-temp%10)/10;
	}
	
	if ( std::equal( vect.begin(), vect.begin() + vect.size()/2, vect.rbegin() ) ) return true;
	
	return false;
}
