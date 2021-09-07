//
//  BestSum.cpp
//  DynamicProgramming - Shortest sum from the input using Tabulation
//
//  Created by Peter on 07/09/21.
//  Copyright © 2021 Peter. All rights reserved.
//
//  Compile : g++ -std=c++11 -stdlib=libc++ BestSum.cpp
//

#include "../Utils/Utils.h"
#include <map>

using namespace std;

using TableItem = tuple<bool, vector<int>>;
vector<int> tBestSum(int targetSum, vector<int> numbers)
{
    vector<TableItem> table(targetSum + 1, make_tuple<bool, vector<int>>(false, vector<int>()));

    get<0>(table[0]) = true;

    for (int i = 0; i <= targetSum; ++i) {
        if (get<0>(table[i])) {

            for (auto& num : numbers) {
                if (i + num <= targetSum) {
                    get<0>(table[i + num]) = true;
                    auto& target = get<1>(table[i + num]);
                    auto& src = get<1>(table[i]);
                    auto combination = vector<int>(src.begin(), src.end());
                    combination.push_back(num);
                    if (combination.size() < target.size() || target.size() == 0) {
                        target = combination;
                    }
                }
            }
        }
    }

    return get<1>(table[targetSum]);
}

int main()
{
    printVector(tBestSum(7, { 5, 3, 4, 7 }));
    printVector(tBestSum(8, { 2, 3, 5}));
    printVector(tBestSum(8, { 1, 4, 5 }));
    printVector(tBestSum(100, { 1, 2, 5, 25 }));
    printVector(tBestSum(300, { 7, 14 }));
    printVector(tBestSum(1024, { 2, 4, 8, 514, 16 }));
    
    return 0;
}
