/*input
2
8 5
20 10 10 10 7 7 7 10
2 6 2
3 6 2
3 6 3
3 8 3
3 8 1
3 2
27 27 27
1 3 1
2 2 1
*/

//
//  main.cpp
//  SMARKET
//
//  Created by Nirmaljot Singh Bhasin on 29/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli arr[MAXN], pre[MAXN], post[MAXN];
map<lli, vector<lli> > m;

lli solve(lli L, lli R, lli K) {
    if (m.count(K) == 0 || m[K].size() == 0) {
        return 0;
    }
    lli ans = 0; 
    if (pre[L] != 1) {
        if (post[L] >= K) {
            ++ans;
        }
        L += post[L];
    }

    lli low = lower_bound(m[K].begin(), m[K].end(), L) - m[K].begin();
    lli high = lower_bound(m[K].begin(), m[K].end(), R) - m[K].begin();
    if (high == m[K].size() || m[K][high] > R) {
        --high;
    }
    ans += high - low + 1;
    return ans;
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        m.clear();
        int n, q;
        cin >> n >> q;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        pre[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (arr[i] == arr[i - 1]) {
                pre[i] = pre[i - 1] + 1;
            } else {
                pre[i] = 1;
            }
        }
        post[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] == arr[i + 1]) {
                post[i] = post[i + 1] + 1;
            } else {
                post[i] = 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            m[pre[i]].push_back(i);
        }
        while (q--) {
            lli L, R, K;
            lli ans = 0;
            cin >> L >> R >> K;
            cout << solve(L - 1, R - 1, K) << endl;
        }
    }
    return 0;
}
