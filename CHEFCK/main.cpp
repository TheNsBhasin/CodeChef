/*input
4 2 1
1 1 1 1 1 1 1 1 1 100 1
1 1 1 3 1 1 1 2
*/

//
//  main.cpp
//  CHEFCK
//
//  Created by Nirmaljot Singh Bhasin on 20/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

typedef long long int lli;

const int MAXN = 10000007;
const int MOD = 1000000007;

lli N, K, Q;
lli A[MAXN], ans[MAXN];
lli a, b, c, d, e, f, r, s, t, m;
lli L1, La, Lc, Lm, D1, Da, Dc, Dm;
deque<lli> q;

int main(int argc, const char * argv[]) {
	cin >> N >> K >> Q;
	cin >> a >> b >> c >> d >> e >> f >> r >> s >> t >> m >> A[1];
	cin >> L1 >> La >> Lc >> Lm >> D1 >> Da >> Dc >> Dm;

	lli val = t;
	for (lli x = 2; x <= N; ++x) {
		val = (val * t) % s;
		if (val <= r) {
			A[x] = (a * A[x - 1] * A[x - 1] + b * A[x - 1] + c) % m;
		} else {
			A[x] = (d * A[x - 1] * A[x - 1] + e * A[x - 1] + f) % m;
		}
	}

	for (int i = 1; i <= N; ++i) {
		while (!q.empty() && q.back() > A[i]) {
			q.pop_back();
		}
		q.push_back(A[i]);
		if (i > K && q.front() == A[i - K]) {
			q.pop_front();
		}
		if (i >= K) {
			ans[i - K + 1] = q.front();
		}
	}

	lli sum = 0, prod = 1;

	for (lli i = 1; i <= Q; ++i) {
		L1 = (La * L1 + Lc) % Lm;
		D1 = (Da * D1 + Dc) % Dm;
		lli L = L1 + 1;
		lli R = min(L + K - 1 + D1, N);

		sum += min(ans[L], ans[R - K + 1]);
		prod = (prod * min(ans[L], ans[R - K + 1])) % MOD;
	}
	cout << sum << " " << prod << endl;
	return 0;
}
