/*input
1
3 4
0011
0000
0100
*/

//
//  main.cpp
//  AVGMAT
//
//  Created by Nirmaljot Singh Bhasin on 19/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <utility>
#include <vector>
using namespace std;

typedef long long int lli;
const int MAXN = 302;
const int LEN = 602;

char arr[MAXN][MAXN];
lli rd[LEN], rdd[LEN], ld[LEN];
lli res[LEN];

int main(int argc, const char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        memset(res, 0, sizeof(res));
        memset(rd, 0, sizeof(rd));
        memset(rdd, 0, sizeof(rdd));
        memset(ld, 0, sizeof(ld));

        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (arr[i][j] == '1') {
                    rd[i + j]++;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < LEN; ++j) {
                rdd[j] = rd[j];
                ld[j] = 0;
            }

            for (int j = 0; j < m; ++j) {
                if (arr[i][j] == '1') {
                    for (int k = 0; k < LEN; ++k) {
                        res[k] += rdd[k];
                        res[k] += ld[k];
                    }
                }

                for (int k = i; k < n; ++k) {
                    if (arr[k][j] == '1') {
                        rdd[k - i]--;
                        if (k != i) {
                            ld[k - i]++;
                        }
                    }
                }

                for (int k = 0; k + 1 < LEN; ++k) {
                    rdd[k] = rdd[k + 1];
                    ld[LEN - 1 - k] = ld[LEN - 1 - k - 1];
                }
            }

            for (int j = 0; j < m; ++j) {
                if (arr[i][j] == '1') {
                    rd[j]--;
                }
            }

            for (int j = 0; j + 1 < LEN; ++j) {
                rd[j] = rd[j + 1];
            }
        }
        for (int i = 1; i < n + m - 1; ++i) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
