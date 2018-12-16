/*input
5 4
3 1 8 9 7
2 1 5
1 2 12
2 1 3
2 2 5
*/

//
//  main.cpp
//  PSHTRG
//
//  Created by Nirmaljot Singh Bhasin on 03/03/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

struct node {
	lli val, pos;

	node() {
		val = LONG_MIN;
		pos = -1;
	}
};

node max(node & a, node & b) {
	if (a.val > b.val) {
		return a;
	}
	return b;
}

node tree[MAXN << 1];
node res[MAXN];
int n, q;

void build() {
	for (int i = n - 1; i >= 0; --i) {
		tree[i] = max(tree[(i << 1)], tree[(i << 1) | 1]);
	}
}

void update(lli idx, lli x) {
	idx += n;
	tree[idx].val = x;
	while (idx > 1) {
		tree[idx >> 1] = max(tree[idx], tree[idx ^ 1]);
		idx = (idx >> 1);
	}
}

node query(lli l, lli r) {
	node res;
	l += n; r += n;
	while (l <= r) {
		if (l & 1) {
			res = max(res, tree[l++]);
		}
		if (!(r & 1)) {
			res = max(res, tree[r--]);
		}
		l = l >> 1;
		r = r >> 1;
	}
	return res;
}

int main(int argc, const char * argv[]) {
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> tree[i + n].val;
		tree[i + n].pos = i;
	}
	build();
	while (q--) {
		lli ty;
		cin >> ty;
		if (ty == 1) {
			lli pos, val;
			cin >> pos >> val;
			--pos;
			update(pos, val);
		} else {
			lli l, r;
			cin >> l >> r;
			--l; --r;
			lli siz = r - l + 1;
			if (siz < 3) {
				cout << 0 << endl;
				continue;
			}
			lli ans = 0;
			lli idx = -1;

			while (idx < siz) {
				res[++idx] = query(l, r);
				if (res[idx].val != LONG_MIN) {
					update(res[idx].pos, LONG_MIN);
				} else {
					--idx;
					break;
				}
				if (idx >= 2) {
					if (res[idx - 2].val < res[idx - 1].val + res[idx].val) {
						ans = res[idx - 2].val + res[idx - 1].val + res[idx].val;
						break;
					}
				}
			}
			for (int i = idx; i >= 0; --i) {
				update(res[i].pos, res[i].val);
			}
			cout << ans << endl;
		}
	}
	return 0;
}