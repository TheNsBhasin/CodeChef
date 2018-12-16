/*input
2
3 1
3 2
*/

//
//  main.cpp
//  COMPEXP
//
//  Created by Nirmaljot Singh Bhasin on 05/11/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iomanip>
#include <iostream>
using namespace std;

typedef long long int lli;

int main(int argc, const char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        double n, k;
        cin >> n >> k;
        double res = 2 * (n - ((n - 1) / k));
        cout << fixed << setprecision(6) << res << endl;
    }
    return 0;
}