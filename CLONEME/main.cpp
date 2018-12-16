/*input
1
6 3
1 3 4 2 3 4
1 3 4 6
1 2 5 6
3 5 2 4
*/

//
//  main.cpp
//  ABX02
//
//  Created by Nirmaljot Singh Bhasin on 30/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
using namespace std;

typedef long long int lli;
const int MAXN = 100005;
const int LOGN = 20;
const int BASE = 48;
const int MOD = 1000000007;

lli arr[MAXN], sum[MAXN], sqr[MAXN], H[MAXN], base[MAXN];
lli root[MAXN * LOGN];
lli siz;

struct node {
    lli cnt;
    lli leftChild, rightChild;
} seg[MAXN * LOGN];

lli power(lli a, lli n, lli mod) {
    lli ret = 1;
    while (n > 0) {
        if (n & 1) {
            ret = (ret * a) % mod;
        }
        n = n >> 1;
        a = (a * a) % mod;
    }
    return ret % mod;
}

void preprocess() {
    for (int i = 0; i < MAXN; ++i) {
        base[i] = power(i, BASE, MOD) % MOD;
    }
}

void init() {
    siz = 0;
    for (int i = 0; i < MAXN * LOGN; ++i) {
        root[i] = 0;
        seg[i].cnt = seg[i].leftChild = seg[i].rightChild = 0;
    }
}

void update(lli &cur, lli par, lli start, lli end, lli pos) {
    if (pos > end || pos < start) {
        return;
    }
    cur = ++siz;
    seg[cur] = seg[par];
    if (start == end) {
        ++seg[cur].cnt;
        seg[cur].leftChild = seg[cur].rightChild = 0;
        return;
    }
    lli mid = start + ((end - start) >> 1);
    if (pos <= mid) {
        update(seg[cur].leftChild, seg[par].leftChild, start, mid, pos);
    } else {
        update(seg[cur].rightChild, seg[par].rightChild, mid + 1, end, pos);
    }
    seg[cur].cnt = seg[seg[cur].leftChild].cnt + seg[seg[cur].rightChild].cnt;
}

lli query(lli right, lli left, lli start, lli end, lli low, lli high) {
    if (high < start || low > end) {
        return 0;
    }
    if (low <= start && end <= high) {
        return seg[right].cnt - seg[left].cnt;
    }
    lli mid = start + ((end - start) >> 1);
    return query(seg[right].leftChild, seg[left].leftChild, start, mid, low, high) +
           query(seg[right].rightChild, seg[left].rightChild, mid + 1, end, low, high);
}

int main(int argc, const char * argv[]) {
    preprocess();

    int t;
    cin >> t;
    while (t--) {
        init();
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
            H[i] = (H[i - 1] + base[arr[i]]) % MOD;
            sum[i] = sum[i - 1] + arr[i];
            sqr[i] = sqr[i - 1] + (arr[i] * arr[i]);
        }
        for (int i = 1; i <= n; ++i) {
            update(root[i], root[i - 1], 1, MAXN, arr[i]);
        }
        for (int i = 0; i < q; ++i) {
            lli L1, R1, L2, R2;
            cin >> L1 >> R1 >> L2 >> R2;
            if (L1 > L2) {
                swap(L1, L2);
                swap(R1, R2);
            }
            lli hash1 = (H[R1] - H[L1 - 1] + MOD) % MOD;
            lli hash2 = (H[R2] - H[L2 - 1] + MOD) % MOD;

            if (hash1 == hash2) {
                cout << "YES" << endl;
                continue;
            }

            lli sqrDiff = (sqr[R2] - sqr[L2 - 1]) - (sqr[R1] - sqr[L1 - 1]);
            lli diffPQ = (sum[R2] - sum[L2 - 1]) - (sum[R1] - sum[L1 - 1]);

            if (sqrDiff == 0 || diffPQ == 0 || sqrDiff % diffPQ != 0) {
                cout << "NO" << endl;
                continue;
            }

            lli sumPQ = sqrDiff / diffPQ;
            if ((sumPQ + diffPQ) & 1 || (sumPQ - diffPQ) & 1) {
                cout << "NO" << endl;
                continue;
            }

            lli Q = (sumPQ + diffPQ) >> 1;
            lli P = (sumPQ - diffPQ) >> 1;

            if (P <= 0 || Q <= 0 || P > MAXN || Q > MAXN) {
                cout << "NO" << endl;
                continue;
            }

            lli newHash1 = (hash1 - base[P] + MOD) % MOD;
            lli newHash2 = (hash2 - base[Q] + MOD) % MOD;

            if (newHash1 != newHash2) {
                cout << "NO" << endl;
                continue;
            }

            lli pos1 = query(root[R1], root[L1 - 1], 1, MAXN, 1, P - 1);
            lli pos2 = query(root[R2], root[L2 - 1], 1, MAXN, 1, Q - 1);

            lli freqP = query(root[R1], root[L1 - 1], 1, MAXN, P, P);
            lli freqQ = query(root[R2], root[L2 - 1], 1, MAXN, Q, Q);

            if (pos1 == pos2) {
                cout << "YES" << endl;
                continue;
            }

            lli left1 = pos1 + 1;
            lli right1 = pos1 + freqP;
            lli left2 = pos2 + 1;
            lli right2 = pos2 + freqQ;

            if (left1 > right1 || left2 > right2) {
                cout << "NO" << endl;
                continue;
            }
            if (left1 <= right2 && left2 <= right1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
