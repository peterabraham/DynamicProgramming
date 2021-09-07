//
//  HowSum.cpp
//  DynamicProgramming - How to sum the input using Tabulation
//
//  Created by Peter on 07/09/21.
//  Copyright © 2021 Peter. All rights reserved.
//
//  Compile : g++ -std=c++11 -stdlib=libc++ HowSum.cpp
//

#include "../Utils/Utils.h"
#include <map>

using namespace std;

using TableItem = tuple<bool, vector<int>>;
vector<int> howSum(int targetSum, vector<int> numbers)
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
                    target = vector<int>(src.begin(), src.end());
                    target.push_back(num);
                }
            }
        }
    }

    return get<1>(table[targetSum]);
}
int main()
{
    printVector(howSum(7, { 2, 3 }));
    printVector(howSum(7, { 5, 3, 4, 7 }));
    printVector(howSum(7, { 2, 4 }));
    printVector(howSum(8, { 2, 3, 5 }));
    printVector(howSum(300, { 7, 14 }));
    printVector(howSum(1025, { 2, 4, 8, 16}));
    
    return 0;
}
