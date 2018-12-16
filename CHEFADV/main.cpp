/*input
5
2 2 1 2
11 10 5 9
11 11 5 9
12 11 5 9
1 2 1 100
*/

//
//  main.cpp
//  CHEFADV
//
//  Created by Nirmaljot Singh Bhasin on 13/09/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

bool isSafe(lli n, lli x) {
	return ((n == 1) || ((n - 1) % x == 0));
}

bool fix(lli n, lli x) {
	if (n == 1) {
		return false;
	}
	return ((n == 2) || ((n - 2) % x == 0));
}

bool solve(lli n, lli m, lli x, lli y) {
	if (isSafe(n, x) && isSafe(m, y)) {
		return true;
	}

	if (fix(n, x) && fix(m, y)) {
		return true;
	}

	return false;
}

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		lli n, m, x, y;
		cin >> n >> m >> x >> y;
		cout << (solve(n, m, x, y) ? "Chefirnemo" : "Pofik") << endl;
	}
	return 0;
}
