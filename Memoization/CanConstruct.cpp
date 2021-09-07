//
//  CanConstruct.cpp
//  DynamicProgramming - Can construct string from the input using Memoization
//
//  Created by Peter on 07/09/21.
//  Copyright © 2021 Peter. All rights reserved.
//
//  Compile : g++ -std=c++11 -stdlib=libc++ CanConstruct.cpp
//

#include "../Utils/Utils.h"
#include <map>

using namespace std;

using CanConstructMemo = map<string, bool>;
bool canConstruct(string targetWord, initializer_list<string> wordBank, CanConstructMemo& memo)
{
    if (memo.end() != memo.find(targetWord)) return memo[targetWord];
    if (targetWord.empty()) return true;

    for (auto& word : wordBank)
    {
        // valid prefix
        if (targetWord.find(word) == 0)
        {
            auto suffix = targetWord.substr(word.size());
            if (canConstruct(suffix, wordBank, memo))
            {
                memo[suffix] = true;
                return true;
            }
        }
    }

    memo[targetWord] = false;
    return false;
}

int main()
{
    CanConstructMemo canConstructmemo;
    cout << boolToString(canConstruct("abcdef", { "ab", "abc", "cd", "def", "abcd" }, canConstructmemo)) << endl;
    canConstructmemo.clear();
    cout << boolToString(canConstruct("skateboard", { "bo", "rd", "ate", "t", "ska", "sk", "boar" }, canConstructmemo)) << endl;
    canConstructmemo.clear();
    cout << boolToString(canConstruct("enterapotentpot", { "a", "p", "ent", "enter", "ot", "o", "t" }, canConstructmemo)) << endl;
    canConstructmemo.clear();
    cout << boolToString(canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", { "e", "ee", "eee", "eeee", "eeeee", "eeeeee" }, canConstructmemo)) << endl;
    canConstructmemo.clear();
    
    return 0;
}
