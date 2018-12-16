/*input
5 3
1 2 3 4 5
1 2 3 4 5
*/

//
//  main.cpp
//  HMAPPY
//
//  Created by Nirmaljot Singh Bhasin on 16/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli a[MAXN], b[MAXN];
long double ab[MAXN];
lli n, m;

bool f(lli val) {
    lli canGive = m;
    for (int i = 0; i < n; ++i) {
        if (a[i] * b[i] > val) {
            lli cnt = ceil((ab[i] - val) / double(b[i]));
            canGive -= cnt;
            if (canGive < 0) {
                return false;
            }
        }
    }
    return canGive >= 0;
}

int main(int argc, const char *argv[]) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    for (int i = 0; i < n; ++i) {
        ab[i] = a[i] * b[i];
    }

    lli res = 1e18;
    lli lo = 0, hi = a[0] * b[0];
    for (int i = 1; i < n; ++i) {
        hi = max(hi, a[i] * b[i]);
    }
    while (lo <= hi) {
        lli mid = lo + ((hi - lo) >> 1);
        if (f(mid)) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << res << endl;
    return 0;
}
