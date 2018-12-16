/*input
2
2 1
3 2
*/

//
//  main.cpp
//  CHN05
//
//  Created by Nirmaljot Singh Bhasin on 04/11/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;`
        if (n == 1) {
            cout << 0 <<endl;
        } else if(n == 2){
            cout << m << endl;
        } else {
            cout << n + (m << 1) - 3 << endl;
        }
    }
    return 0;
}
