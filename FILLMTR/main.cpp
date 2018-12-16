/*input
4
2 2
1 1 0
1 2 1
2 3
1 1 0
1 2 1
2 1 0
3 2
2 2 0
2 3 1
3 3
1 2 1
2 3 1
1 3 1
*/

//
//  main.cpp
//  FILLMTR
//
//  Created by Nirmaljot Singh Bhasin on 02/09/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int MAXN = 100005;
const int BLACK = 1;
const int WHITE = 0;

int parent[MAXN], rnk[MAXN], color[MAXN];
vector<pair<int, int> > v;

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    parent[x] = find(parent[x]);
    return parent[x];
}

void join(int x, int y) {
    int p1 = find(x);
    int p2 = find(y);
    if (p1 == p2) {
        return;
    }
    if (rnk[p1] >= rnk[p2]) {
        parent[p2] = parent[p1];
        ++rnk[p1];
    } else {
        parent[p1] = parent[p2];
        ++rnk[p2];
    }
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        bool flag = false;
        v.clear();
        int n, q;
        cin >> n >> q;
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
            rnk[i] = 0;
            color[i] = -1;
        }
        for (int i = 0; i < q; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            if (z == 0) {
                if (x != y) {
                    join(x, y);
                }
            } else {
                if (x < y) {
                    swap(x, y);
                }
                v.push_back(make_pair(x, y));
            }
        }
        for (auto &p : v) {
            int p1 = find(p.first);
            int p2 = find(p.second);
            if (p1 == p2 || p.first == p.second) {
                flag = true;
                break;
            }
            int c1 = color[p1];
            int c2 = color[p2];
            if (c1 == -1 && c2 == -1) {
                color[p1] = BLACK;
                color[p2] = WHITE;
            } else if (c1 == -1 && c2 != -1) {
                color[p1] = !c2;
            } else if (c1 != -1 && c2 == -1) {
                color[p2] = !c1;
            } else if (c1 == c2) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "no" << endl;
        } else {
            cout << "yes" << endl;
        }
    }
    return 0;
}
