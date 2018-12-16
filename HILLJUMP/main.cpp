/*input
5 3
1 2 3 4 5
1 1 2
2 3 4 -1
1 1 2
*/

//
//  main.cpp
//  HILLJUMP
//
//  Created by Nirmaljot Singh Bhasin on 03/09/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;
const int ROOT_N = 320;

int n, q;
lli arr[MAXN], offset[ROOT_N];
int no_of_blocks, block_of[MAXN], max_in_block[MAXN], next_high[MAXN];

int jump(int idx) {
    lli curr_height = arr[idx] + offset[block_of[idx]];
    for (int i = 1; i <= 100 && idx + i <= n; ++i) {
        if (arr[idx + i] + offset[block_of[idx + i]] > curr_height) {
            return idx + i;
        }
    }
    return idx;
}

int getNextHigh(int curr_block) {
    if (curr_block == no_of_blocks) {
        return -1;
    }
    int from = max_in_block[curr_block];
    int to = max_in_block[curr_block + 1];
    if (arr[from] + offset[curr_block] >= arr[to] + offset[curr_block + 1]) {
        return -1;
    }
    int answer = 0;
    while (from != to) {
        int nxt = jump(from);
        if (nxt == from) {
            return -1;
        }
        from = nxt;
        ++answer;
    }
    return answer;
}

void makeBloack(int curr_block) {
    int from = (curr_block - 1) * ROOT_N + 1;
    int to = min(n, curr_block * ROOT_N);
    int maxi_idx = from;
    for (int i = from + 1; i < to; ++i) {
        if (arr[i] > arr[maxi_idx]) {
            maxi_idx = i;
        }
    }
    max_in_block[curr_block] = maxi_idx;
    next_high[curr_block] = getNextHigh(curr_block);
}

void init() {
    no_of_blocks = (n + ROOT_N - 1) / ROOT_N;
    for (int i = 1; i <= n; ++i) {
        block_of[i] = ((i - 1) / ROOT_N) + 1;
    }
    for (int i = no_of_blocks; i > 0; --i) {
        makeBloack(i);
    }
}

int query(int pos, int k) {
    while (k > 0 && pos != max_in_block[block_of[pos]]) {
        --k;
        int nxt = jump(pos);
        if (nxt == pos) {
            return pos;
        }
        pos = nxt;
    }
    int curr_block = block_of[pos];
    while (next_high[curr_block] != -1 && k >= next_high[curr_block]) {
        k = k - next_high[curr_block];
        ++curr_block;
        pos = max_in_block[curr_block];
    }
    while (k > 0) {
        --k;
        int nxt = jump(pos);
        if (nxt == pos) {
            return pos;
        }
        pos = nxt;
    }
    return pos;
}

void update(int L, int R, int X) {
    int from_block = block_of[L];
    int to_block = block_of[R];
    if (from_block == to_block) {
        for (int i = L; i <= R; ++i) {
            arr[i] += X;
        }
    } else {
        for (int i = L; i <= from_block * ROOT_N; ++i) {
            arr[i] += X;
        }
        for (int i = ((to_block - 1) * ROOT_N) + 1; i <= R; ++i) {
            arr[i] += X;
        }
        for (int curr_block = from_block + 1; curr_block < to_block; ++curr_block) {
            offset[curr_block] += X;
        }
        makeBloack(to_block);
        if (from_block != to_block - 1) {
            makeBloack(to_block - 1);
        }
    }
    makeBloack(from_block);
    if (from_block > 1) {
        next_high[from_block - 1] = getNextHigh(from_block - 1);
    }
}

int main(int argc, const char * argv[]) {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    init();
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, k;
            cin >> i >> k;
            cout << query(i, k) << endl;
        } else {
            int L, R, X;
            cin >> L >> R >> X;
            update(L, R, X);
        }
    }
    return 0;
}
