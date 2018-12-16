//
//  main.cpp
//  ROBOGAME
//
//  Created by Nirmaljot Singh Bhasin on 23/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 51;

bool vis[MAXN];

bool solve(string &s) {
    for (int i = 0; i < MAXN; ++i) {
        vis[i] = false;
    }
    lli n = s.length();
    for (lli i = 0; i < n; ++i) {
        if (s[i] != '.') {
            lli x = s[i] - '0';
            for (lli j = max(0ll, i - x); j <= min(n - 1, i + x); ++j) {
                if (vis[j]) {
                    return false;
                } else {
                    vis[j] = true;
                }
            }
        }
    }
    return true;
}

int main(int argc, const char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (solve(s)) {
            cout << "safe" << endl;
        } else {
            cout << "unsafe" << endl;
        }
    }
    return 0;
}
