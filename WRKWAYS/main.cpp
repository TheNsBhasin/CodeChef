/*input
1
2 12
*/

//
//  main.cpp
//  WRKWAYS
//
//  Created by Nirmaljot Singh Bhasin on 12/06/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

typedef long long int lli;
const int MAXN = 1000001;

vector<lli> facts;
lli ans[MAXN];
int n, c, ptr;

bool check(lli idx) {
	ptr = n;
	lli prod = c;
	while (ptr > 0) {
		while (prod % facts[idx] != 0) {
			--idx;
		}
		prod /= facts[idx];
		ans[ptr] = facts[idx] + ptr - 1;
		--ptr;
		if (idx < facts.size() && (facts[idx] == facts[idx + 1] - 1)) {
			++idx;
		}
		if (idx == 0 || prod == 1) {
			break;
		}
	}
	return prod == 1;
}

int main(int argc, const char * argv[]) {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> c;
		facts.clear();
		lli x = sqrt(c);
		for (int i = 1; i <= x; ++i) {
			if (c % i == 0) {
				facts.push_back(i);
				if (i * i != c) {
					facts.push_back(c / i);
				}
			}
		}
		sort(facts.begin(), facts.end());
		for (int i = 0; i < facts.size(); ++i) {
			if (check(i)) {
				break;
			}
		}
		for (int i = 1; i <= ptr; ++i) {
			cout << i << " ";
		}
		for (int i = ptr + 1; i <= n; ++i) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
