/*input
1
2
1 2
*/

//
//  main.cpp
//  XORAGN
//
//  Created by Nirmaljot Singh Bhasin on 11/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

const int MAXN = 100005;
typedef long long int lli;

lli arr[MAXN];

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		lli res = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			res ^= (arr[i] << 1);
		}
		cout << res << endl;
	}
	return 0;
}
