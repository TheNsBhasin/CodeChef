/*input
3
5 5
1 1 2
1 4 5
2 1 2
2 1 3
2 3 4
1 2
1 1 1
1 1 1
10 10
1 1 10
2 1 1
2 1 2
2 1 3
2 1 4
2 1 5
2 1 6
2 1 7
2 1 8
2 1 9
*/

//
//  main.cpp
//  SEACO
//
//  Created by Nirmaljot Singh Bhasin on 04/09/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <cstring>
using namespace std;

typedef long long int lli;
const lli MOD = 1000000007;

vector< pair<lli, lli> > query;
map< map<lli, lli> > state;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        query.clear();
        lli n, m;
        cin >> n >> m;
        vector<lli> inc(m + 1, 0);
        vector<lli> ans(n + 1, 0);
        for (lli i = 1; i <= m; ++i) {
            lli type, l, r;
            cin >> type >> l >> r;
            if (type == 1) {
                ans[l] = ans[l] + 1;
                state[i][l] += 1;
                if (i < m) {
                    ans[i + 1] = ans[r + 1] - 1;
                    state[i][r] -= 1;
                }
            } else if (type == 2) {
                query.push_back(make_pair(l , r));
                for (int k = l; k <= r; ++k) {

                }
            }
        }
        for (lli i = 1; i <= n; ++i) {
            ans[i] = (ans[i] + ans[i - 1]);
            cout << ans[i] % MOD << " ";
        }
        cout << endl;
    }
    return 0;
}
