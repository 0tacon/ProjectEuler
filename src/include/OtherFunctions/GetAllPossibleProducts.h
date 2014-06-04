#include <cstdint>
#include <vector>

#define _GETALLPOSSIBLEPRODUCTS_

template<typename T>
void GetAllPossibleProducts(T &n, std::vector<T> &vect, std::vector<T> &products)
{
	std::vector<T> temp;
	T new_n;

	for (uint32_t i = 0; i < vect.size(); i++)
	{
		products.push_back(n*vect.at(i));

		if (vect.size() > 1 && i+1 < vect.size())
		{
			for (uint32_t j = i+1; j < vect.size(); j++)
				temp.push_back(vect.at(j));

			new_n = n*vect.at(i);

			GetAllPossibleProducts(new_n, temp, products);

			temp.clear();
		}
	}
}