/*input
3
ab
ab
aba
cde
ab
cd
*/

//
//  main.cpp
//  PALINGAM
//
//  Created by Nirmaljot Singh Bhasin on 02/09/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;
        int A[26], B[26];
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        for (int i = 0; s[i] && t[i]; ++i) {
            ++A[s[i] - 'a'];
            ++B[t[i] - 'a'];
        }
        bool unique_A = false;
        bool unique_B = false;
        bool flag = false;
        for (int i = 0; i < 26; ++i) {
            if (A[i] && !B[i]) {
                unique_A = true;
                if (A[i] > 1) {
                    flag = true;
                    break;
                }
            }
            if (!A[i] && B[i]) {
                unique_B = true;
            }
        }
        if (flag || (unique_A && !unique_B)) {
            cout << "A" << endl;
        } else {
            cout << "B" << endl;
        }
    }
    return 0;
}
