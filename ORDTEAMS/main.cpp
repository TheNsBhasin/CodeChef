/*input
3
1 2 3
2 3 4
2 3 5
1 2 3
2 3 4
2 3 4
5 6 5
1 2 3
2 3 4
*/

//
//  main.cpp
//  ORDTEAMS
//
//  Created by Nirmaljot Singh Bhasin on 05/11/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef long long int lli;

int main(int argc, const char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        vector<pair<lli, pair<lli, lli>>> v;
        for (int i = 0; i < 3; ++i) {
            lli H, I, P;
            cin >> H >> I >> P;
            v.push_back(make_pair(H, make_pair(I, P)));
        }

        sort(v.begin(), v.end());

        bool flag = false;
        if ((v[0].first <= v[1].first) &&
            ((v[0].second).first <= (v[1].second).first) &&
            ((v[0].second).second <= (v[1].second).second) &&
            (v[1].first <= v[2].first) &&
            ((v[1].second).first <= (v[2].second).first) &&
            ((v[1].second).second <= (v[2].second).second)) {
            if (((v[0].first < v[1].first) ||
                 ((v[0].second).first < (v[1].second).first) ||
                 ((v[0].second).second < (v[1].second).second)) &&
                ((v[1].first < v[2].first) ||
                 ((v[1].second).first < (v[2].second).first) ||
                 ((v[1].second).second < (v[2].second).second))) {
                flag = true;
            } else {
                flag = false;
            }
        } else {
            flag = false;
        }

        if (flag) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}
