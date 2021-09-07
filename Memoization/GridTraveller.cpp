//
//  GridTraveller.cpp
//  DynamicProgramming - Grid Traveller using Memoization
//
//  Created by Peter on 07/09/21.
//  Copyright © 2021 Peter. All rights reserved.
//
//  Compile : g++ -std=c++11 -stdlib=libc++ GridTraveller.cpp
//

#include "../Utils/Utils.h"
#include <map>

using namespace std;

using GridMemo = map<string, long long>;
long long  gridTraveller(int m, int n, GridMemo& memo)
{
    string key = to_string(m) + "," + to_string(n);
    if (memo.end() != memo.find(key))
    {
        return memo[key];
    }
    if (m == 1 && n == 1)
    {
        return 1;
    }
    if (m == 0 || n == 0)
    {
        return 0;
    }

    memo[key] = gridTraveller(m-1, n, memo) + gridTraveller(m, n-1, memo);
    return memo[key];
}

int main()
{
    GridMemo gridMemo;
    cout << gridTraveller(1, 1, gridMemo) << endl;
    cout << gridTraveller(2, 3, gridMemo) << endl;
    cout << gridTraveller(3, 2, gridMemo) << endl;
    cout << gridTraveller(3, 3, gridMemo) << endl;
    cout << gridTraveller(18, 18, gridMemo) << endl;
    
    return 0;
}

