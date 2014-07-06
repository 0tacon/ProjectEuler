/*
    If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

    {20,48,52}, {24,45,51}, {30,40,50}

    For which value of p ≤ 1000, is the number of solutions maximised?
*/

#include <cstdint>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>

bool Problem39()
{
    std::map<float, std::vector<std::vector<float> > > results;
    std::vector<float> temp_vect;
    float a;
    uint8_t largest_num_triplets = 0;
    uint16_t ans;

    for (float p = 12.0f; p < 1001.0f; p++)
        for (float b = 1; b <= p/(2.0f + sqrt(2.0f)); b++)
        {
            a = (p/2.0f)*((2.0f*b-p)/(b-p));

            if (fmod(a, 1.0f) == 0.0f)
            {
                temp_vect.clear();
                temp_vect.push_back(a);
                temp_vect.push_back(b);
                temp_vect.push_back(sqrt(a*a + b*b));
                results[p].push_back(temp_vect);
            }
        }

    for (std::map<float, std::vector<std::vector<float> > >::iterator per = results.begin(); per != results.end(); per++)
        if (per->second.size() > largest_num_triplets)
        {
            largest_num_triplets = per->second.size();
            ans = static_cast<uint16_t>(per->first);
        }

    printf("\nProblem 039: %u\n", ans);
    return true;
}
