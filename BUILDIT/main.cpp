/*input
3
5
3
2
1 3 5
1 1
1 1
*/

//
//  main.cpp
//  BUILDIT
//
//  Created by Nirmaljot Singh Bhasin on 09/06/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <random>
#include <time.h>
#include <fstream>
using namespace std;

typedef long long int lli;

const int MOD = 163577857;
const int MAXN = 50005;
const int MAXK = 105;
const int LNH = 31;

lli p[MAXN];
lli a[MAXK], sum[MAXK], s[MAXK];
lli c[LNH][MAXK][MAXK];
lli N, H, X, K;

lli power(lli x, lli y) {
	lli res = 1;
	x = x % MOD;
	while (y > 0) {
		if (y & 1) {
			res = (res * x) % MOD;
		}
		y = y >> 1;
		x = (x * x) % MOD;
	}
	return res;
}

lli get(lli x) {
	for (int i = 0; i <= K; ++i) {
		sum[i] = a[i];
	}
	for (int pw = 0; pw < LNH; ++pw) {
		if ((x >> pw) & 1) {
			for (int i = 0; i <= K; ++i) {
				s[i] = 0;
			}
			for (int i = 0; i <= K; ++i) {
				for (int j = 0; j <= K; ++j) {
					s[j] = (s[j] + (sum[i] * c[pw][i][j]) % MOD) % MOD;
				}
			}
			for (int i = 0; i <= K; ++i) {
				sum[i] = s[i] % MOD;
			}
		}
	}
	return sum[K];
}

lli solve() {
	lli all = get(H);
	lli tot = 0;
	for (int i = 0; i < N; ++i) {
		if (p[i] >= X) {
			tot = (tot + (MOD + get(p[i]) - get(p[i] - X)) % MOD) % MOD;
		} else {
			tot = (tot + (get(p[i]) + (MOD + all - get(p[i] - X + H)) % MOD) % MOD) % MOD;
		}
	}
	return (tot * power(all, MOD - 2)) % MOD;
}

int main(int argc, const char * argv[]) {
	cin >> N >> H >> X >> K;
	for (lli i = 0; i < N; ++i) {
		cin >> p[i];
	}
	for (lli i = 0; i < K; ++i) {
		cin >> a[i];
		a[i] = a[i] % MOD;
	}
	for (int i = 1; i < K; ++i) {
		c[0][i][i - 1] = 1;
	}

	for (int i = 0; i < K; ++i) {
		cin >> c[0][K - i - 1][K - 1];
		c[0][K - i - 1][K - 1] = c[0][K - i - 1][K - 1] % MOD;
	}
	c[0][K][K] = c[0][0][K] = 1;

	for (int i = 1; i < LNH; ++i) {
		for (int z = 0; z <= K; ++z) {
			for (int x = 0; x <= K; ++x) {
				for (int y = 0; y <= K; ++y) {
					c[i][x][y] = (c[i][x][y] + (c[i - 1][x][z] * c[i - 1][z][y]) % MOD) % MOD;
				}
			}
		}
	}
	lli res = solve();
	cout << res << endl;
	return 0;
}
