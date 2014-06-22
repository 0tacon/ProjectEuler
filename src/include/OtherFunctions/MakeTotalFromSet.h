#include <cstdint>
#include <cstdio>
#include <vector>
#include <algorithm>

#define _MAKETOTALFROMSET_

std::vector<std::vector<uint64_t> > MakeTotalFromSet (std::vector<uint64_t> set, uint64_t total);
void MakeTotalFromSet_RecursiveLoop (std::vector<uint64_t> set, uint64_t total, std::vector<uint64_t> &current_combo, std::vector<std::vector<uint64_t> > &combos);

std::vector<std::vector<uint64_t> > MakeTotalFromSet (std::vector<uint64_t> set, uint64_t total)
{
    std::vector<std::vector<uint64_t> > combos;
    std::vector<uint64_t> current_combo;

    MakeTotalFromSet_RecursiveLoop(set, total, current_combo, combos);

    return combos;
}

void MakeTotalFromSet_RecursiveLoop (std::vector<uint64_t> set, uint64_t total, std::vector<uint64_t> &current_combo, std::vector<std::vector<uint64_t> > &combos)
{
    uint64_t temp_total;
    std::vector<uint64_t> temp_set = set;
    temp_set.erase(std::prev(temp_set.end(), 1), temp_set.end());

    for (uint64_t i = 0; i <= total/set[set.size() - 1]; i++)
    {
        temp_total = total - i*set[set.size() - 1];

        for (uint64_t a = 0; a < i; a++)
            current_combo.push_back(set[set.size() - 1]);

        if (temp_total != 0 && temp_set.size() > 0)
            MakeTotalFromSet_RecursiveLoop(temp_set, temp_total, current_combo, combos);
        else if (temp_total == 0)
            combos.push_back(current_combo);

        current_combo.erase(std::prev(current_combo.end(), i), current_combo.end());
    }
}
