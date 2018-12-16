/*input
2
3
2 3 4
2 5 5
2
3 2
2 1 1
*/

//
//  main.cpp
//  CARPTUN
//
//  Created by Nirmaljot Singh Bhasin on 02/02/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	cout.precision(9);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long double A[n];
		for (int i = 0; i < n; ++i) {
			cin >> A[i];
		}
		lli cars, dist, speed;
		cin >> cars >> dist >> speed;
		long double lag = 0;
		for (int i = 0; i < n; ++i) {
			lag += (A[i] - lag) > 0 ? (A[i] - lag) : 0;
		}
		cout << fixed << (cars - 1) * lag << endl;
	}
	return 0;
}
