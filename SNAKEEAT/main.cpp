/*input
2
5 2
21 9 5 8 10
10
15
5 1
1 2 3 4 5
100
*/

//
//  main.cpp
//  SNAKEEAT
//
//  Created by Nirmaljot Singh Bhasin on 31/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli L[MAXN], sum[MAXN];

int bs(int low, int high, lli val) {
    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        if (L[mid] >= val) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int solve(int low, int high, lli val) {
    int X = high;
    while (low < high) {
        int mid = low + ((high - low) >> 1);
        int len = X - mid;
        if (((val * len) - (sum[X] - sum[mid])) <= mid) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        for (int i = 0; i < n; ++i) {
            cin >> L[i];
        }
        sort(L, L + n);
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + L[i];
        }
        for (int i = 0; i < q; ++i) {
            lli k, cnt = 0;
            cin >> k;
            int pos = bs(0, n - 1, k);
            cout << n - solve(0, pos, k) << endl;
        }
    }
    return 0;
}
