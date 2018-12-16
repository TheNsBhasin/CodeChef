/*input
6 4
1 2
5 1 3
2 1 4
3 2 5
4 2 1
6 3 3
1 4 2
6 0 12 0
7 12 7
4 0 7
*/

//
//  main.cpp
//  GPD
//
//  Created by Nirmaljot Singh Bhasin on 29/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int N = 3e5 + 10;
const int M = 30 * N + 10;
const int NUM_BITS = 30;

map<int, int> key_of_id;
map<int, vector<int> > adj;
map<int, int> ROOT;
int child[2][M];
int cnt = 0;

int add(int prev, int idx, int key) {
    int root = ++cnt;
    if (idx < 0) {
        return root;
    }
    int bit = (key >> idx) & 1;
    child[bit ^ 1][root] = child[bit ^ 1][prev];
    child[bit][root] = add(child[bit][prev], idx - 1, key);
    return root;
}

int query_min(int root, int key) {
    int ans = 0;
    for (int i = NUM_BITS; i >= 0; i--) {
        int bit = (key >> i) & 1;
        if (child[bit][root]) {
            root = child[bit][root];
            ans += (bit << i);
        } else {
            root = child[bit ^ 1][root];
            ans += ((bit ^ 1) << i);
        }
    }
    return ans;
}

int query_max(int root, int key) {
    int ans = 0;
    for (int i = NUM_BITS; i >= 0; i--) {
        int bit = (key >> i) & 1;
        if (child[bit ^ 1][root]) {
            root = child[bit ^ 1][root];
            ans += ((bit ^ 1) << i);
        } else {
            root = child[bit][root];
            ans += (bit << i);
        }
    }
    return ans;
}

void add_node(int u, int p, int key) {
    ROOT[u] = add(ROOT[p], NUM_BITS, key);
}

void dfs(int u, int p) {
    add_node(u, p, key_of_id[u]);
    for (auto &v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}

int main(int argc, const char * argv[]) {
    int n, q;
    int R, key;
    int v, u , k;
    cin >> n >> q;
    cin >> R >> key;
    key_of_id[R] = key;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v >> k;
        key_of_id[u] = k;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cnt = 0;
    dfs(R, 0);
    int last_answer = 0;
    int t;
    for (int i = 0; i < q; i++) {
        cin >> t;
        t ^= last_answer;
        if (t == 0) {
            cin >> v >> u >> k;
            u ^= last_answer;
            v ^= last_answer;
            k ^= last_answer;
            add_node(u, v, k);
        } else {
            cin >> v >> k;
            v ^= last_answer;
            k ^= last_answer;
            int min_answer = query_min(ROOT[v], k) ^ k;
            int max_answer = query_max(ROOT[v], k) ^ k;
            cout << min_answer << " " << max_answer << endl;
            last_answer = min_answer ^ max_answer;
        }
    }
    return 0;
}
