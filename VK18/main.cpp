/*input
1
99876
*/

//
//  main.cpp
//  VK18
//
//  Created by Nirmaljot Singh Bhasin on 02/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAXN = 1000006;
typedef long long int lli;

lli f[MAXN << 1];
lli sum[MAXN << 1];
lli ans[MAXN];

void preprocess() {
    f[0] = sum[0] = 0;
    for (int i = 1; i < (MAXN << 1); ++i) {
        if ((i % 10) & 1) {
            f[i] = f[i / 10] - (i % 10);
        } else {
            f[i] = (i % 10) + f[i / 10];
        }
        sum[i] = sum[i - 1] + abs(f[i]);
    }

    ans[0] = 0;
    for (int i = 1; i < MAXN; ++i) {
        ans[i] = ans[i - 1] + ((sum[i << 1] - sum[i]) << 1) - abs(f[i << 1]);
    }
}

int main(int argc, const char * argv[]) {
    preprocess();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}
