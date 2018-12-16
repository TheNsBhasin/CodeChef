/*input
2
4 4
6 5
*/

//
//  main.cpp
//  REMAIN
//
//  Created by Nirmaljot Singh Bhasin on 27/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		lli n, m;
		cin >> n >> m;
		if ((n % m) & 1) {
			cout << "ODD" << endl;
		} else {
			cout << "EVEN" << endl;
		}
	}
	return 0;
}
