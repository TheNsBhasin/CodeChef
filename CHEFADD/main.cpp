//
//  main.cpp
//  CHEFADD
//
//  Created by Nirmaljot Singh Bhasin on 19/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <map>
#include <memory.h>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

typedef long long int lli;
const int MAXN = 31;

lli dp[MAXN][MAXN][MAXN][2];
lli a, b, c;

lli countSetBits(lli n) {
    lli cnt = 0;
    while (n) {
        n &= (n - 1);
        ++cnt;
    }
    return cnt;
}

lli solve(lli cntA, lli cntB, lli pos, bool carry, lli n) {
    if (cntA < 0 || cntB < 0) {
        return 0ll;
    }

    if (!n) {
        return (!cntA && !cntB && !carry);
    }

    if (dp[cntA][cntB][pos][carry] != -1ll) {
        return dp[cntA][cntB][pos][carry];
    }

    lli res = 0ll;

    if (n & 1ll) {
        if (carry) {
            res = solve(cntA - 1, cntB - 1, pos + 1, 1, n >> 1) +
                  solve(cntA, cntB, pos + 1, 0, n >> 1);
        } else {
            res = solve(cntA - 1, cntB, pos + 1, 0, n >> 1) +
                  solve(cntA, cntB - 1, pos + 1, 0, n >> 1);
        }
    } else {
        if (carry) {
            res = solve(cntA - 1, cntB, pos + 1, 1, n >> 1) +
                  solve(cntA, cntB - 1, pos + 1, 1, n >> 1);
        } else {
            res = solve(cntA - 1, cntB - 1, pos + 1, 1, n >> 1) +
                  solve(cntA, cntB, pos + 1, 0, n >> 1);
        }
    }

    return dp[cntA][cntB][pos][carry] = res;
}

int main(int argc, const char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < MAXN; i++) {
            for (int j = 0; j < MAXN; j++) {
                for (int k = 0; k < MAXN; k++) {
                    dp[i][j][k][0] = dp[i][j][k][1] = -1ll;
                }
            }
        }
        cin >> a >> b >> c;
        lli cntA = countSetBits(a);
        lli cntB = countSetBits(b);

        lli res = solve(cntA, cntB, 0, 0, c);
        cout << res << endl;
    }
    return 0;
}