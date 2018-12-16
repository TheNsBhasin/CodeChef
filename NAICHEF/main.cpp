/*input
2
5 1 1
1 1 1 1 1
2 1 1
1 2
*/

//
//  main.cpp
//  NAICHEF
//
//  Created by Nirmaljot Singh Bhasin on 03/06/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		double cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			if (x == a) {
				cnt1 += 1;
			}
			if (x == b) {
				cnt2 += 1;
			}
		}
		double probability = (cnt1 / n) * (cnt2 / n);
		cout << fixed << setprecision(6) << probability << endl;
	}
	return 0;
}
