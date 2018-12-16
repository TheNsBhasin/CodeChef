/*input
2
5 5
0 0 0 -1 5
0 0 0 -1 0
1 0 0 0 0
0 0 0 0 0
0 0 0 0 0
3 4
0 0 5 -1
0 -1 -1 0
0 0 0 0
*/

//
//  main.cpp
//  L56LABY
//
//  Created by Nirmaljot Singh Bhasin on 27/01/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <memory>
#include <utility>
#include <vector>
using namespace std;

typedef long long int lli;

lli row[] = { -1, 0, 0, 1};
lli col[] = { 0, -1, 1, 0};

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		lli n, m;
		cin >> n >> m;
		lli mat[n][m];
		char ans[n][m];
		vector < pair<lli, lli> > v;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				ans[i][j] = 'N';
				cin >> mat[i][j];
				if (mat[i][j] == -1) {
					ans[i][j] = 'B';
				} else if (mat[i][j] > 0) {
					++mat[i][j];
					ans[i][j] = 'Y';
					v.push_back(make_pair(i, j));
				}
			}
		}
		for (int i = 0; i < v.size(); ++i) {
			lli x = v[i].first;
			lli y = v[i].second;
			for (int j = 0; j < 4; ++j) {
				lli X = x + row[j];
				lli Y = y + col[j];
				if (X >= 0 && X < n && Y >= 0 && Y < m && mat[X][Y] >= 0 && (mat[X][Y] < (mat[x][y] - 1))) {
					mat[X][Y] = mat[x][y] - 1;
					ans[X][Y] = 'Y';
					v.push_back(make_pair(X, Y));
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << ans[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
