/*input
2
5 11
0 1
0 2
0 5
2 3
2 5
1 3
1 5
1 2
3 4
3 5
4 5
3 4
0 3
2 3
1 2
0 1
*/

//
//  main.cpp
//  STRINGRA
//
//  Created by Nirmaljot Singh Bhasin on 02/09/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 3 * 100005;

set<int> adj[MAXN];
vector<int> G[MAXN];
bool visited[MAXN];
int arr[MAXN], counter[MAXN];

void preprocess() {
    memset(arr, 0, sizeof(arr));
    memset(counter, 0, sizeof(arr));
    memset(visited, false, sizeof(arr));
    for (int i = 0; i < MAXN; ++i) {
        adj[i].clear();
        G[i].clear();
    }
}

void dfs(int u) {
    visited[u] = true;
    for(int v : G[u]) {
        if(!visited[v]) {
            arr[v] = arr[u];
            dfs(v);
        }
    }
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        preprocess();
        int n, m;
        bool flag = true;
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            if (adj[y].find(x) == adj[y].end()) {
                adj[y].insert(x);
            } else {
                flag = false;
            }
        }
        int k = 0;
        for (int i = 1; i <= n && flag; ++i) {
            int siz = (int)adj[i].size();
            int root = *adj[i].begin();
            if (siz != i - root) {
                flag = false;
                break;
            }
            if (root == 0) {
                arr[i] = ++k;
            } else {
                G[root].push_back(i);
                ++counter[root];
                if (counter[root] > 1) {
                    flag = false;
                    break;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (!visited[i] && arr[i]) {
                dfs(i);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (arr[i] == 0 || !visited[i]) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            cout << -1 << endl;
        } else {
            for (int i = 1; i <= n; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
