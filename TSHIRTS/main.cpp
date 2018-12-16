/*input
2
2
3 5
8 100
3
5 100 1
2
5 100
*/

//
//  main.cpp
//  TSHIRTS
//
//  Created by Nirmaljot Singh Bhasin on 24/08/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <memory.h>
using namespace std;

typedef long long int lli;

const int NUM_TSHIRTS = 100;
const int NUM_PEOPLE = 10;
const int MOD = 1000000007;

vector<int> tshirts[NUM_TSHIRTS];
lli dp[1 << NUM_PEOPLE][NUM_TSHIRTS];
int n;

void preprocess() {
    for (int i = 0; i < NUM_TSHIRTS; ++i) {
        tshirts[i].clear();
    }
    memset(dp, -1, sizeof(dp));
}

lli solve(int mask, int id) {
    if (id == NUM_TSHIRTS) {
        return mask == ((1 << n) - 1);
    }
    if (dp[mask][id] != -1) {
        return dp[mask][id];
    }
    lli cnt = 0;
    for (int i = 0; i < tshirts[id].size(); ++i) {
        int person = (1 << tshirts[id][i]);
        if (!(mask & person)) {
            cnt = (cnt + solve(mask | person, id + 1) % MOD) % MOD;
        }
    }
    cnt = (cnt + solve(mask, id + 1) % MOD) % MOD;
    dp[mask][id] = cnt;
    return dp[mask][id];
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        preprocess();
        cin >> n;
        getchar();
        for (int i = 0; i < n; ++i) {
            string line;
            getline(cin, line);
            istringstream iss(line);
            int id;
            while (iss >> id) {
                --id;
                tshirts[id].push_back(i);
            }
        }
        cout << solve(0, 0) << endl;
    }
    return 0;
}
