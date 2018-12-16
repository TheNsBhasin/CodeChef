/*input
5
1
2
3
4
5
*/

//
//  main.cpp
//  ENIG10
//
//  Created by Nirmaljot Singh Bhasin on 04/04/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;
const int BITS = 17;

lli dp1[1 << BITS], dp2[1 << BITS];

void preprocess() {
	dp1[1] = dp2[1] = 1;
	for (int i = 2; i < (1 << BITS); i = i << 1) {
		for (int j = 0; j < i; ++j) {
			dp1[i + j] = i + dp1[i - 1 - j];
			dp2[i + dp1[i - 1 - j]] = i + j;
		}
	}

	for (int i = 0; i < 40; ++i) {
		cout << dp1[i] << " " << dp2[i] << endl;
	}
}

int main(int argc, const char * argv[]) {
	preprocess();
	int t;
	cin >> t;
	while (t--) {
		lli n;
		cin >> n;
		lli p = 0;
		for (int i = 0; i <= BITS; ++i) {
			if (n & (1 << i)) {
				n ^= (1 << i);
				lli s = dp2[p % (1 << i)];
				for (int j = 0; j < (1 << i); ++j) {
					p = dp1[s] + n;
					cout << dp1[s] + n << " ";
					++s;
					s %= (1 << i);
				}
			}
		}
		cout << endl;
	}
	return 0;
}
