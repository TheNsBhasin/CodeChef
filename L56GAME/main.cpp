/*input
2
2
1 2
5
7 4 3 2 6
*/

//
//  main.cpp
//  L56GAME
//
//  Created by Nirmaljot Singh Bhasin on 27/01/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		lli arr[n];
		lli even = 0, odd = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			if ((arr[i] & 1)) {
				++odd;
			} else {
				++even;
			}
		}
		even += (odd >> 1);
		cout << ((odd & 1) ? 1 : 0) + (even ? 1 : 0) << endl;
	}
	return 0;
}
