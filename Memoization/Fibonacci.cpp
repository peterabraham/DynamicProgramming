//
//  Fibonacci.cpp
//  DynamicProgramming - Fibonacci using Memoization
//
//  Created by Peter on 07/09/21.
//  Copyright © 2021 Peter. All rights reserved.
//
//  Compile : g++ -std=c++11 -stdlib=libc++ Fibonacci.cpp
//

#include "../Utils/Utils.h"
#include <map>

using namespace std;

using FibMemo = map<long, long long>;
long long fib(long n, FibMemo& memo)
{
    if (memo.end() != memo.find(n))
    {
        return memo[n];
    }

    if (n <= 2)
    {
        return 1;
    }


    memo[n] =  fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];
}

int main()
{
    FibMemo fibMemo;
    cout << fib(6, fibMemo) << endl;
    cout << fib(7, fibMemo) << endl;
    cout << fib(8, fibMemo) << endl;
    cout << fib(50, fibMemo) << endl;
    
    return 0;
}
