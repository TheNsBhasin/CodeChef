/*input
2
krillinisdead
futuretrunks
*/

//
//  main.cpp
//  FRIEZA
//
//  Created by Nirmaljot Singh Bhasin on 12/06/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli a[MAXN];

int check(char ch) {
	if (ch == 'f' || ch == 'r' || ch == 'i' || ch == 'e' || ch == 'z' || ch == 'a') {
		return 1;
	}
	return 0;
}

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		lli cnt = 0;
		int i = 0;
		while (i < s.length()) {
			while (i < s.length() && check(s[i])) {
				++i;
				++cnt;
			}
			if (cnt > 0) {
				cout << cnt;
				cnt = 0;
			}
			while (i < s.length() && !check(s[i])) {
				++i;
				++cnt;
			}
			if (cnt > 0) {
				cout << cnt;
				cnt = 0;
			}
		}
		cout << endl;
	}
	return 0;
}
