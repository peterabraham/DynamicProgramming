//
//  AllConstruct.cpp
//  DynamicProgramming - Possible ways string constructed from the input
//
//  Created by Peter on 07/09/21.
//  Copyright © 2021 Peter. All rights reserved.
//
//  Compile : g++ -std=c++11 -stdlib=libc++ AllConstruct.cpp
//

#include "../Utils/Utils.h"
#include <map>

using namespace std;

using AllConstructResult = list<list<string>>;
using AllConstructMemo = map<string, AllConstructResult>;
AllConstructResult allConstruct(string targetWord, initializer_list<string> wordBank, AllConstructMemo& memo)
{
    if (memo.end() != memo.find(targetWord)) return memo[targetWord];
    if (targetWord.empty()) return {{}};

    auto result = list<list<string>> {};
    for (auto& word : wordBank)
    {
        if (targetWord.find(word) == 0)
        {
            auto suffix = targetWord.substr(word.size());
            auto suffixWays = allConstruct(suffix, wordBank, memo);
            for (auto& item : suffixWays) item.push_front(word);
            result.merge(suffixWays);
        }
    }

    memo[targetWord] = result;
    return result;
}

int main()
{
    AllConstructMemo allConstructMemo;
    printNestedList<string>(allConstruct("purple", { "purp", "p", "ur", "le", "purpl" }, allConstructMemo));
    allConstructMemo.clear();
    printNestedList<string>(allConstruct("abcdef", { "ab", "abc", "cd", "def", "abcd", "ef", "c" }, allConstructMemo));
    allConstructMemo.clear();
    printNestedList<string>(allConstruct("skateboard", { "bo", "rd", "ate", "t", "ska", "sk", "boar" }, allConstructMemo));
    allConstructMemo.clear();
    printNestedList<string>(allConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", { "e", "ee", "eee", "eeee", "eeeee", "eeeeee" }, allConstructMemo));
    
    return 0;
}
