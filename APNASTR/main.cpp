/*input
3
1111
1001
1010
*/

//
//  main.cpp
//  APNASTR
//
//  Created by Nirmaljot Singh Bhasin on 02/09/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        string temp_str = str;
        int n = (int)str.length();
        int ct = 0;
        while (1) {
            rotate(str.begin(), str.begin() + 1, str.end());
            ct++;
            if (str == temp_str)
                break;
        }
        lli sum = 0;
        for (int i = 1;; ++i) {
            sum += i;
            if (sum % ct == 0) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
