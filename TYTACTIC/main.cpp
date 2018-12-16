/*input
5 8
7 2 0 5 8
1 2
2 3
2 4
1 5
Q 1
Q 2
U 2 4
Q 1
Q 2
U 5 3
Q 1
Q 2
*/

//
//  main.cpp
//  TYTACTIC
//
//  Created by Nirmaljot Singh Bhasin on 04/11/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;

int cnt = 0;
lli skill[MAXN];
int start[MAXN], finish[MAXN];
lli arr[MAXN], tree[MAXN << 1];
bool visited[MAXN];
vector <int> adj[MAXN];

void dfs(int u, int parent) {
    start[u] = cnt;
    arr[cnt++] = skill[u];
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
        }
    }
    finish[u] = cnt - 1;
}

void build(int idx, int low, int high) {
    if (low == high) {
        tree[idx] = arr[low];
        return;
    }
    int mid = low + ((high - low) >> 1);
    build(2 * idx, low, mid);
    build(2 * idx + 1, mid + 1, high);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

lli query(int idx, int low, int high, int L, int R) {
    if (L > high || R < low) {
        return 0;
    }
    if (L <= low && R >= high) {
        return tree[idx];
    }
    int mid = low + ((high - low) >> 1);
    lli left = query(2 * idx, low, mid, L, R);
    lli right = query(2 * idx + 1, mid + 1, high, L, R);
    return left + right;
}

void update(int idx, int low, int high, int pos, lli val) {
    if (low == high && pos == high) {
        tree[idx] = val;
        return;
    }
    int mid = low + ((high - low) >> 1);
    if (pos <= mid) {
        update(2 * idx, low, mid, pos, val);
    } else {
        update(2 * idx + 1, mid + 1, high, pos, val);
    }
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

int main(int argc, const char * argv[]) {
    memset(visited, false, sizeof(visited));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> skill[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    build(1, 0, n - 1);
    while (m--) {
        string type;
        cin >> type;
        if (type == "Q") {
            int u;
            cin >> u;
            --u;
            lli ans = query(1, 0, n - 1, start[u], finish[u]);
            cout << ans << endl;
        } else {
            int u;
            lli x;
            cin >> u >> x;
            --u;
            update(1, 0, n - 1, start[u], x);
        }
    }
    return 0;
}
