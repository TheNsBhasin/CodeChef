/*input
2
2 4
1 5
*/

// 111 110

//
//  main.cpp
//  BINSHFFL
//
//  Created by Nirmaljot Singh Bhasin on 03/06/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <bitset>
#include <limits.h>
#include <map>
using namespace std;

typedef long long int lli;
const int BITS = 64;

lli solve(lli a, lli b) {
	if (a == b) {
		return 0;
	}
	if (b == 1 && a == 0) {
		return 1;
	}
	if (b <= 1) {
		return -1;
	}

	if (a == b - 1) {
		return 1;
	}

	lli x = __builtin_popcountll(a);
	lli y = __builtin_popcountll(b - 1);

	if (x == y) {
		if (b > a) {
			return min(b - a, 1LL);
		}
		return 1;
	} else if (x < y) {
		if (b > a) {
			return min(b - a, (y - x) + 1);
		}
		return (y - x) + 1;
	}
	if (b > a) {
		return min(b - a, 2LL);
	}
	return 2;
}

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		lli a, b;
		cin >> a >> b;
		cout << solve(a, b) << endl;
	}
	return 0;
}
