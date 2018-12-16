/*input
2
6 0
1 1 1 1 1 1
5 1
2 4 6 3 4
*/

//
//  main.cpp
//  MTYFRI
//
//  Created by Nirmaljot Singh Bhasin on 11/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;
const int MAXN = 10004;

lli tomu[MAXN], motu[MAXN];

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		lli n , s;
		cin >> n >> s;
		lli sc_motu = 0, sc_tomu = 0;
		lli j = 0, k = 0;
		for (int i = 0; i < n; ++i) {
			if (i & 1) {
				cin >> tomu[j];
				sc_tomu += tomu[j++];
			} else {
				cin >> motu[k];
				sc_motu += motu[k++];
			}
		}
		sort(tomu, tomu + j);
		sort(motu, motu + k);
		lli idx1 = 0, idx2 = k - 1;
		while (s > 0 && idx1 < j && idx2 >= 0 && sc_tomu <= sc_motu) {
			sc_tomu -= tomu[idx1];
			sc_motu -= motu[idx2];
			sc_tomu += motu[idx2--];
			sc_motu += tomu[idx1++];
			--s;
		}
		if (sc_tomu > sc_motu) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
