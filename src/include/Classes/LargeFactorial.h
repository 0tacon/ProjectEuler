#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#ifndef _LARGEBASE2_
	#include "LargeBase2.h"
#endif

#define _LARGEFACTORIAL_

class LargeFactorial
{
	public:
		LargeFactorial();
		template<typename T> LargeFactorial(T);
		~LargeFactorial();
		
		LargeBase2 GetFactorial() { return factorial; }
		
		void CalcFactors();
		
		void CalcFactorial();
		
		void RecursiveDecomposition (double);
		
		LargeBase2 CreateLargeBase2 (uint16_t n);
	
	private:
		uint64_t number;
		std::vector<LargeBase2> factors;
		std::vector<uint16_t> factor_exps;
		LargeBase2 factorial;
};

LargeFactorial::LargeFactorial()
{
	number = 0;
	
	factorial.SetNum("0.000000");
	
	factors.push_back(factorial);
	factor_exps.push_back(0);
}

template<typename T>
LargeFactorial::LargeFactorial(T n)
{
	number = n;
	factorial.SetNum("0.000000");
	
	this->CalcFactors();
	
	this->CalcFactorial();
}

LargeFactorial::~LargeFactorial() {}

void LargeFactorial::CalcFactors()
{
	std::vector<double> nums;
	double exp = 0, rem = 1;
	
	for (double i = 2; i <= number; i++)
		nums.push_back(i);
		
	for (double i = 0; i < nums.size(); i++)
	{
		while (fmod(static_cast<double>(nums.at(i)), static_cast<double>(2.0)) == 0.0)
		{
			nums.at(i) = nums.at(i) / 2;
			exp++;
		}
	}
	
	for (std::vector<double>::iterator i = nums.begin(); i != nums.end(); i++)
		rem *= *i;
		
	std::cout << "\nexp = " << exp << "\n";
	std::cout << "\nrem = " << rem << "\n";
	
	RecursiveDecomposition(rem);
	
	factor_exps.push_back(0);
	
	for (uint16_t e = 0; e != factor_exps.size(); e++)
		factor_exps.at(e) += exp;	
	
	for (std::vector<uint16_t>::iterator e = factor_exps.begin(); e != factor_exps.end(); e++)
		factors.push_back(CreateLargeBase2(*e));
		
	/*for (std::vector<LargeBase2>::iterator n = factors.begin(); n != factors.end(); n++)
		n->Print();*/
}

void LargeFactorial::RecursiveDecomposition (double input)
{
	double exp = 0, rem;
	
	while (pow(2, exp) < input)
		exp++;
		
	exp--;
	
	rem = input - pow(2,exp);
	
	factor_exps.push_back(exp);
	
	if (rem != 1)
		RecursiveDecomposition(rem);
}

LargeBase2 LargeFactorial::CreateLargeBase2 (uint16_t n)
{
	LargeBase2 num(n);
	return num;
}

void LargeFactorial::CalcFactorial ()
{
	for (std::vector<LargeBase2>::iterator n = factors.begin(); n != factors.end(); n++)
		factorial = factorial + *n;
		
	//factorial.Print();
}
