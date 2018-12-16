/*input
1
3 3
3 1 2 2
2 1 2
3 1 4 1
2 1 2
2 1 5
3 1 3
2 1 1 2
1 1 1 2
3 1 3 3
*/

//
//  main.cpp
//  CHEFCCYL
//
//  Created by Nirmaljot Singh Bhasin on 10/10/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <cstring>
using namespace std;

typedef long long int lli;

lli shortestPath(vector<lli> path, lli u , lli v, lli siz, lli total_length) {
    if (u > v) {
        swap(u, v);
    }
    lli x = abs(path[(v - 1 + siz) % siz] - path[(u - 1 + siz) % siz]);
    return min(x , total_length - x);
}

int main(int argc, const char * argv[]) {
    lli t;
    cin >> t;
    while (t--) {
        lli n, q;
        cin >> n >> q;
        vector<lli> cycle[n];
        lli siz[n];
        lli start[n], end[n], weight[n];
        lli length[n];
        lli total_length = 0;
        memset(length, 0, sizeof(length));
        for (int i = 0; i < n; ++i) {
            cin >> siz[i];
            for (int j = 0; j < siz[i]; ++j) {
                lli w;
                cin >> w;
                length[i] += w;
                cycle[i].push_back(w);
            }
        }
        for (int i = 0; i < n; ++i) {
            lli v1, v2, w;
            cin >> v1 >> v2 >> w;
            --v1; --v2;
            start[i] = v1;
            end[(i + 1) % n] = v2;
            weight[i] = w;
        }

        for (int i = 0; i < n; ++i) {
            cycle[i][siz[i] - 1] = 0;
            for (int j = 0; j < siz[i] - 1; ++j) {
                cycle[i][j] += cycle[i][(j - 1 + siz[i]) % siz[i]];
            }
        }

        weight[0] = (shortestPath(cycle[0], start[0], end[0], siz[0], length[0]) + weight[0]);
        for (int  i = 1; i < n; ++i) {
            weight[i] += (shortestPath(cycle[i], start[i], end[i], siz[i], length[i])
                          + weight[i - 1]);
        }
        total_length = weight[n - 1];
        weight[n - 1] = 0;

        for (int i = 0; i < q; ++i) {
            lli v1, c1, v2, c2;
            cin >> v1 >> c1 >> v2 >> c2;
            --v1; --c1; --v2; --c2;
            
            if (c1 > c2) {
                swap(c1, c2);
                swap(v1, v2);
            }

            lli clockwise_path = abs(weight[(c2 - 1 + n) % n] - weight[(c1 - 1 + n) % n] - shortestPath(cycle[c1], end[c1], start[c1], siz[c1], length[c1]));
            lli anti_clockwise_path = total_length - clockwise_path - shortestPath(cycle[c1], start[c1], end[c1], siz[c1], length[c1]) - shortestPath(cycle[c2], start[c2], end[c2], siz[c2], length[c2]);

            lli ans = min(shortestPath(cycle[c1], v1, start[c1], siz[c1], length[c1])
                          + clockwise_path
                          + shortestPath(cycle[c2], end[c2], v2, siz[c2], length[c2]),
                          shortestPath(cycle[c1], v1, end[c1], siz[c1], length[c1])
                          + anti_clockwise_path
                          + shortestPath(cycle[c2], start[c2], v2, siz[c2], length[c2]));

            cout << ans << endl;
        }
    }
    return 0;
}
