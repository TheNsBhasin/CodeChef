/*input
3
5 2
7 2
127 1
*/

//
//  main.cpp
//  ABX01
//
//  Created by Nirmaljot Singh Bhasin on 30/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

typedef unsigned long long int lli;

lli power(lli A, lli N) {
	if (N == 0) {
		return 1;
	}
	if (N == 1) {
		return A;
	}
	lli p = power(A, N >> 1);
	if (N & 1) {
		return p * A * p;
	} else {
		return p * p;
	}
}

lli sumOfDigits(lli val) {
	lli cnt = 0;
	while (val > 0) {
		cnt += val % 10;
		val = val / 10;
	}
	return cnt;
}

lli F(lli val) {
	if ((val / 10) == 0) {
		return val;
	} else {
		return F(sumOfDigits(val));
	}
}

lli solve(lli A, lli N) {
	if (N == 0) {
		return 0;
	}
	if (N == 1) {
		return F(A);
	}
	lli p = solve(F(A), N >> 1);
	if (N & 1) {
		return F(p * F(A) * p);
	} else {
		return F(p * p);
	}
}

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		lli A, N;
		cin >> A >> N;
		cout << solve(A, N) << endl;
	}
	return 0;
}
