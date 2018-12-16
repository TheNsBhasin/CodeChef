/*input
2
101
01
6
1 1
1 2
1 3
2 1
2 2
2 3
1011001
0101111
6
5 5
3 4
2 6
3 7
7 7
6 5
*/

//
//  main.cpp
//  TABGAME
//
//  Created by Nirmaljot Singh Bhasin on 13/09/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <memory.h>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

bool row[2][MAXN];
bool col[MAXN][2];

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		memset(row, false, sizeof(row));
		memset(col, false, sizeof(col));

		string s1, s2;
		cin >> s1 >> s2;
		lli m = s1.length();
		lli n = s2.length();
		row[0][0] = col[0][0] = (s1[0] == '0') || (s2[0] == '0');
		row[0][1] = col[0][1] = (m > 1 && s1[1] == '0') || (!row[0][0]);
		row[1][0] = col[1][0] = (n > 1 && s2[1] == '0') || (!row[0][0]);
		row[1][1] = col[1][1] = (!row[0][1]) || (!col[1][0]);

		for (int i = 2; i < n; ++i) {
			col[i][0] = (s2[i] == '0') || (!col[i - 1][0]);
		}

		for (int j = 2; j < m; ++j) {
			row[0][j] = (s1[j] == '0') || (!row[0][j - 1]);
		}

		for (int i = 2; i < n; ++i) {
			col[i][1] = (!col[i][0]) || (!col[i - 1][1]);
		}

		for (int j = 2; j < m; ++j) {
			row[1][j] = (!row[1][j - 1]) || (!row[0][j]);
		}

		int q;
		cin >> q;
		string ans = "";
		for (int i = 0; i < q; ++i) {
			lli x, y;
			cin >> x >> y;
			--x;
			--y;
			if (x < 2) {
				ans += (row[x][y] ? "1" : "0");
			} else if (y < 2) {
				ans += (col[x][y] ? "1" : "0");
			} else {
				if (x < y) {
                    // cout << 1 << ", " << y - x + 1 << endl;
					ans += (row[1][y - x + 1] ? "1" : "0");
				} else {
                    // cout << x - y + 1 << ", " << 1 << endl;
					ans += (col[x - y + 1][1] ? "1" : "0");
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
