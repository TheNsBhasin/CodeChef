/*input
6 3
0 0 5
0 0 5
8 3 2
8 3 3
8 3 4
8 3 5
0
10
20
*/

//
//  main.cpp
//  CCIRCLES
//
//  Created by Nirmaljot Singh Bhasin on 16/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <vector>
using namespace std;

typedef long long int lli;

const int MAXN = 1000006;
const int N = 1003;

map<pair<pair<lli, lli>, lli>, lli> hm;
vector<pair<pair<lli, lli>, lli>> v;
lli dp[MAXN];

double dist(pair<pair<lli, lli>, lli> &c1, pair<pair<lli, lli>, lli> &c2) {
    lli x1 = c1.first.first, y1 = c1.first.second;
    lli x2 = c2.first.first, y2 = c2.first.second;

    if (x1 == x2 && y1 == y2) {
        return 0;
    }

    lli dx = (x1 - x2) * (x1 - x2);
    lli dy = (y1 - y2) * (y1 - y2);

    return sqrt(dx + dy);
}

int main(int argc, const char *argv[]) {
    lli n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        lli x, y, r;
        cin >> x >> y >> r;
        hm[{{x, y}, r}]++;
    }

    for (auto &p : hm) {
        v.push_back(p.first);
    }

    for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            lli r1 = v[i].second;
            lli r2 = v[j].second;

            double d = dist(v[i], v[j]);

            lli lo = 0, hi = 0;
            if (d == 0) {
                lo = ceil(abs(r2 - r1));
                hi = floor(r1 + r2);
            } else if (d + r1 <= r2) {
                lo = ceil(r2 - d - r1);
                hi = floor(d + r1 + r2);
            } else if (d + r2 <= r1) {
                lo = ceil(r1 - d - r2);
                hi = floor(d + r1 + r2);
            } else if (d <= r1 + r2) {
                lo = 0;
                hi = floor(d + r1 + r2);
            } else if (d >= r1 + r2) {
                lo = ceil(d - r1 - r2);
                hi = floor(d + r1 + r2);
            }

            dp[lo] += (hm[v[i]] * hm[v[j]]);
            dp[hi + 1] -= (hm[v[i]] * hm[v[j]]);
        }
    }

    for (int i = 1; i < MAXN; ++i) {
        dp[i] += dp[i - 1];
    }

    for (int i = 0; i < q; ++i) {
        lli k;
        cin >> k;
        cout << dp[k] << endl;
    }
    return 0;
}
