/*input
4
2 1
9 3
11 13
95 83
*/

//
//  main.cpp
//  MINDSUM
//
//  Created by Nirmaljot Singh Bhasin on 16/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <map>
#include <queue>
using namespace std;

typedef long long int lli;

map<lli, lli> hm;

lli digitsum(lli n) {
    lli res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }

    return res;
}

pair<lli, lli> solve(lli n, lli d) {
    queue<pair<lli, lli>> q;
    q.push({n, 0});
    lli steps = 0;
    lli min_val = n;
    lli timeout = 1e6;
    while (!q.empty() && timeout > 0) {
        pair<lli, lli> p = q.front();
        q.pop();
        lli val = p.first;
        lli step = p.second;

        if (hm.find(val) != hm.end()) {
            hm[val] = min(hm[val], step);
        } else {
            hm[val] = step;
        }

        lli sum = val;
        lli cnt = 0;
        while (sum > 9) {
            sum = digitsum(sum);
            ++cnt;
        }

        if (sum < min_val) {
            min_val = sum;
        }

        if (hm.find(sum) != hm.end()) {
            hm[sum] = min(hm[sum], step + cnt);
        } else {
            hm[sum] = step + cnt;
        }

        q.push({val + d, hm[val] + 1});
        q.push({digitsum(val), hm[val] + 1});
        q.push({sum + d, hm[sum] + 1});
        q.push({sum, hm[sum]});
        --timeout;
    }

    return {min_val, hm[min_val]};
}

int main(int argc, const char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        hm.clear();
        lli n, d;
        cin >> n >> d;
        pair<lli, lli> res = solve(n, d);
        cout << res.first << " " << res.second << endl;
    }
    return 0;
}
