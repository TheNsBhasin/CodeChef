/*input
2
4 3
1 2
2 3
3 4
2 1
1 2
*/

//
//  main.cpp
//  SEAKAM
//
//  Created by Nirmaljot Singh Bhasin on 25/08/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

typedef long long int lli;
const lli MAXN = 1e5 + 10;
const lli MOD = 1e9 + 7;

map< pair< lli, lli>, int > edge;
vector<lli> faulty_nodes;
lli mark_faulty[MAXN], dp[1 << 15][15][15];
lli fact[MAXN], inv_fact[MAXN];

lli poww(lli a, lli b)
{
    lli ans = 1;
    while (b) {
        if (b % 2) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b = b >> 1;
    }
    return ans;
}

void preprocess() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv_fact[i] = poww(fact[i], MOD - 2);
    }
}

lli nCr(lli n, lli r) {
    if (n < r) {
        return 0;
    }
    lli ret = fact[n];
    ret = (ret * inv_fact[r]) % MOD;
    ret = (ret * inv_fact[n - r]) % MOD;
    return ret;
}

int main(int argc, const char * argv[]) {
    preprocess();

    int t;
    lli n, m;
    cin >> t;
    while (t--) {
        edge.clear(); faulty_nodes.clear();
        memset(mark_faulty, 0, sizeof mark_faulty);
        memset(dp, 0, sizeof dp);
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;

            if (!mark_faulty[u]) {
                mark_faulty[u] = 1;
                faulty_nodes.push_back(u);
            }
            if (!mark_faulty[v]) {
                mark_faulty[v] = 1;
                faulty_nodes.push_back(v);
            }

            edge[make_pair(u, v)] = 1;
            edge[make_pair(v, u)] = 1;
        }

        lli normal_nodes = n - faulty_nodes.size();
        lli ans = 0;

        for (int i = 0; i < faulty_nodes.size(); ++i)
            dp[1 << i][i][0] = 1;

        for (int mask = 1; mask < (1 << faulty_nodes.size()); ++mask) {
            for (int first_node = 0; first_node < faulty_nodes.size(); ++first_node) {
                for (int number_tied = 0; number_tied < faulty_nodes.size(); ++number_tied) {
                    if (dp[mask][first_node][number_tied] > 0) {
                        for (int new_first = 0; new_first < faulty_nodes.size(); ++new_first) {
                            if ((mask & (1 << new_first)) == 0) {
                                int new_mask = mask ^ (1 << new_first);
                                int edge_exists = edge[make_pair(faulty_nodes[new_first], faulty_nodes[first_node])];
                                dp[new_mask][new_first][number_tied + edge_exists] = (dp[new_mask][new_first][number_tied + edge_exists] + dp[mask][first_node][number_tied]) % MOD;
                            }
                        }
                    }

                    if (mask == (1 << faulty_nodes.size()) - 1) {
                        lli val = dp[mask][first_node][number_tied];
                        lli get = (val * nCr(n - number_tied, faulty_nodes.size())) % MOD;
                        get = (get * fact[normal_nodes]) % MOD;

                        ans = (ans + get) % MOD;
                    }
                }
            }
        }

        if (m == 0)
            ans = fact[n];

        cout << ans << endl;
    }
    return 0;
}
