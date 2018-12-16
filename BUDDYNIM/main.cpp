/*input
3
3 1
1 1 1
3
3 1
1 2 4
7
1 1
1
1
*/

//
//  main.cpp
//  BUDDYNIM
//
//  Created by Nirmaljot Singh Bhasin on 03/11/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;
const int MAXN = 102;

int main(int argc, const char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        lli sum1 = 0ll, sum2 = 0ll;
        vector<lli> v1, v2;
        for (int i = 0; i < n; ++i) {
            lli val;
            cin >> val;
            if (val != 0) {
                v1.push_back(val);
                sum1 += val;
            }
        }
        for (int i = 0; i < m; ++i) {
            lli val;
            cin >> val;
            if (val != 0) {
                v2.push_back(val);
                sum2 += val;
            }
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        bool flag = v1.size() == v2.size();

        for (int i = 0; flag && i < v1.size(); ++i) {
            if (v1[i] != v2[i]) {
                flag = false;
            }
        }

        if (flag || (!sum1 && !sum2)) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    }
    return 0;
}
