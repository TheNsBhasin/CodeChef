/*input
abc
3
1 1
2 3
5 6
*/

//
//  main.cpp
//  KILLKTH
//
//  Created by Nirmaljot Singh Bhasin on 13/01/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef long long int lli;
const lli MAXN = (100005 << 1);

lli suffixArr[MAXN], lcp[MAXN];

struct suffix {
	lli index;
	lli rank[2];
};

int cmp(const struct suffix &a, const struct suffix &b) {
	return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1]) : (a.rank[0] < b.rank[0]);
}

void build(string str) {
	lli n = str.length();
	suffix suffixes[n];
	for (int i = 0; i < n; ++i) {
		suffixes[i].index = i;
		suffixes[i].rank[0] = str[i] - 'a';
		suffixes[i].rank[1] = ((i + 1) < n) ? (str[i + 1] - 'a') : -1;
	}
	sort(suffixes, suffixes + n, cmp);
	lli ind[n], invSuffix[n];
	for (int k = 4; k < (n << 1); k = (k << 1)) {
		lli rank = 0;
		lli prev_rank = suffixes[0].rank[0];
		suffixes[0].rank[0] = rank;
		ind[suffixes[0].index] = 0;
		for (int i = 1; i < n; ++i) {
			if (suffixes[i].rank[0] == prev_rank &&
			        suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = rank;
			} else {
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = ++rank;
			}
			ind[suffixes[i].index] = i;
		}
		for (int i = 0; i < n; ++i) {
			lli nextIndex = suffixes[i].index + (k >> 1);
			suffixes[i].rank[1] = (nextIndex < n) ? suffixes[ind[nextIndex]].rank[0] : -1;
		}
		sort(suffixes, suffixes + n, cmp);
	}
	for (int i = 0; i < n; ++i) {
		suffixArr[i] = suffixes[i].index;
		invSuffix[suffixArr[i]] = i;
	}
	lli k = 0;
	for (int i = 0; i < n; ++i) {
		if (invSuffix[i] == n - 1) {
			k = 0;
			continue;
		}
		lli j = suffixArr[invSuffix[i] + 1];
		while (i + k < n && j + k < n && str[i + k] == str[j + k]) {
			++k;
		}
		lcp[invSuffix[i]] = k;
		if (k > 0) {
			--k;
		}
	}
}

lli sumOfFirstN(lli n) {
	return ((n * (n + 1)) << 1);
}

char solve(string str, lli k) {
	lli n = str.length();
	for (int i = 0; i < n; ++i) {
		lli charToSkip = sumOfFirstN(n - suffixArr[i]);
		if (k <= charToSkip) {
			for (int j = 0; j <= (n - suffixArr[i]); ++j) {
				lli currSubstrLength = j;
				if (k <= currSubstrLength) {
					return str[(suffixArr[i] + k - 1)];
				} else {
					k = k - currSubstrLength;
				}
			}
		} else {
			k = k - charToSkip;
		}
	}
	return -1;
}

int main() {
	string str = "ababa";
	// lli q, g = 0;
	// cin >> str;
	// cin >> q;
	build(str);
	// while (q--) {
	// 	lli p, m;
	// 	cin >> p >> m;
	// 	lli k = (p * g) % m;
	// 	char ans = solve(str, k);
	// 	cout << ans << endl;
	// 	g += int(ans);
	// }
	for (int i = 1; i <= 25; ++i) {
		cout << solve(str, i);
	}
	return 0;
}