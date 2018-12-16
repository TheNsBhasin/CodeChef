/*input
2
4
1 7 3 8
4
2 3 2 2
*/

//
//  main.cpp
//  TEAMMATE
//
//  Created by Nirmaljot Singh Bhasin on 12/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

typedef long long int lli;

const int MAXN = 1000006;
const int MOD = 1e9 + 7;

lli fact[MAXN];
map<lli, lli> hm;

void preprocess() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = ((fact[i - 1] % MOD) * (i % MOD)) % MOD;
    }
}

lli power(lli a, lli n, lli mod) {
    lli res = 1;
    while (n > 0) {
        if (n & 1) {
            res = ((res % mod) * (a % mod)) % mod;
        }
        n >>= 1;
        a = ((a % mod) * (a % mod)) % mod;
    }

    return res;
}

lli f(lli n) {
    lli res = fact[n] % MOD;
    lli inv = ((fact[n >> 1] % MOD) * (1 << (n >> 1)) % MOD) % MOD;
    inv = power(inv, MOD - 2, MOD);
    res = ((res % MOD) * (inv % MOD)) % MOD;
    return res % MOD;
}

int main(int argc, const char *argv[]) {
    preprocess();
    int t;
    cin >> t;
    while (t--) {
        hm.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            lli x;
            cin >> x;
            hm[-x]++;
        }

        lli res = 1;
        lli next = 0;

        for (auto &p : hm) {
            lli cnt = p.second;
            if (next) {
                res = ((res % MOD) * (cnt % MOD)) % MOD;
                --cnt;
            }
            next = cnt & 1ll;
            res = ((res % MOD) * (f(cnt + next) % MOD)) % MOD;
        }

        cout << res % MOD << endl;
    }
    return 0;
}
