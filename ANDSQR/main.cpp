/*input
1
3 2
1 2 3
2 2
1 3
*/

//
//  main.cpp
//  ANDSQR
//
//  Created by Nirmaljot Singh Bhasin on 13/09/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli arr[MAXN];

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		for (int i = 0; i < q; ++i) {
			lli cnt = 0;
			lli l, r;
			cin >> l >> r;
			--l;
			--r;
			lli siz = r - l + 1;
			for (int i = l; i <= r; ++i) {
				lli cur = (lli)(1 << 31) - 1;
				for (int j = i; j <= r; ++j) {
					cur &= arr[j];
					long double sr = sqrt(cur);
					if ((sr - floor(sr)) == 0) {
						++cnt;
					}
				}
			}

			cout << cnt << endl;
		}
	}
	return 0;
}
