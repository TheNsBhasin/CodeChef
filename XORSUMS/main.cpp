/*input
6
11 4 4 13 11 5
*/

//
//  main.cpp
//  XORSUMS
//
//  Created by Nirmaljot Singh Bhasin on 25/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

typedef long long int lli;
const int MAXN = 1 << 25;
const int NUM_BIT = 25;

lli bit[MAXN];

void update(lli idx, lli val) {
	idx = idx + 1;
	while (idx > 0 && idx <= MAXN) {
		bit[idx] += val;
		idx += (idx & (-idx));
	}
}

lli query(lli idx) {
	if (idx <= 0) {
		return 0;
	}
	if (idx > MAXN) {
		idx = MAXN;
	}
	lli sum = 0;
	while (idx > 0) {
		sum += bit[idx];
		idx -= (idx & (-idx));
	}
	return sum;
}

lli query(lli L, lli R) {
	if (L > R) {
		return 0;
	}
	return query(R + 1) - query(L);
}

int main(int argc, const char * argv[]) {
	int n;
	cin >> n;
	vector<lli> pref;
	pref.push_back(0);
	for (int i = 0; i < n; ++i) {
		lli x;
		cin >> x;
		pref.push_back(pref.back() + x);
	}
	lli ans = 0;
	for (int b = 0; b < NUM_BIT; ++b) {
		lli cnt = 0;
		lli half = (1 << b);
		lli mod = ((half << 1) - 1);
		for (auto sum : pref) {
			sum = sum & mod;
			cnt += query(0, sum - half);
			cnt += query(sum + 1, sum + half);
			update(sum, 1);
		}
		ans |= ((cnt & 1) << b);
		for (auto sum : pref) {
			update(sum & mod, -1);
		}
	}
	cout << ans << endl;
	return 0;
}
