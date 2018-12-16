/*input
5
1 2 3 4 5
5
1 1
2 2
3 3
4 4
5 5
*/

//
//  main.cpp
//  MONSTER
//
//  Created by Nirmaljot Singh Bhasin on 06/01/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <memory.h>
using namespace std;

typedef long long int lli;
const int MAXN = (1 << 18) + 1;
const int BITS = 18;
const int N = (1 << 17) + 1;
const int MASK = (1 << 17) - 1;
const lli MAXH = 1e9 + 7;
lli ans[MAXN], arr[N], query[MAXN][2];
lli bitmask[MAXN];

int main(int argc, const char * argv[]) {
	int n, q;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> query[i][0] >> query[i][1];
		query[i][0] &= MASK;
	}

	lli blk_sz = 1000;
	lli total_blk = (q / blk_sz) + 1;
	lli idx = 0;
	lli tmp;
	for (int blk = 0; blk < total_blk; ++blk) {
		memset(bitmask, 0, sizeof(bitmask));
		tmp = idx;
		for (int i = 0; (i < blk_sz) && (idx < q); ++i, ++idx) {
			bitmask[query[idx][0]] += query[idx][1];
		}
		for (int bit = 0; bit < BITS; ++bit) {
			for (int i = MASK; i >= 0; --i) {
				if (!((i >> bit) & 1)) {
					bitmask[i] += bitmask[i ^ (1 << bit)];
					bitmask[i] = min(bitmask[i], MAXH);
				}
			}
		}
		lli pos = tmp;
		for (int i = 0; i < N; ++i) {
			if (arr[i] <= 0) {
				continue;
			}
			arr[i] -= bitmask[i];
			if (arr[i] > 0) {
				continue;
			}
			lli curr = 0;
			tmp = pos;
			for (int j = 0; (j < blk_sz) && (tmp < q); ++j, ++tmp) {
				if ((i & query[tmp][0]) == i) {
					curr += query[tmp][1];
				}
				if ((bitmask[i] + arr[i]) - curr <= 0) {
					++ans[tmp];
					break;
				}
			}
		}
	}
	lli alive = n;
	for (int i = 0; i < q; ++i) {
		alive = alive - ans[i];
		cout << alive << endl;
	}
	return 0;
}
