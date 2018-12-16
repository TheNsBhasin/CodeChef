//
//  main.cpp
//  BBRICKS
//
//  Created by Nirmaljot Singh Bhasin on 14/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

const int MAXN = 1003;
const int MOD = 1e9 + 7;

lli dp[MAXN];

lli power(lli a, lli n, lli mod) {
    lli res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (res * a) % MOD;
        }
        n >>= 1;
        a = (a * a) % MOD;
    }

    return res % MOD;
}

int main(int argc, const char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        lli n, k;
        cin >> n >> k;

        if (k == 1) {
            cout << (n * 2) % MOD << endl;
            continue;
        }

        if (n == k) {
            cout << 2 << endl;
            continue;
        }

        if (n < k) {
            cout << 0 << endl;
            continue;
        }

        dp[1] = (((n - k + 1) % MOD) * 2) % MOD;
        for (int i = 2; i <= k; ++i) {
            dp[i] = dp[i - 1] % MOD;
            dp[i] = (dp[i] * 2) % MOD;
            dp[i] = (dp[i] * ((MOD + k + 1 - i) % MOD)) % MOD;
            dp[i] = (dp[i] * ((MOD + n - k - i + 2) % MOD)) % MOD;
            dp[i] = (dp[i] * (power(i, MOD - 2, MOD) % MOD)) % MOD;
            dp[i] = (dp[i] * (power(i - 1, MOD - 2, MOD) % MOD)) % MOD;
        }

        lli res = 0;

        for (int i = 1; i <= k; ++i) {
            res = (res + dp[i]) % MOD;
        }

        cout << res << endl;
    }
    return 0;
}
