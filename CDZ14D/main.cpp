/*input
1
10 2 2
1 10
5 5
*/

//
//  main.cpp
//  CDZ14D
//
//  Created by Nirmaljot Singh Bhasin on 04/03/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

typedef long long int lli;

vector<lli> pf;

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		pf.clear();
		lli n, x, m;
		cin >> n >> x >> m;
		if (n % x) {
			for (int i = 0; i < m; ++i) {
				lli l, r;
				cin >> l >> r;
				cout << 0 << endl;
			}
			continue;
		}
		n = n / x;
		lli tmp = n;
		for (int j = 2; j * j <= tmp; ++j) {
			if (tmp % j == 0) {
				pf.push_back(j);
				while (tmp % j == 0) {
					tmp /= j;
				}
			}
		}
		if (tmp > 1) {
			pf.push_back(tmp);
		}
		for (int i = 0; i < m; ++i) {
			lli l, r;
			lli ans = 0;
			cin >> l >> r;
			--l;
			l /= x;
			r /= x;
			for (int mask = 0; mask < (1 << pf.size()); ++mask) {
				lli prod = 1;
				for (int j = 0; j < pf.size(); ++j) {
					if ((mask >> j) & 1) {
						prod *= pf[j];
					}
				}
				if (__builtin_popcount(mask) % 2) {
					ans -= (r / prod);
					ans += (l / prod);
				} else {
					ans += (r / prod);
					ans -= (l / prod);
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
