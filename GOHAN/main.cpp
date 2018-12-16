/*input
2
4 5 78 60
4 5 6 3
*/

//
//  main.cpp
//  GOHAN
//
//  Created by Nirmaljot Singh Bhasin on 12/06/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		long double R, L, C, Vin;
		cin >> R >> L >> C >> Vin;
		long double ans = (R * R * C);
		ans = (ans / (4 * L));
		ans = 1 - ans;
		cout << fixed << setprecision(6) << ans << endl;
	}
	return 0;
}
