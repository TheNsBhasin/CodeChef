/*input
3
3
1 3 2
4
4 1 2 1
6
1 2 2 2 2 1
*/

//
//  main.cpp
//  CHEFARRP1
//
//  Created by Nirmaljot Singh Bhasin on 04/11/17.
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
        cin >> n;
        lli arr[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        lli counter = 0;
        for (int i = 0; i < n; ++i) {
            lli prod = arr[i];
            lli sum = arr[i];
            for (int j = i + 1; j < n; ++j) {
                if (prod == sum) {
                    ++counter;
                }

                prod = prod * arr[j];
                sum = sum + arr[j];
            }
            if (prod == sum) {
                ++counter;
            }
        }
        cout << counter << endl;
    }
    return 0;
}
