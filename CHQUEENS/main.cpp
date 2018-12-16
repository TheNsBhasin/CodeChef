//
//  main.cpp
//  CHQUEENS
//
//  Created by Nirmaljot Singh Bhasin on 03/11/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 102;

const lli dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const lli dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

lli arr[MAXN][MAXN];

bool isSafe(lli x, lli y, lli n, lli m) {
    if (x < 0 || y < 0 || x >= n || y >= m) {
        return false;
    }
    return true;
}

lli solve(lli u, lli v, lli x, lli y, lli n, lli m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = 1;
        }
    }
    arr[u][v] = 0;
    arr[x][y] = -1;
    for (int k = 0; k < 8; ++k) {
        lli i = u + dx[k];
        lli j = v + dy[k];
        while (isSafe(i, j, n, m)) {
            if (arr[i][j] == -1) {
                break;
            }
            arr[i][j] = 0;
            i += dx[k];
            j += dy[k];
        }
    }
    lli ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // cout << arr[i][j] << " ";
            if (arr[i][j] == 1) {
                ++ans;
                arr[i][j]++;
            }
        }
        // cout << endl;
    }
    // cout << endl;
    return ans;
}

int main(int argc, const char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        lli n, m, x, y;
        cin >> n >> m >> x >> y;
        --x;
        --y;
        lli res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == x && j == y) {
                    continue;
                }
                res += solve(i, j, x, y, n, m);
            }
        }
        cout << res << endl;
    }
    return 0;
}
