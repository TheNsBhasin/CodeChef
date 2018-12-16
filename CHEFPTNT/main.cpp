/*input
2
4 4 2 4
EEOO
4 3 1 4
EEOO
*/

//
//  main.cpp
//  CHEFPTNT
//
//  Created by Nirmaljot Singh Bhasin on 03/02/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		lli N, M, X, K;
		cin >> N >> M >> X >> K;
		string str;
		cin >> str;
		lli even = 0, odd = 0;
		for (int i = 0; i < str.length(); ++i) {
			if (str[i] == 'E') {
				++even;
			} else {
				++odd;
			}
		}
		lli done = 0;
		for (int i = 1; i <= M && done < N; ++i) {
			if (i & 1) {
				if (odd > 0) {
					done += min(odd, X);
					odd -= min(odd, X);
				}
			} else {
				if (even > 0) {
					done += min(even, X);
					even -= min(even, X);
				}
			}
		}
		if (done >= N) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
	return 0;
}
