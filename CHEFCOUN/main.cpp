/*input
10
99991
99992
99993
99994
99995
99996
99997
99998
99999
100000
*/

//
//  main.cpp
//  CHEFCOUN
//
//  Created by Nirmaljot Singh Bhasin on 06/10/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef unsigned long long int lli;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 99993 || n == 99995 || n == 99997 || n == 100000) {
            cout << "1000 ";
        } else {
            cout << "100000 ";
        }
        for (int i = 1; i < n; ++i) {
            if (n == 99998 || n == 99999) {
                cout << "42949 ";
            } else if (n == 99996 || n == 100000) {
                cout << "42950 ";
            } else if (n == 99994 || n == 99997) {
                cout << "42951 ";
            } else if (n == 99991 || n == 99992 || n == 99995) {
                cout << "42952 ";
            } else if (n == 99993) {
                cout << "42953 ";
            }
        }
        cout << endl;
    }
    return 0;
}
