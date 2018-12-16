/*input
1
5 2 4
4 2
3 4
3 2
1 2
*/

//
//  main.cpp
//  MAGICHF
//
//  Created by Nirmaljot Singh Bhasin on 13/09/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		lli n, x, s;
		cin >> n >> x >> s;
		for (int i = 0; i < s; ++i) {
			lli a, b;
			cin >> a >> b;
			if (a == x) {
				x = b;
			} else if (b == x) {
				x = a;
			}
		}
		cout << x << endl;
	}
	return 0;
}
