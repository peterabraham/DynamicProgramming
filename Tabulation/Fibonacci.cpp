//
//  Fibonacci.cpp
//  DynamicProgramming - Fibonacci using Tabulation
//
//  Created by Peter on 07/09/21.
//  Copyright © 2021 Peter. All rights reserved.
//
//  Compile : g++ -std=c++11 -stdlib=libc++ Fibonacci.cpp
//

#include "../Utils/Utils.h"
#include <map>

using namespace std;

int64_t fib(int n)
{
    auto table = vector<int64_t>(n + 1, 0);
    table[1] = 1;

    for (auto i = 0; i <= n; ++i)
    {
        if (i + 1 <= n)
        {
            table[i + 1] += table[i];
        }

        if (i + 2 <= n)
        {
            table[i + 2] += table[i];
        }
    }

    return table[n];
}


int main()
{
    cout << fib(6) << endl;
    cout << fib(7) << endl;
    cout << fib(8) << endl;
    cout << fib(50) << endl;
    
    return 0;
}
