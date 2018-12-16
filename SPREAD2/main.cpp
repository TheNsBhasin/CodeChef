/*input
2
7
2 1 1 5 5 5 5
5
5 1 3 2 1
*/

//
//  main.cpp
//  SPREAD2
//
//  Created by Nirmaljot Singh Bhasin on 12/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli arr[MAXN];
lli sum[MAXN];

int main(int argc, const char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sum[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            sum[i] = arr[i] + sum[i - 1];
        }

        lli res = 0;
        lli i = 0;
        while (i + 1 < n) {
            ++res;
            i += sum[i];
        }

        cout << res << endl;
    }
    return 0;
}
