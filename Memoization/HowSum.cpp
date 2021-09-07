//
//  HowSum.cpp
//  DynamicProgramming - How to sum the input using Memoization
//
//  Created by Peter on 07/09/21.
//  Copyright © 2021 Peter. All rights reserved.
//
//  Compile : g++ -std=c++11 -stdlib=libc++ HowSum.cpp
//

#include "../Utils/Utils.h"
#include <map>

using namespace std;

using HowSumResult = tuple<bool, vector<int>>;
using HowSumMemo = map<int, HowSumResult>;
HowSumResult howSum(int targetSum, initializer_list<int> numbers, HowSumMemo& memo)
{
    if (memo.end() != memo.find(targetSum)) return memo[targetSum];
    if (targetSum == 0) return make_tuple<bool, vector<int>>(true, {});
    if (targetSum < 0) return make_tuple<bool, vector<int>>(false, {});

    for (auto& num : numbers)
    {
        auto remainder = targetSum - num;
        auto remainderRes = howSum(remainder, numbers, memo);

        if (get<0>(remainderRes) == true)
        {
            auto remainderList = get<1>(remainderRes);
            remainderList.push_back(num);
            auto res = make_tuple<bool, vector<int>>(true, vector<int>(remainderList));
            memo[remainder] = res;
            return res;
        }
    }

    auto res = make_tuple<bool, vector<int>>(false, {});
    memo[targetSum] = res;
    return res;
}

int main()
{
    HowSumMemo howSumMemo;
    printVector(get<1>(howSum(7, { 2, 3 }, howSumMemo)));
    howSumMemo.clear();
    printVector(get<1>(howSum(7, { 5, 3, 4, 7 }, howSumMemo)));
    howSumMemo.clear();
    printVector(get<1>(howSum(7, { 2, 4 }, howSumMemo)));
    howSumMemo.clear();
    printVector(get<1>(howSum(8, { 2, 3, 5 }, howSumMemo)));
    howSumMemo.clear();
    printVector(get<1>(howSum(300, { 7, 14 }, howSumMemo)));
    howSumMemo.clear();
    printVector(get<1>(howSum(1025, { 2, 4, 8, 16}, howSumMemo)));
    
    return 0;
}
