/*input
5
ifchefisgoodforchess
fehcaskchefechohisvoice
hecfisaniceperson
letscallchefthefch
chooseaprogrammer
*/

//
//  main.cpp
//  CHEFCHR
//
//  Created by Nirmaljot Singh Bhasin on 02/02/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		if (str.length() < 4) {
			cout << "normal" << endl;
			continue;
		}
		lli cnt = 0;
		bool C, H, E, F;
		for (int i = 0; i < str.length() - 3; ++i) {
			C = H = E = F = false;
			for (int j = 0; j < 4; ++j) {
				if (str[i + j] == 'c') {
					C = true;
				} else if (str[i + j] == 'h') {
					H = true;
				} else if (str[i + j] == 'e') {
					E = true;
				} else if (str[i + j] == 'f') {
					F = true;
				} else {
					i += j;
					break;
				}
			}
			if (C && H && E && F) {
				++cnt;
			}
		}
		if (cnt > 0) {
			cout << "lovely " << cnt << endl;
		} else {
			cout << "normal" << endl;
		}
	}
	return 0;
}
