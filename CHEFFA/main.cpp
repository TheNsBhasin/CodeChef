/*input
3
3
2 3 1
2
2 2
3
1 2 3
*/

//
//  main.cpp
//  CHEFFA
//
//  Created by Nirmaljot Singh Bhasin on 02/09/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

typedef long long int lli;
const int MOD = 1e9 + 7;

lli dp[155][155][155];
int arr[155];
int n;

void preprocess() {
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < 61; ++i) {
        for (int j = 0; j < 155; ++j) {
            for (int k = 0; k < 155; ++k) {
                dp[i][j][k] = -1;
            }
        }
    }
}

lli solve(int pos, int curr, int next) {
    if (dp[pos][curr][next] != -1) {
        return dp[pos][curr][next] % MOD;
    }
    dp[pos][curr][next] = 0;
    int x = curr, y = next;
    int counter = 0;
    while (x >= 0 && y >= 0 ) {
        dp[pos][curr][next] = (dp[pos][curr][next] % MOD + solve(pos + 1, y, arr[pos + 2] + counter) % MOD) % MOD;
        --x;
        --y;
        ++counter;
    }
    return dp[pos][curr][next] % MOD;
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        preprocess();
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        dp[60][0][0] = 1;
        cout << solve(0, arr[0], arr[1]) << endl;
    }
    return 0;
}
