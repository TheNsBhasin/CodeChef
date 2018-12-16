//
//  main.cpp
//  CARDMGK
//
//  Created by Nirmaljot Singh Bhasin on 19/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli arr[MAXN];

int main(int argc, const char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        int j = 1;
        while (j < n) {
            if (arr[j - 1] > arr[j]) {
                break;
            }
            ++j;
        }
        if (j == n) {
            cout << "YES" << endl;
            continue;
        }

        bool flag = true;
        for (int i = j; i + 1 < n; ++i) {
            if (arr[i] > arr[i + 1]) {
                flag = false;
                break;
            }
        }

        flag &= arr[n - 1] <= arr[0];

        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
