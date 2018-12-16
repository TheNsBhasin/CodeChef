//
//  main.cpp
//  TYPING
//
//  Created by Nirmaljot Singh Bhasin on 19/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

typedef long long int lli;
const int MAXN = 102;

string str[MAXN];
map<char, bool> mp;
map<string, lli> hm;

int main(int argc, const char *argv[]) {
    int t;
    cin >> t;
    mp['d'] = true;
    mp['f'] = true;
    mp['j'] = false;
    mp['k'] = false;
    while (t--) {
        hm.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> str[i];
        }

        lli res = 0;
        for (int i = 0; i < n; ++i) {
            if (hm.find(str[i]) != hm.end()) {
                res += (hm[str[i]] >> 1);
                continue;
            }
            lli cur = 2;
            bool flag = mp[str[i][0]];
            for (int j = 1; j < str[i].length(); ++j) {
                if (mp[str[i][j - 1]] ^ mp[str[i][j]]) {
                    cur += 2;
                    // cout << str[i][j] << " " << 2 << endl;
                } else {
                    cur += 4;
                    // cout << str[i][j] << " " << 4 << endl;
                }
            }
            // cout << str[i] << " -> " << cur << endl;
            res += cur;
            hm[str[i]] = cur;
        }

        cout << res << endl;
    }
    return 0;
}
