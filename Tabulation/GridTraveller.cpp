//
//  GridTraveller.cpp
//  DynamicProgramming - Grid Traveller using Tabulation
//
//  Created by Peter on 07/09/21.
//  Copyright © 2021 Peter. All rights reserved.
//
//  Compile : g++ -std=c++11 -stdlib=libc++ GridTraveller.cpp
//

#include "../Utils/Utils.h"
#include <map>

using namespace std;

int64_t gridTraveller(const int m, const int n)
{
    //auto size = (m+1) * (n+1);
    auto grid = new int64_t *[m+1];
    for (int i = 0; i <= m+1; ++i) {
        grid[i] = new int64_t[n+1] {0};
    }
    grid[1][1] = 1;
    //print2DArray<int64_t>(grid, m+1, n+1);

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            auto current = grid[i][j];
            if (j + 1 <= n) grid[i][j + 1] += current;
            if (i + 1 <= m) grid[i+1][j] += current;
        }
    }

    //cout << "Transformed matrix\n";
    //print2DArray<int64_t>(grid, m + 1, n + 1);

    return grid[m][n];

    for (int i = 0; i <= m; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}
int main()
{
    cout << gridTraveller(1, 1) << endl;
    cout << gridTraveller(2, 3) << endl;
    cout << gridTraveller(3, 2) << endl;
    cout << gridTraveller(3, 3) << endl;
    cout << gridTraveller(18, 18) << endl;
    
    return 0;
}

