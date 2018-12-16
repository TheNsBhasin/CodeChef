/*input
3
2
1 2
3
1 1 2
6
3 5 4 4 3 3
*/

//
//  main.cpp
//  CHEFLAPT
//
//  Created by Nirmaljot Singh Bhasin on 04/11/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (m.count(x) > 0) {
                ++m[x];
            } else {
                m[x] = 1;
            }
        }
        for(map<int, int> ::iterator it = m.begin(); it != m.end(); ++it) {
            if(it->second == 1) {
                cout << it->first << endl;
                break;
            }
        }
    }
    return 0;
}
