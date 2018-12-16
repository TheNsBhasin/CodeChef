/*input
4
8 s
7 p
13 s
100 d
*/

//
//  main.cpp
//  SPDF
//
//  Created by Nirmaljot Singh Bhasin on 01/09/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int ll;
const int MAXN = 100005;

int main(int argc, const char * argv[]) {
    int  t;
    int arr[] = {8, 11, 14, 17};
    cin >> t;
    while (t--) {
        int n;
        ll ans = 0;
        char c;
        cin >> n >> c;
        if (n >= 5)
        {
            ans = n - 5;
            if (ans == 0)
            {
                if (c == 's') ans = 9;
            }
            else {
                if (c == 's') ans = arr[0] + ans * 4;
            }
            if (c == 'p') ans = arr[1] + ans * 4;
            if (c == 'd') ans = arr[2] + ans * 4;
            if (c == 'f') ans = arr[3] + ans * 4;
            cout << ans << endl;
        } else {
            if (n == 1)
                cout << 1;
            else if (n == 2) {
                if (c == 's')
                    cout << 2;
                if (c == 'p')
                    cout << 3;
            } else if (n == 3) {
                if (c == 's')
                    cout << 4;
                if (c == 'p')
                    cout << 5;
                if (c == 'd')
                    cout << 7;
            } else if (n == 4) {
                if (c == 's')
                    cout << 6;
                if (c == 'p')
                    cout << 8;
                if (c == 'd')
                    cout << 10;
                if (c == 'f')
                    cout << 13;
            }
            cout << endl;
        }
    }
    return 0;
}
