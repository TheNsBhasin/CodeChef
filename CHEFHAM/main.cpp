//
//  main.cpp
//  CHEFHAM
//
//  Created by Nirmaljot Singh Bhasin on 04/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        lli arr[n], ans[n];
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            ans[(i + 1) % n] = arr[i];
        }
        
        for (int i = 0; i < n; ++i) {
            if (arr[i] == ans[i]) {
                for (int j = 0; j < n; ++j) {
                    if(arr[j] != ans[i] && ans[j] != arr[i]) {
                        int x = ans[i];
                        ans[i] = ans[j];
                        ans[j] = x;
                        break;
                    }
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (arr[i] != ans[i]) {
                ++counter;
            }
        }
        
        cout << counter << endl;
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
