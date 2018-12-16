/*input
6
3 100
10 1 100
3 100
11 1 100
3 100
10 1 10
3 100
10 1 50
4 100
50 50 50 50
4 100
1 1 1 1
*/

//
//  main.cpp
//  PERFCONT
//
//  Created by Nirmaljot Singh Bhasin on 06/10/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        lli p;
        cin >> n >> p;
        lli limit_hard = p / 10;
        lli limit_cakewalk = p / 2;
        int count_hard = 0;
        int count_cakewalk = 0;
        for (int i = 0; i < n; ++i) {
            lli solved;
            cin >> solved;
            if (solved <= limit_hard) {
                ++count_hard;
            }
            if (solved >= limit_cakewalk) {
                ++count_cakewalk;
            }
        }
        if (count_cakewalk == 1 && count_hard == 2) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}
