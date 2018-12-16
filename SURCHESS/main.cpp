/*input
8 8
00101010
00010101
10101010
01010101
10101010
01010101
10101010
01010101
4
1 2 0 1001
*/

/*
0 0 0 0 0 0 0 0 0
0 0 1 2 1 4 1 6 1
0 1 2 2 6 2 10 2 14
0 2 2 7 2 13 2 19 2
0 1 6 2 14 2 22 2 30
0 4 2 13 2 23 2 33 2
0 1 10 2 22 2 34 2 46
0 6 2 19 2 33 2 47 2
0 1 14 2 30 2 46 2 62

0 0 0 0 0 0 0 0 0
0 1 1 1 3 1 5 1 7
0 1 2 4 2 8 2 12 2
0 1 4 2 10 2 16 2 22
0 3 2 10 2 18 2 26 2
0 1 8 2 18 2 28 2 38
0 5 2 16 2 28 2 40 2
0 1 12 2 26 2 40 2 54
0 7 2 22 2 38 2 54 2
*/

//
//  main.cpp
//  SURCHESS
//
//  Created by Nirmaljot Singh Bhasin on 15/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <limits.h>
using namespace std;

typedef long long int lli;

const int MAXN = 201;

bool arr[MAXN][MAXN];
lli dp[MAXN][MAXN][2];
lli ans[MAXN];
lli n, m, q;

lli solve(lli cnt) {
    lli lo = 1, hi = min(n, m);
    lli res = 1;
    while (lo <= hi) {
        lli mid = lo + ((hi - lo) >> 1);
        if (ans[mid] <= cnt) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return res;
}

int main(int argc, const char *argv[]) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char ch;
            cin >> ch;
            arr[i][j] = (ch == '1');
        }
    }

    dp[1][1][0] = arr[1][1];
    dp[1][1][1] = !arr[1][1];

    for (int i = 2; i <= n; ++i) {
        dp[i][1][0] = dp[i - 1][1][1] + arr[i][1];
        dp[i][1][1] = dp[i - 1][1][0] + !arr[i][1];
    }
    for (int j = 2; j <= m; ++j) {
        dp[1][j][0] = dp[1][j - 1][1] + arr[1][j];
        dp[1][j][1] = dp[1][j - 1][0] + !arr[1][j];
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= m; ++j) {
            dp[i][j][0] = dp[i - 1][j][1] + dp[i][j - 1][1] -
                          dp[i - 1][j - 1][0] + arr[i][j];
            dp[i][j][1] = dp[i - 1][j][0] + dp[i][j - 1][0] -
                          dp[i - 1][j - 1][1] + !arr[i][j];
        }
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            cout << dp[i][j][0] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            cout << dp[i][j][1] << " ";
        }
        cout << endl;
    }

    for (int k = 1; k < MAXN; ++k) {
        ans[k] = LONG_MAX;
        for (int i = k; i <= n; ++i) {
            for (int j = k; j <= m; ++j) {
                ans[k] =
                    min(ans[k], dp[i][j][0] - dp[i - k][j][k & 1] -
                                    dp[i][j - k][k & 1] + dp[i - k][j - k][0]);
                ans[k] = min(ans[k], dp[i][j][1] - dp[i - k][j][!(k & 1)] -
                                         dp[i][j - k][!(k & 1)] +
                                         dp[i - k][j - k][1]);
            }
        }
    }

    cin >> q;
    for (int i = 0; i < q; ++i) {
        lli cnt;
        cin >> cnt;
        cout << solve(cnt) << endl;
    }
    return 0;
}
