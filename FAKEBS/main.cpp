/*input
1
7 7
3 1 6 7 2 5 4
1
2
3
4
5
6
7
*/

//
//  main.cpp
//  FAKEBS
//
//  Created by Nirmaljot Singh Bhasin on 06/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli n, q;
lli arr[MAXN], s[MAXN], gre[MAXN];
map <lli, lli> m;

lli solve(lli x) {
	lli low = 0, high = n - 1;
	lli idx = m[x];
	lli tot_ge = 0, tot_le = 0;
	lli ge = 0, le = 0;
	while (low <= high) {
		lli mid = low + ((high - low) >> 1);
		if (mid == idx) {
			break;
		} else if (mid < idx) {
			++tot_le;
			low = mid + 1;
			if (arr[mid] > x) {
				++le;
			}
		} else {
			++tot_ge;
			high = mid - 1;
			if (arr[mid] < x) {
				++ge;
			}
		}
	}
	// cout << "> " << x << ": " << gre[idx] << " [" << tot_ge << "]" << endl;
	// cout << "< " << x << ": " << n - gre[idx] - 1 << " [" << tot_le << "]" << endl;
	if ((gre[idx] < tot_ge) || (n - gre[idx] - 1 < tot_le)) {
		return -1;
	}
	return le + ge - min(le, ge);
}

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> q;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			m[arr[i]] = i;
			s[i] = arr[i];
		}
		sort(s, s + n);
		for (int i = 0; i < n; ++i) {
			// cout << s[i] << " ";
			gre[m[s[i]]] = n - i - 1;
		}
		// cout << endl;
		for (int i = 0; i < q; ++i) {
			lli x;
			cin >> x;
			// cout << x << ": ";
			lli ans = solve(x);
			// cout << "Answer: ";
			cout << ans << endl;
			// cout << endl;
		}
	}
	return 0;
}
