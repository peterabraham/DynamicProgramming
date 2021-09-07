//
//  BestSum.cpp
//  DynamicProgramming - Shortest sum from the input using Memoization
//
//  Created by Peter on 07/09/21.
//  Copyright © 2021 Peter. All rights reserved.
//
//  Compile : g++ -std=c++11 -stdlib=libc++ BestSum.cpp
//

#include "../Utils/Utils.h"
#include <map>

using namespace std;

using BestSumResult = tuple<bool, vector<int>>;
using BestSumMemo = map<int, BestSumResult>;
BestSumResult bestSum(int targetSum, initializer_list<int> numbers, BestSumMemo& memo)
{
    if (memo.end() != memo.find(targetSum)) return memo[targetSum];
    if (targetSum == 0) return make_tuple<bool, vector<int>>(true, {});
    if (targetSum < 0) return make_tuple<bool, vector<int>>(false, {});

    auto shortestCombination = make_tuple<bool, vector<int>>(false, {});

    for (auto& num : numbers)
    {
        auto remainder = targetSum - num;
        auto remainderCombination = bestSum(remainder, numbers, memo);

        if (get<0>(remainderCombination) == true)
        {
            auto remainderList = get<1>(remainderCombination);
            remainderList.push_back(num);

            auto combination = make_tuple<bool, vector<int>>(true, vector<int>(remainderList));

            if (get<1>(combination).size() < get<1>(shortestCombination).size() ||
                get<0>(shortestCombination) == false)
            {
                shortestCombination = combination;
            }
        }
    }

    memo[targetSum] = shortestCombination;
    return shortestCombination;
}

int main()
{
    BestSumMemo bestSumMemo;
    printVector(get<1>(bestSum(7, { 5, 3, 4, 7 }, bestSumMemo)));
    bestSumMemo.clear();
    printVector(get<1>(bestSum(8, { 2, 3, 5}, bestSumMemo)));
    bestSumMemo.clear();
    printVector(get<1>(bestSum(8, { 1, 4, 5 }, bestSumMemo)));
    bestSumMemo.clear();
    printVector(get<1>(bestSum(100, { 1, 2, 5, 25 }, bestSumMemo)));
    bestSumMemo.clear();
    printVector(get<1>(bestSum(300, { 7, 14 }, bestSumMemo)));
    bestSumMemo.clear();
    printVector(get<1>(bestSum(1024, { 2, 4, 8, 514, 16 }, bestSumMemo)));
    
    return 0;
}
