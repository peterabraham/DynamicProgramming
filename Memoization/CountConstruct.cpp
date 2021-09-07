//
//  CountConstruct.cpp
//  DynamicProgramming - How many ways string constructed from the input
//
//  Created by Peter on 07/09/21.
//  Copyright © 2021 Peter. All rights reserved.
//
//  Compile : g++ -std=c++11 -stdlib=libc++ CountConstruct.cpp
//

#include "../Utils/Utils.h"
#include <map>

using namespace std;

using CountConstructMemo = map<string, int>;
int countConstruct(string targetWord, initializer_list<string> wordBank, CountConstructMemo& memo)
{
    if (memo.end() != memo.find(targetWord)) return memo[targetWord];
    if (targetWord.empty()) return 1;

    auto count = 0;
    for (auto& word : wordBank)
    {
        // valid prefix
        if (targetWord.find(word) == 0)
        {
            auto suffix = targetWord.substr(word.size());
            count += countConstruct(suffix, wordBank, memo);
        }
    }

    memo[targetWord] = count;
    return count;
}

int main()
{
    CountConstructMemo countConstructMemo;
    cout << countConstruct("purple", { "purp", "p", "ur", "le", "purpl" }, countConstructMemo) << endl;
    countConstructMemo.clear();
    cout << countConstruct("abcdef", { "ab", "abc", "cd", "def", "abcd" }, countConstructMemo) << endl;
    countConstructMemo.clear();
    cout << countConstruct("skateboard", { "bo", "rd", "ate", "t", "ska", "sk", "boar" }, countConstructMemo) << endl;
    countConstructMemo.clear();
    cout << countConstruct("enterapotentpot", { "a", "p", "ent", "enter", "ot", "o", "t" }, countConstructMemo) << endl;
    countConstructMemo.clear();
    cout << countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", { "e", "ee", "eee", "eeee", "eeeee", "eeeeee" }, countConstructMemo) << endl;
}
