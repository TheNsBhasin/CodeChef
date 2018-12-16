/*input
1
11
0 0
1 1
2 3
2 5
0 10
-2 10
-5 9
-8 7
-8 4
-6 1
-2 0
*/

//
//  main.cpp
//  POINPOLY
//
//  Created by Nirmaljot Singh Bhasin on 03/02/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;

typedef long long int lli;

vector< pair<lli, lli> > poly;
set< pair<lli, lli> > res;
lli N;

void solve() {
	for (int i = 0; i < N - 2; ++i) {
		for (int j = i + 2; j < N; ++j) {
			if (!((poly[i].first + poly[j].first) & 1) && !((poly[i].second + poly[j].second) & 1)) {
				lli mid_x = (poly[i].first + poly[j].first) >> 1;
				lli mid_y = (poly[i].second + poly[j].second) >> 1;
				res.insert({mid_x, mid_y});
				if (res.size() == (N / 10)) {
					return;
				}
			}
		}
		if (res.size() == (N / 10)) {
			return;
		}
	}
}

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		poly.clear();
		res.clear();
		cin >> N;
		for (int i = 0; i < N; ++i) {
			lli x, y;
			cin >> x >> y;
			poly.push_back({x, y});
		}
		solve();
		for (auto &p : res) {
			cout << p.first << " " << p.second << endl;
		}
	}
	return 0;
}
