/*input
2
3
4 2 2
5 3 4
4
2 1 1 2
3 3 3 3
*/

//
//  main.cpp
//  EQUALMOD
//
//  Created by Nirmaljot Singh Bhasin on 05/11/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef long long int lli;
const int MAXN = 5 * 100005;
const int INF = 1e9 + 7;

lli suffix[MAXN], prefix[MAXN];

int main(int argc, const char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        memset(prefix, 0, sizeof(prefix));
        memset(suffix, 0, sizeof(suffix));
        lli n;
        cin >> n;
        vector<pair<lli, lli>> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> v[i].second;
        }
        lli mini = INF;
        for (int i = 0; i < n; ++i) {
            mini = min(mini, v[i].second - 1);
            v[i].first %= v[i].second;
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + v[i].first;
        }
        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + (v[i].second - v[i].first);
        }
        lli res = suffix[0];
        for (int i = 0; i < n; ++i) {
            if (v[i].first <= mini) {
                res = min(res, v[i].first * n - prefix[i + 1] + suffix[i + 1]);
            }
        }
        cout << res << endl;
    }
    return 0;
}
