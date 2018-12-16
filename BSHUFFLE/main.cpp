/*input
5
*/

//
//  main.cpp
//  BSHUFFLE
//
//  Created by Nirmaljot Singh Bhasin on 13/09/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

typedef long long int lli;

void solve(lli n) {
	if (n == 1) {
		cout << "1" << endl << "1" << endl;
		return;
	} else if (n == 2) {
		cout << "1 2" << endl;
		cout << "1 2" << endl;
		return;
	}

	int mid = floor(n / 2);

	for (int i = 2; i <= mid; ++i) {
		cout << i << " ";
	}

	cout << 1 << " ";

	for (int i = mid + 2; i <= n; ++i) {
		cout << i << " ";
	}
	cout << mid + 1 << endl;

	cout << n << " ";
	for (int i = 1; i < n; ++i) {
		cout << i << " ";
	}
	cout << endl;
}

int main(int argc, const char * argv[]) {
	lli n;
	cin >> n;
	solve(n);
	return 0;
}
