/*input
1
5 2
50 40 30 20 10
*/

//
//  main.cpp
//  CRISIS
//
//  Created by Nirmaljot Singh Bhasin on 04/04/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

typedef long long int lli;
const int MAXN = 1003;

lli s[MAXN];
bool v[MAXN];

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		lli X = -1, Y = 1;
		for (int i = 1; i <= n; ++i) {
			cin >> s[i];
			v[i] = false;
		}
		lli num = 0, den = 0;
		while (x--) {
			double maxi = 0;
			lli idx = -1;
			for (int i = 1; i <= n; ++i) {
				if (!v[i]) {
					double tmp = 1.0 * (num + i * s[i]) / (den + i);
					if (tmp > maxi) {
						idx = i;
						maxi = tmp;
					}
				}
			}
			v[idx] = true;
			num += (idx * s[idx]);
			den += idx;
		}
		cout << fixed << setprecision(9) << 1.0 * num / den << endl;
	}
	return 0;
}
