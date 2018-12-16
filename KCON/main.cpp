/*input
3
2 3
1 2
3 2
1 -2 1
3 2
-1 1 -2
*/

//
//  main.cpp
//  KCON
//
//  Created by Nirmaljot Singh Bhasin on 05/01/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <climits>
#include <memory.h>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli arr[MAXN];

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		lli sum = 0;
		cin >> n >> k;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			sum += arr[i];
		}

		lli max_prefix = LONG_MIN, max_postfix = LONG_MIN;
		lli pre = 0, post = 0;

		for (int i = 1; i <= n; ++i) {
			pre += arr[i - 1];
			max_prefix = max(max_prefix, pre);
		}
		for (int i = n - 1; i >= 0; --i) {
			post += arr[i];
			max_postfix = max(max_postfix, post);
		}

		lli max_so_far = LONG_MIN, max_ending_here = 0;

		for (int i = 0; i < n; ++i) {
			max_ending_here += arr[i];
			if (max_so_far < max_ending_here) {
				max_so_far = max_ending_here;
			}

			if (max_ending_here < 0) {
				max_ending_here = 0;
			}
		}

		lli maxi = LONG_MIN;

		if (k > 1) {
			maxi = max(max_postfix + max_prefix, (max_postfix + (sum * (k - 2)) + max_prefix));
		}

		cout << max(max_so_far, maxi) << endl;
	}
	return 0;
}
