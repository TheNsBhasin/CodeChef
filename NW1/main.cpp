/*input
2
28 mon
31 wed
*/

//
//  main.cpp
//  NW1
//
//  Created by Nirmaljot Singh Bhasin on 30/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

const int NUM_DAYS = 7;

string week[] = {"mon", "tues", "wed", "thurs", "fri", "sat", "sun"};
map<string, int> m;

void preprocess() {
	int cnt = 0;
	for (int i = 0; i < NUM_DAYS; ++i) {
		m[week[i]] = cnt++;
	}
}

int main(int argc, const char * argv[]) {
	preprocess();
	int t;
	cin >> t;
	while (t--) {
		int w;
		string s;
		cin >> w >> s;
		int cnt[NUM_DAYS];
		int reg = w / NUM_DAYS;
		for (int i = 0; i < NUM_DAYS; ++i) {
			cnt[i] = reg;
		}
		int rem = w - NUM_DAYS * reg;
		int st = m[s];
		while (rem > 0) {
			cnt[st % NUM_DAYS]++;
			--rem;
			++st;
		}
		for (int i = 0; i < NUM_DAYS; ++i) {
			cout << cnt[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
