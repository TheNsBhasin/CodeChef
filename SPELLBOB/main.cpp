/*input
3
bob
rob
dbc
ocb
boc
obc
*/

//
//  main.cpp
//  SPELLBOB
//
//  Created by Nirmaljot Singh Bhasin on 12/08/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

char str[2][3];

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 3; ++j) {
				cin >> str[i][j];
			}
		}
		bool case1, case2, case3;
		case1 = case2 = case3 = false;

		case1 = (str[0][0] == 'b' || str[1][0] == 'b') && (str[0][1] == 'o' || str[1][1] == 'o') && (str[0][2] == 'b' || str[1][2] == 'b');
		case2 = (str[0][0] == 'o' || str[1][0] == 'o') && (str[0][1] == 'b' || str[1][1] == 'b') && (str[0][2] == 'b' || str[1][2] == 'b');
		case3 = (str[0][0] == 'b' || str[1][0] == 'b') && (str[0][1] == 'b' || str[1][1] == 'b') && (str[0][2] == 'o' || str[1][2] == 'o');


		if (case1 || case2 || case3) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}
	return 0;
}
