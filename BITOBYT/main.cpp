//
//  main.cpp
//  BITOBYT
//
//  Created by Nirmaljot Singh Bhasin on 16/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 1602;

lli dp[MAXN][3];

void preprocess() {
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[0][2] = 0;
    for (int i = 1; i < MAXN; ++i) {
        lli bits = i - 2 >= 0 && dp[i - 2][0] > 0 ? dp[i - 2][0] : 0;
        lli nibbles = i - 8 >= 0 && dp[i - 8][1] > 0 ? dp[i - 8][1] : 0;
        lli bytes = i - 16 >= 0 && dp[i - 16][2] > 0 ? dp[i - 16][2] : 0;
        dp[i][0] -= bits;
        dp[i][1] -= nibbles;
        dp[i][2] -= bytes;
        dp[i][0] += (bytes << 1);
        dp[i][1] += bits;
        dp[i][2] += nibbles;
    }

    for (int i = 1; i < MAXN; ++i) {
        dp[i][0] += dp[i - 1][0];
        dp[i][1] += dp[i - 1][1];
        dp[i][2] += dp[i - 1][2];
    }
}

int main(int argc, const char *argv[]) {
    preprocess();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n - 1][0] << " " << dp[n - 1][1] << " " << dp[n - 1][2]
             << endl;
    }
    return 0;
}
