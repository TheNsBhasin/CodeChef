/*input
11 12
*/

//
//  main.cpp
//  CHEFDIV
//
//  Created by Nirmaljot Singh Bhasin on 25/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100005;
const int RTN = 1000006;
typedef long long int lli;

vector<lli> primes;
vector<lli> pf[MAXN];
lli spf[RTN];
lli A, B;

lli solve(lli N) {
	lli x = N;
	lli ans = 1;
	priority_queue<lli> pq;

	for (int i = 0; i < pf[N - A].size() && x != 1; ++i) {
		lli cnt = 0;
		while (x % pf[N - A][i] == 0) {
			x = x / pf[N - A][i];
			++cnt;
		}
		pq.push(cnt + 1);
		ans = ans * (cnt + 1);
	}

	if (x != 1) {
		pq.push(2);
		ans = ans << 1;
	}

	lli cur = ans;
	ans = 0;
	while (!pq.empty()) {
		ans = ans + cur;
		lli highest_freq = pq.top();
		pq.pop();
		cur = cur / highest_freq;
		cur = cur * (highest_freq - 1);
		if (highest_freq > 2) {
			pq.push(highest_freq - 1);
		}
	}
	return ans;
}

int main(int argc, const char * argv[]) {
	cin >> A >> B;

	for (int i = 2; i < RTN; ++i) {
		if (!spf[i]) {
			spf[i] = i;
			primes.push_back(i);
			for (lli j = ((A - 1) - (A - 1) % i) + i; j <= B; j = j + i) {
				pf[j - A].push_back(i);
			}
		}
		for (int j = 0; j < primes.size() && primes[j] <= spf[i] && i * primes[j] < RTN; ++j) {
			spf[i * primes[j]] = primes[j];
		}
	}

	lli total = 0;
	for (lli j = A; j <= B; ++j) {
		total = total + solve(j);
	}
	cout << total << endl;

	return 0;
}
