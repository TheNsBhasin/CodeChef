/*input
3
1 3 2 1 2
1 5 2 1 2
1 5 3 2 2
*/

//
//  main.cpp
//  CHEFRUN
//
//  Created by Nirmaljot Singh Bhasin on 20/05/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	lli t;
	cin >> t;
	while (t--) {
		lli x1, x2, x3, v1, v2;
		cin >> x1 >> x2 >> x3 >> v1 >> v2;
		lli d1 = abs(x3 - x1);
		lli d2 = abs(x3 - x2);
		if (d1 * v2 < d2 * v1) {
			cout << "Chef" << endl;
		} else if (d1 * v2 > d2 * v1) {
			cout << "Kefa" << endl;
		} else {
			cout << "Draw" << endl;
		}
	}
	return 0;
}
