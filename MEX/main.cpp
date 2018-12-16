/*input
5
3 100
101 101 103
3 1
1 0 2
4 3
2 5 4 9
4 3
1 1 1 4
4 0
1 2 0 1
*/

//
//  main.cpp
//  MEX
//
//  Created by Nirmaljot Singh Bhasin on 06/10/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200010;

int binarySearch(int arr[], int l, int r, int k) {
    while (l < r) {
        int m = l + (r - l) / 2;
        if (arr[m] > (m + k)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    int m = l + (r - l) / 2;
    if (arr[m] > (m + k)) {
        return m - 1;
    } else {
        return m;
    }
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        int size = 0;
        bool flag[MAXN];
        memset(flag, false, sizeof(flag));
        for (int i = 0; i < n; ++i) {
            int element;
            cin >> element;
            if (!flag[element]) {
                arr[size++] = element;
                flag[element] = true;
            }
        }
        sort(arr, arr + size);
        int idx = binarySearch(arr, 0, size - 1, k);
        if (idx < 0) {
            cout << k << endl;
        } else {
            int diff = arr[idx] - idx;
            cout << arr[idx] + 1 + (k - diff) << endl;
        }
    }
    return 0;
}
