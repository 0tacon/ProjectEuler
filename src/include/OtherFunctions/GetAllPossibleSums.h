/*

Copyright 2014 Daniel Forde

This file is part of ProjectEuler.

ProjectEuler is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ProjectEuler is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ProjectEuler.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <cstdint>
#include <vector>
#include <utility>
#include <algorithm>

#define _GETALLPOSSIBLESUMS_

template<typename T> void GetAllPossibleSums_RecursiveLoop(T n, std::vector<T> v, std::vector<std::pair<T, std::vector<T> > > &sums, std::vector<T> &temp_nums);
template<typename T> void GetAllPossibleSums(std::vector<T> v, std::vector<std::pair<T, std::vector<T> > > &sums);
template<typename T> void GetAllPossibleSums_RecursiveLoop(T n, std::vector<T> v, std::vector<std::pair<T, std::vector<T> > > &sums, std::vector<T> &temp_nums, std::vector<T> &additional_vals);
template<typename T> void GetAllPossibleSums(std::vector<T> v, std::vector<std::pair<T, std::vector<T> > > &sums, std::vector<T> &additional_vals);

template<typename T>
void GetAllPossibleSums_RecursiveLoop(T n, std::vector<T> v, std::vector<std::pair<T, std::vector<T> > > &sums, std::vector<T> &temp_nums)
{
    std::vector<T> temp_v(v.size()-1);

    for (typename std::vector<T>::iterator a = v.begin(); a != v.end(); a++)
    {
        temp_nums.push_back(*a);

        if (n != 0)
            sums.push_back(std::make_pair(n + *a, temp_nums));

        if (v.size() > 1 && a != std::prev(v.end(), 1))
        {
            std::copy(std::next(a, 1), v.end(), temp_v.begin());
            temp_v = v;
            temp_v.erase(temp_v.begin(), std::next(std::find(temp_v.begin(), temp_v.end(), *a), 1));

            GetAllPossibleSums_RecursiveLoop(static_cast<T>(n + *a), temp_v, sums, temp_nums);

            temp_v.clear();
        }

        temp_nums.erase(std::prev(temp_nums.end(), 1), temp_nums.end());
    }
}

template<typename T>
void GetAllPossibleSums(std::vector<T> v, std::vector<std::pair<T, std::vector<T> > > &sums)
{
    std::vector<T> temp_nums;

    GetAllPossibleSums_RecursiveLoop(static_cast<T>(0), v, sums, temp_nums);
}

template<typename T>
void GetAllPossibleSums_RecursiveLoop(T n, std::vector<T> v, std::vector<std::pair<T, std::vector<T> > > &sums, std::vector<T> &temp_nums, std::vector<T> &additional_vals)
{
    std::vector<T> temp_v(v.size()-1);
    T temp_sum_total;

    for (typename std::vector<T>::iterator a = v.begin(); a != v.end(); a++)
    {
        temp_nums.push_back(*a);

        temp_sum_total = n + *a;

        for (typename std::vector<T>::iterator val = additional_vals.begin(); val != additional_vals.end(); val++)
            temp_sum_total += *val;

        sums.push_back(std::make_pair(temp_sum_total, temp_nums));

        if (v.size() > 1 && a != std::prev(v.end(), 1))
        {
            std::copy(std::next(a, 1), v.end(), temp_v.begin());
            temp_v = v;
            temp_v.erase(temp_v.begin(), std::next(std::find(temp_v.begin(), temp_v.end(), *a), 1));

            GetAllPossibleSums_RecursiveLoop(static_cast<T>(n + *a), temp_v, sums, temp_nums, additional_vals);

            temp_v.clear();
        }

        temp_nums.erase(std::prev(temp_nums.end(), 1), temp_nums.end());
    }
}

template<typename T>
void GetAllPossibleSums(std::vector<T> v, std::vector<std::pair<T, std::vector<T> > > &sums, std::vector<T> &additional_vals)
{
    std::vector<T> temp_nums;

    temp_nums = additional_vals;

    GetAllPossibleSums_RecursiveLoop(static_cast<T>(0), v, sums, temp_nums, additional_vals);
}
