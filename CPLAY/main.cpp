/*input
10100101111011111111
00000000000000000000
01011101110110101111
*/

//
//  main.cpp
//  CPLAY
//
//  Created by Nirmaljot Singh Bhasin on 01/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
    while (1) {
        string str;
        lli kicks = 0;
        cin >> str;

        if (str == "") {
            break;
        }

        lli team1 = 0, team2 = 0;

        for (int i = 0; i < 10; ++i) {
            ++kicks;
            if (str[i] == '1') {
                if (i & 1) {
                    ++team2;
                } else {
                    ++team1;
                }
            }
            if ((team1 > team2 + (10 - kicks + 1) / 2) || (team2 > team1 + (10 - kicks) / 2)) {
                break;
            }
        }

        if (team1 == team2) {
            for (int i = 10; i < 20; ++i) {
                ++kicks;
                if (str[i] == '1') {
                    if (i & 1) {
                        ++team2;
                    } else {
                        ++team1;
                    }
                }
                if (i & 1) {
                    if (team1 != team2) {
                        break;
                    }
                }
            }
        }

        if (team1 > team2) {
            cout << "TEAM-A " << kicks << endl;
        } else if (team1 < team2) {
            cout << "TEAM-B " << kicks << endl;
        } else {
            cout << "TIE" << endl;
        }
    }
    return 0;
}
