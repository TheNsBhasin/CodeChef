//
//  main.cpp
//  ARRGRAPH
//
//  Created by Nirmaljot Singh Bhasin on 19/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

typedef long long int lli;
const int MAXN = 51;
const int MAXP = 15;

lli prime[MAXP] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

bool hm[MAXN][MAXN];
lli a[MAXN];
bool vis[MAXN];
int n;

lli gcd(lli a, lli b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void preprocess() {
    memset(hm, 0, sizeof(hm));
    for (int i = 2; i < MAXN; ++i) {
        for (int j = i + 1; j < MAXN; ++j) {
            if (gcd(i, j) == 1) {
                hm[i][j] = hm[j][i] = 1;
            }
        }
    }
}

void dfs(lli u) {
    vis[u] = true;
    for (int i = 0; i < n; ++i) {
        if (hm[a[u]][a[i]] && !vis[i]) {
            dfs(i);
        }
    }
}

void solve() {
    memset(vis, false, sizeof(vis));
    dfs(0);
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << 0 << endl;
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    } else {
        cout << 1 << endl;
        for (int i = 0; i + 1 < n; ++i) {
            cout << a[i] << " ";
        }
        for (int k = 0; k < MAXP; ++k) {
            bool flag = true;
            for (int i = 0; i + 1 < n; ++i) {
                if (!hm[a[i]][prime[k]]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << prime[k] << endl;
                break;
            }
        }
    }
}

int main(int argc, const char *argv[]) {
    preprocess();
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        solve();
    }
    return 0;
}
