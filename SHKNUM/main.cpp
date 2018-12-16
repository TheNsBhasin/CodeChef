/*input
3
10
22
4
*/

//
//  main.cpp
//  SHKNUM
//
//  Created by Nirmaljot Singh Bhasin on 12/08/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <limits.h>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		lli n;
		cin >> n;
		lli res = LONG_MAX;

		for (int x = 0; x < 32; ++x) {
			for (int y = 0; y < 32; ++y) {
				if (x != y) {
					lli m = (1 << x) + (1 << y);
					res = min(res, abs(n - m));
				}
			}
		}

		cout << res << endl;
	}
	return 0;
}
