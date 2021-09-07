//
//  Utils.h
//  DynamicProgramming - Utility functions
//
//  Created by Peter on 07/09/21.
//  Copyright © 2021 Peter. All rights reserved.
//
#pragma once
#include <list>
#include <vector>
#include <iostream>

template <typename T>
void printVector(std::vector<T> list)
{
    int i = 1;
    std::cout << "[";
    for (auto item = list.begin(); item != list.end(); ++item)
    {
        std::cout << *item;
        if (i < list.size())
            std::cout << ", ";
        ++i;
    }
    std::cout << "]\n";
}

template <typename T>
void printList(std::list<T> list)
{
    int i = 1;
    std::cout << "[";
    for (auto item = list.begin(); item != list.end(); ++item)
    {
        std::cout << *item;
        if (i < list.size())
            std::cout << ", ";
        ++i;
    }
    std::cout << "], ";
}

template <typename T>
void printNestedList(std::list<std::list<T>> nestedList)
{
    std::cout << "[";
    for (auto& item : nestedList)
    {
        printList(item);
    }
    std::cout << "]\n";
}

template <typename T>
void print2DArray(T** item, int n, int m)
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << item[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

// Lambda function to return bool string.
auto boolToString = [](bool flag) {
    return flag ? "true": "false";
};
