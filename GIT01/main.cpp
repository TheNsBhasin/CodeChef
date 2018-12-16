/*input
2
4 5
RGRGR
GRGRG
RGRGR
GRGRG
2 3
RRG
GGR
*/

//
//  main.cpp
//  GIT01
//
//  Created by Nirmaljot Singh Bhasin on 01/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
    int t;
    int n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        string cake[n];
        for (int i = 0; i < n; ++i) {
            cin >> cake[i];
        }
        lli cost1 = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i + j) & 1) {
                    if (cake[i][j] != 'G') {
                        cost1 += 5;
                    }
                } else {
                    if (cake[i][j] != 'R') {
                        cost1 += 3;
                    }
                }
            }
        }
        lli cost2 = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i + j) & 1) {
                    if (cake[i][j] != 'R') {
                        cost2 += 3;
                    }
                } else {
                    if (cake[i][j] != 'G') {
                        cost2 += 5;
                    }
                }
            }
        }
        cout << min(cost1, cost2) << endl;
    }
    return 0;
}
