/*input
1
1
*/

//
//  main.cpp
//  XDS
//
//  Created by Nirmaljot Singh Bhasin on 04/04/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		lli a = sqrt(n);
		lli b = ceil(sqrt(n));
		if (a * b < n) {
			++b;
		}
		lli diff = n - (a - 1) * b;
		while (--a) {
			cout << "X";
		}
		while (b--) {
			if (b < diff) {
				cout << "X";
				diff = 0;
			}
			cout << "D";
		}
		cout << endl;
	}
	return 0;
}
