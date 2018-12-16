/*input
1
3 7
1 2 4
*/

//
//  main.cpp
//  RNGOR
//
//  Created by Nirmaljot Singh Bhasin on 01/09/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAXN = 100005;
typedef long long int lli;

lli prefixXOR[MAXN], arr[MAXN];

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        lli counter = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] >= k) {
                counter += (n - i);
                continue;
            }
            int prefixXOR = arr[i];
            for (int j = i + 1; j < n; ++j) {
                prefixXOR |= arr[j];
                if (prefixXOR >= k) {
                    counter += (n - j);
                    break;
                }
            }
        }
        cout << counter << endl;
    }
    return 0;
}
