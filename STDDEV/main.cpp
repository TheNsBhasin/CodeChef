/*input
3
2 2
3 3
4 0
*/

//
//  main.cpp
//  STDDEV
//
//  Created by Nirmaljot Singh Bhasin on 05/11/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

typedef long long int ll;

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while (T--)
    {
        double n, rho;
        cin >> n >> rho;
        if ((n == 1 && rho != 0 ) || ( rho < 0 ))
            cout << -1 << endl;
        else
        {
            double ans = n * rho;
            if (n != 1)
                ans = ans  / sqrt(n - 1);
            for (int i = 0; i < n - 1; i++)
                cout << 0 << " ";
            printf("%.6lf\n", ans);
        }
    }
    return 0;
}
