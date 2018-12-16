/*input
1
4 4
abab
baba
*/

//
//  main.cpp
//  STRMRG
//
//  Created by Nirmaljot Singh Bhasin on 05/01/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
using namespace std;

typedef long long int lli;
const int MAXN = 5001;

int n, m;
string A, B;
lli dp[MAXN][MAXN];

lli solve(lli ptr1, lli ptr2) {
	if (ptr1 >= n) {
		return m - ptr2;
	}
	if (ptr2 >= m) {
		return n - ptr1;
	}
	if (dp[ptr1][ptr2] != -1) {
		return dp[ptr1][ptr2];
	}
	if (A[ptr1] == B[ptr2]) {
		dp[ptr1][ptr2] = 1 + solve(ptr1 + 1, ptr2 + 1);
	} else {
		dp[ptr1][ptr2] = 1 + min(solve(ptr1 + 1, ptr2), solve(ptr1, ptr2 + 1));
	}
	return dp[ptr1][ptr2];
}

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		A.clear();
		B.clear();
		memset(dp, -1, sizeof(dp));
		cin >> n >> m;
		string str;
		cin >> str;
		A += str[0];
		for (int i = 1; i < n; ++i) {
			if (str[i] != str[i - 1]) {
				A += str[i];
			}
		}
		cin >> str;
		B += str[0];
		for (int i = 1; i < m; ++i) {
			if (str[i] != str[i - 1]) {
				B += str[i];
			}
		}
		n = A.length();
		m = B.length();
		cout << solve(0, 0) << endl;
	}
	return 0;
}
