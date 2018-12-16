/*input
3
19
1 2 3 4 4 5 6 6 6 7 6 6 6 5 4 4 3 2 1
14
1 2 3 4 5 6 7 6 5 4 3 2 1 1
13
1 2 3 4 5 6 8 6 5 4 3 2 1
*/

//
//  main.cpp
//  RAINBOWA
//
//  Created by Nirmaljot Singh Bhasin on 17/08/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;
typedef long long int lli;

int main(int argc, const char* argv[]) {
	int t, n;
	int arr[102];
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		int counter = 0;
		for (int i = 0; i < n / 2; ++i) {
			if (arr[i] == arr[n - i - 1]) {
				++counter;
			}
		}
		if (counter == n / 2 && arr[n / 2] == 7) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
	return 0;
}
