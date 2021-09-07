//
//  CanSum.cpp
//  DynamicProgramming - Can sum the input using Tabulation
//
//  Created by Peter on 07/09/21.
//  Copyright © 2021 Peter. All rights reserved.
//
//  Compile : g++ -std=c++11 -stdlib=libc++ CanSum.cpp
//

#include "../Utils/Utils.h"
#include <map>

using namespace std;

bool canSum(int targetSum, vector<int> numbers)
{
    vector<bool> table(targetSum + 1, false);
    table[0] = true;

    for (int i = 0; i < targetSum; ++i) {
        if (table[i] == true) {
            for (int j = 0; j < numbers.size(); ++j) {
                if (i + numbers[j] <= targetSum) {
                    table[i + numbers[j]] = true;
                }
            }
        }
    }

    return table[targetSum];
}

int main()
{
    cout << boolToString(canSum(7, {2, 3})) << endl;
    cout << boolToString(canSum(7, { 5, 3, 4, 7 })) << endl;
    cout << boolToString(canSum(7, { 2, 4 })) << endl;
    cout << boolToString(canSum(8, { 2, 3, 5 })) << endl;
    cout << boolToString(canSum(300, { 7, 14 })) << endl;
    cout << boolToString(canSum(1025, { 2, 4, 8, 16 })) << endl;
}
