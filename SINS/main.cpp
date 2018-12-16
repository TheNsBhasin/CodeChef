/*input
3
5 3
10 10
4 8
*/

//
//  main.cpp
//  SINS
//
//  Created by Nirmaljot Singh Bhasin on 04/04/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

lli gcd(lli a, lli b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		lli g = gcd(x, y);
		cout << (g << 1) << endl;
	}
    return 0;
}
