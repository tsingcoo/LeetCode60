//
// Created by 王青龙 on 23/02/2017.
//

#include <vector>
#include <iostream>
#include <numeric>
#include "solution.h"

std::string Solution::getPermutation(int n, int k) {
    std::vector<char> numSet(n, '0');
    std::iota(numSet.begin(), numSet.end(), '1');
//    for (auto i : numSet) {
//        std::cout << i << std::endl;
//    }

    int f = 1;
    for (int i = 1; i <= n; ++i) {
//        numSet[i - 1] += i;
        f *= i;
    }
    std::string res;
    while (n > 0) {
        f /= n;
//        std::cout << n << " " << f << std::endl;
        int index = (k - 1) / f;
//        std::cout << k << " " << index << " "<<std::endl;
        char c = numSet[index];
        res += c;
        numSet.erase(numSet.begin() + index);
        k = k - index * f;
        --n;
    }
    return res;
}
