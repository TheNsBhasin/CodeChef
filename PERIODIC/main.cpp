//
//  main.cpp
//  PERIODIC
//
//  Created by Nirmaljot Singh Bhasin on 20/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;
const int INF = 1e9 + 7;

lli arr[MAXN];
int n;

lli gcd(lli a, lli b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

void solve() {
    lli res = -1;
    lli maxN = -1;
    lli prevI = -1;
    bool ans = true;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == -1) {
            continue;
        }
        maxN = max(arr[i], maxN);
        if (prevI == -1) {
            prevI = i;
            continue;
        }
        lli p = arr[prevI] + i - prevI - arr[i];
        prevI = i;
        if (p == 0) {
            continue;
        } else if (p < 0) {
            ans = false;
            break;
        }
        if (res == -1) {
            res = p;
            continue;
        }
        res = gcd(res, p);
    }
    if (!ans) {
        cout << "impossible" << endl;
    } else if (res == -1) {
        cout << "inf" << endl;
    } else if (maxN > res) {
        cout << "impossible" << endl;
    } else {
        cout << res << endl;
    }
}

int main(int argc, const char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        solve();
    }
    return 0;
}
