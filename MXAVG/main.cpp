/*input
2
3
1 1 1
8
6 7 7 5 7 7 7 6
*/

//
//  main.cpp
//  MXAVG
//
//  Created by Nirmaljot Singh Bhasin on 01/09/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <limits.h>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        lli arr[n];
        lli maxi = LONG_MIN;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            if (arr[i] > maxi) {
                maxi = arr[i];
            }
        }
        cout<<maxi<<endl;
    }
    return 0;
}
