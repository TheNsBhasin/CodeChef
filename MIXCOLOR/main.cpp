/*input
1
9
1 1 1 1 2 2 2 3 4
*/

//
//  main.cpp
//  MIXCOLOR
//
//  Created by Nirmaljot Singh Bhasin on 02/03/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

lli arr[MAXN];
unordered_map<lli, lli> freq;

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		freq.clear();
		int n;
		cin >> n;
		lli maxi = -1, cnt = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			if (freq.count(arr[i])) {
				++freq[arr[i]];
			} else {
				freq[arr[i]] = 1;
			}
			if (arr[i] > maxi) {
				maxi = arr[i];
			}
		}
		for (int i = 0; i < n; ++i) {
			while (freq[arr[i]] > 1) {
				freq[arr[i] + maxi] = 1;
				maxi = arr[i] + maxi;
				--freq[arr[i]];
				++cnt;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
