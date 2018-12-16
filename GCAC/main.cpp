/*input
1
5 6
5000 10000 3000 20 100
10000 2
800 2
600 1
10 8
1000 9
2000 10
111111
100000
000000
000001
100100
*/

//
//  main.cpp
//  GCAC
//
//  Created by Nirmaljot Singh Bhasin on 02/09/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef long long int lli;
const int MAXN = 1003;

int minSalary[MAXN], offeredSalary[MAXN], maxJobOffers[MAXN];
bool assigned[MAXN];
bool employed[MAXN];

void preprocess() {
    for (int i = 0; i < MAXN; i++) {
        assigned[i] = employed[i] = false;
    }
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        preprocess();
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> minSalary[i];
        }
        for (int j = 0; j < m; ++j) {
            cin >> offeredSalary[j] >> maxJobOffers[j];
        }
        int gotJob = 0;
        lli totalSalary = 0;
        int zeroEmploy = 0;
        string str;
        for (int i = 0; i < n; ++i) {
            int maxi = minSalary[i];
            int idx = -1;
            bool flag = false;
            cin >> str;
            for (int j = 0; j < m; ++j) {
                if (str[j] == '1' && offeredSalary[j] >= maxi && maxJobOffers[j] > 0) {
                    if (maxi == -1) {
                        maxi = offeredSalary[j];
                        idx = j;
                        flag = true;
                    } else if (offeredSalary[j] >= maxi && maxJobOffers[j] > 0) {
                        maxi = offeredSalary[j];
                        idx = j;
                        flag = true;
                    }
                }
            }
            if (flag) {
                assigned[i] = true;
                employed[idx] = true;
                --maxJobOffers[idx];
                ++gotJob;
                totalSalary += offeredSalary[idx];
            }
        }
        for (int j = 0; j < m; ++j) {
            if (!employed[j]) {
                ++zeroEmploy;
            }
        }
        cout << gotJob << " " << totalSalary << " " << zeroEmploy << endl;
    }
    return 0;
}
