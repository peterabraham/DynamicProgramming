//
//  CanSum.cpp
//  DynamicProgramming - Can sum the input using Memoization
//
//  Created by Peter on 07/09/21.
//  Copyright © 2021 Peter. All rights reserved.
//
//  Compile : g++ -std=c++11 -stdlib=libc++ CanSum.cpp
//

#include "../Utils/Utils.h"
#include <map>

using namespace std;

using CanSumMemo = map<int, bool>;
bool canSum(int targetSum, initializer_list<int> numbers, CanSumMemo& memo)
{
    if (memo.end() != memo.find(targetSum))
    {
        return memo[targetSum];
    }
    if (targetSum == 0)
    {
        return true;
    }
    if (targetSum < 0)
    {
        return false;
    }

    for (auto& num : numbers)
    {
        auto remainder = targetSum - num;
        if (canSum(remainder, numbers, memo) == true)
        {
            memo[remainder] = true;
            return true;
        }
    }

    memo[targetSum] = false;
    return false;
}

int main()
{
    CanSumMemo canSumMemo1;
    cout << boolToString(canSum(7, {2, 3}, canSumMemo1)) << endl;
    CanSumMemo canSumMemo2;
    cout << boolToString(canSum(7, { 5, 3, 4, 7 }, canSumMemo2)) << endl;
    CanSumMemo canSumMemo3;
    cout << boolToString(canSum(7, { 2, 4 }, canSumMemo3)) << endl;
    CanSumMemo canSumMemo4;
    cout << boolToString(canSum(8, { 2, 3, 5 }, canSumMemo4)) << endl;
    CanSumMemo canSumMemo5;
    cout << boolToString(canSum(300, { 7, 14 }, canSumMemo5)) << endl;
    CanSumMemo canSumMemo6;
    cout << boolToString(canSum(1025, { 2, 4, 8, 16 }, canSumMemo6)) << endl;
}
