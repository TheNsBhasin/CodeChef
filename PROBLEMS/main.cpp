/*input
3 3
16 24 60
498 861 589
14 24 62
72 557 819
16 15 69
435 779 232
*/

//
//  main.cpp
//  PROBLEMS
//
//  Created by Nirmaljot Singh Bhasin on 06/08/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;
const int MAXS = 31;

pair<lli, lli> arr[MAXN][MAXS];
vector<lli> ans[MAXS];

int main(int argc, const char * argv[]) {
	for (int i = 0; i < MAXS; ++i) {
		ans[i].clear();
	}
	int p, s;
	cin >> p >> s;
	for (int i = 0; i < p; ++i) {
		for (int j = 0; j < s; ++j) {
			cin >> arr[i][j].first;
		}
		for (int j = 0; j < s; ++j) {
			cin >> arr[i][j].second;
		}
		sort(arr[i], arr[i] + s);
		lli cnt = 0;
		for (int j = 1; j < s; ++j) {
			if (arr[i][j - 1].second > arr[i][j].second) {
				++cnt;
			}
		}
		ans[cnt].push_back(i + 1);
	}
	for (int i = 0; i < MAXS; ++i) {
		for (int j = 0; j < ans[i].size(); ++j) {
			cout << ans[i][j] << endl;
		}
	}
	return 0;
}
