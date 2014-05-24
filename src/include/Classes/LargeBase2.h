#include <cstdint>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>

#define _LARGEBASE2_

class LargeBase2
{
	public:
		LargeBase2();
		template<typename exp> LargeBase2(exp);
		~LargeBase2();
		
		std::string GetNum () { return num; }
		uint16_t Get1stDigitIndex() { return first_digit_index; }
		
		void SetNum (std::string str) { num = str; }
		
		void Print();
		
		uint64_t SumDigits ();
		
		LargeBase2 Add(LargeBase2);
		
	private:
		std::string num;
		uint16_t first_digit_index;
};

LargeBase2::LargeBase2() { num = ""; }

template<typename exp>
LargeBase2::LargeBase2(exp n)
{
	double dub = pow(2,n);
	char* buf = new char[512];
	
	std:sprintf(buf, "%f", dub);
	
	num = buf;
	
	delete[] buf;

	//num = std::to_string(dub);
	
	uint16_t i = 0;
	while (num[i] != '.')
		i++;
	
	first_digit_index = i-1;
}

LargeBase2::~LargeBase2() {}

void LargeBase2::Print()
{
	std::cout << "\n" << num << "\n";
}

uint64_t LargeBase2::SumDigits ()
{
	uint64_t sum = 0;
	
	uint16_t i = 0;
	while (num[i] != '.')
	{
		sum += num[i] - 48;
		i++;
	}
	
	return sum;
}

LargeBase2 LargeBase2::Add(LargeBase2 other)
{
	std::string sum = ".";
	LargeBase2 result;
	uint16_t this_num_index = first_digit_index, other_num_index = other.Get1stDigitIndex();
	uint8_t sum_num = 0, carry = 0, unit = 0;
	
	while (this_num_index != 0 || other_num_index != 0)
	{
		sum_num = carry;
		
		if (this_num_index > 0)
		{
			this_num_index--;
			
			sum_num += num[this_num_index] - 48;
		}
		
		if (other_num_index > 0)
		{
			other_num_index--;
			
			sum_num += other.GetNum()[other_num_index] - 48;
		}
		
		if (sum_num > 9)
			carry = 1;
		else
			carry = 0;
			
		unit = sum_num%10;
		
		//sum.insert(0, std::to_string(unit+48));
	}
	
	result.SetNum(sum);
	
	return result;
}
