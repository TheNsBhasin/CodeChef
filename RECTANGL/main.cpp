/*input
3
1 1 2 2
3 2 2 3
1 2 2 2
*/

//
//  main.cpp
//  RECTANGL
//
//  Created by Nirmaljot Singh Bhasin on 05/01/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;
const int N = 4;

lli arr[N];

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < N; ++i) {
			cin >> arr[i];
		}
		sort(arr, arr + N);
		if (arr[0] == arr[1] && arr[2] == arr[3]) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
