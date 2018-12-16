/*input
1
2 3
*/

//
//  main.cpp
//  KMXOR
//
//  Created by Nirmaljot Singh Bhasin on 20/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

typedef long long int lli;
const int MAXN = 10004;

lli ans[MAXN];

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		lli n, k;
		cin >> n >> k;
		lli x = (1 << lli(log2(k) + 1)) - 1;
		if (n == 1) {
			cout << k << endl;
			continue;
		}
		if (k == 1) {
			for (int i = 0; i < n; ++i) {
				cout << k << " ";
			}
			cout << endl;
			continue;
		}
		if (n & 1) {
			if (k < 3) {
				for (int i = 0; i < n; ++i) {
					cout << k << " ";
				}
				cout << endl;
				continue;
			}
			lli a, b, c;
			bool flag = true;
			for (int i = k; i > 0 && flag; --i) {
				a = i;
				for (int j = i - 1; j > 0 && flag; --j) {
					b = j;
					c = x ^ a ^ b;
					if (c > 0 && c <= k) {
						flag = false;
						break;
					}
				}
			}
			cout << a << " " << b << " " << c << " ";
			for (int i = 0; i < n - 3; ++i) {
				cout << k << " ";
			}
		} else {
			lli a, b;
			for (int i = k; i > 0; --i) {
				a = i;
				if ((x ^ a) > 0 && (x ^ a) <= k) {
					b = x ^ a;
					break;
				}
			}
			cout << a << " " << b << " ";
			for (int i = 0; i < n - 2; ++i) {
				cout << k << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
