/*input
4
*/

//
//  main.cpp
//  SQRGOOD
//
//  Created by Nirmaljot Singh Bhasin on 14/01/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

typedef long long int lli;
const int MAXN = 10000007;
map <lli, lli> m;
lli ans[10000007];

lli power(lli a, lli n) {
	lli ret = 1;
	while (n > 0) {
		if (n & 1) {
			ret = ret * a;
		}
		n = n >> 1;
		a = a * a;
	}
	return ret;
}

int main(int argc, const char * argv[]) {
	lli n;
	cin >> n;
	for (lli i = 2; i < MAXN; ++i) {
		lli val = i;
		lli j = 1;
		while (j * val > 0 & j * val < MAXN) {
			val = val * i;
			for (; j * val > 0 && j * val < MAXN; ++j) {
				m[val * j];
			}
		}
	}
	int i = 1;
	for (auto &p : m) {
		ans[i++] = p.first;
	}
	cout << ans[n] << endl;
	return 0;
}
