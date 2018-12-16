/*input
2
5
2 4 8 1 3
10
2 4 8 1 3 6 4 25 6 2
*/

//
//  main.cpp
//  XORIER
//
//  Created by Nirmaljot Singh Bhasin on 13/09/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;
const int N = 1000006;

lli arr[MAXN];
map<lli, lli> hm;

lli naive(lli n) {
	lli cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if ((arr[i] ^ arr[j]) % 2 == 0 && (arr[i] ^ arr[j]) > 2) {
				++cnt;
				cout << "(" << arr[i] << " " << arr[j] << ")" << endl;
			}
		}
	}

	return cnt;
}

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		hm.clear();
		int n;
		cin >> n;
		lli odd = 0, even = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			hm[arr[i]]++;

			if (arr[i] & 1) {
				++odd;
			} else {
				++even;
			}
		}

		// cout << naive(n) << endl;

		lli cnt = ((even * (even - 1)) >> 1) + ((odd * (odd - 1)) >> 1);

		for (auto &p : hm) {
			lli x = p.first;
			lli val = p.second;

			if (val > 1) {
				cnt -= ((val * (val - 1)) >> 1);
			}

			if ((x ^ 2) > x && (hm.find(x ^ 2) != hm.end())) {
				cnt -= (val * hm[x ^ 2]);
			}
		}

		cout << cnt << endl;
	}
	return 0;
}
