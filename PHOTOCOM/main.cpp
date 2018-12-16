/*input
2
1 2
01
2 1
01
2 2
0111
3 3
000000001
*/

//
//  main.cpp
//  PHOTOCOM
//
//  Created by Nirmaljot Singh Bhasin on 14/09/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <cstddef>
#include <utility>
using namespace std;

typedef long long int lli;
const int MAXN = 1000006;

lli gcd(lli a, lli b) {
	if (a == 0) {
		return b;
	}
	return gcd(b % a, a);
}

lli lcm(lli a, lli b) {
	return (a * b) / gcd(a, b);
}

std::string repeat(std::string str, const std::size_t n) {
	if (n == 0) {
		str.clear();
		str.shrink_to_fit();
		return str;
	} else if (n == 1 || str.empty()) {
		return str;
	}
	const auto period = str.size();
	if (period == 1) {
		str.append(n - 1, str.front());
		return str;
	}
	str.reserve(period * n);
	std::size_t m {2};
	for (; m < n; m *= 2) str += str;
	str.append(str.c_str(), (n - (m / 2)) * period);
	return str;
}

std::string operator*(std::string str, std::size_t n) {
	return repeat(std::move(str), n);
}

void scale(string &s, lli h, lli w, lli sh, lli sw) {
	int j = 0;
	string p = "";
	for (int i = 0; i < s.length(); ++i) {
		p += s.substr(i, 1) * (sw / w);
	}

	s = "";
	j = 0;
	for (int i = 0; i < p.length(); i += sw) {
		s += p.substr(i, sw) * (sh / h);
	}
}

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		lli h1, w1, h2, w2;
		string s1, s2;
		cin >> h1 >> w1;
		cin >> s1;
		cin >> h2 >> w2;
		cin >> s2;

		lli h = lcm(h1, h2);
		lli w = lcm(w1, w2);

		scale(s1, h1, w1, h, w);
		// cout << "s1 = " << s1 << endl;
		scale(s2, h2, w2, h, w);
		// cout << "s2 = " << s2 << endl;

		lli cnt = 0;
		for (int i = 0; i < s1.length(); ++i) {
			cnt += (s1[i] == s2[i]);
		}
		cout << cnt << endl;
	}
	return 0;
}
