/*input
3
5 2
1 4 5 2 3
3 1
1 4 1
4 2
3 4 3 5
*/

//
//  main.cpp
//  CHEFMOVR
//
//  Created by Nirmaljot Singh Bhasin on 02/09/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAXN = 100005;
typedef long long int lli;
lli arr[MAXN];

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        lli total_sum = 0;
        bool flag = true;
        lli answer = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            total_sum += arr[i];
        }
        if (total_sum % n != 0) {
            flag = false;
        }
        lli final_number = total_sum / n;
        for (int i = 0; i < n - d; ++i) {
            if (arr[i] > final_number) {
                lli more = arr[i] - final_number;
                answer += more;
                arr[i + d] += more;
                arr[i] -= more;
            } else if (arr[i] < final_number) {
                lli less = final_number - arr[i];
                answer += less;
                arr[i + d] -= less;
                arr[i] += less;
            }
        }
        for (int i = 0; i < n && flag; ++i) {
            if (arr[i] != final_number) {
                flag = false;
            }
        }
        if (flag) {
            cout << answer << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
