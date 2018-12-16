/*input
3 3 2
1 10 3
2 5 3
3 1 1
*/

//
//  main.cpp
//  CHEFZERO
//
//  Created by Nirmaljot Singh Bhasin on 16/09/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

typedef long long int lli;
const int MAXN = 1003;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

lli arr[MAXN][MAXN], ans[MAXN][MAXN];
int n, m, k;

bool isSafe(lli x, lli y) { return (x >= 0 && x < n && y >= 0 && y < m); }

void solve(lli k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            ans[i][j] = 1;
        }
    }

    lli sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += arr[i][j];
        }
    }

    sum /= 2;

    if (k > 1) {
        queue< pair<lli, lli> > q;
        q.push({0, 0});

        while (!q.empty()) {
            if (sum <= 0) {
                break;
            }

            lli X = q.front().first;
            lli Y = q.front().second;
            q.pop();

            if (sum - arr[X][Y] < 0) {
                continue;
            }

            sum -= arr[X][Y];
            ans[X][Y] = 2;

            for (int i = 0; i < 4; ++i) {
                if (isSafe(X + dx[i], Y + dy[i])) {
                    q.push({X + dx[i], Y + dy[i]});
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, const char *argv[]) {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    solve(k);
    return 0;
}
