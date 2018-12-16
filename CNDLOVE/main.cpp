/*input
1
2
5 2
*/

//
//  main.cpp
//  CNDLOVE
//
//  Created by Nirmaljot Singh Bhasin on 04/04/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 1003;

lli arr[MAXN];

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		lli sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			sum += arr[i];
		}
		--sum;
		if (sum & 1) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}
    return 0;
}
