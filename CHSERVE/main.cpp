//
//  main.cpp
//  CHSERVE
//
//  Created by Nirmaljot Singh Bhasin on 16/10/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

int main(int argc, const char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        lli p1, p2, k;
        cin >> p1 >> p2 >> k;
        cout << (((p1 + p2) / k) % 2 ? "COOK" : "CHEF") << endl;
    }
    return 0;
}
