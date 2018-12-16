/*input
2
3 7
1 1023
*/

//
//  main.cpp
//  VEGETA
//
//  Created by Nirmaljot Singh Bhasin on 12/06/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;
const int N = 1000006;

lli lp[N + 1];
vector<lli> pr;

void preprocess() {
	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back (i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j) {
			lp[i * pr[j]] = pr[j];
		}
	}
}

lli factorize(lli k) {
	lli cnt = 0;
	while (k > 1) {
		++cnt;
        lli f = lp[k];
		while (k % f == 0) {
			k /= f;
		}
	}
	return cnt;
}

int main(int argc, const char * argv[]) {
    preprocess();
	int t;
	cin >> t;
	while (t--) {
		int n , m;
		cin >> n >> m;
		lli cnt = 0;
		for (int i = n; i < m; ++i) {
			cnt += factorize(i);
		}
		cout << cnt << endl;
	}
	return 0;
}
