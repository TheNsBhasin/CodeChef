/*input
1
6 4
3 7 2 4 8 7
? 4 3 9
? 3 1 7
+ 6 2
? 4 3 9
*/
//
//  main.cpp
//  SHTARR
//
//  Created by Nirmaljot Singh Bhasin on 16/10/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

struct node {
    lli mx, ans;
    int low, high, pos;
    node() {
        pos = low = high = -1;
        mx = ans = 0;
    }
    node(int low, int high, int pos, lli mx, lli ans) {
        this->low = low;
        this->high = high;
        this->pos = pos;
        this->mx = mx;
        this->ans = ans;
    }
};

vector<node> st;

lli count(int si, lli mx_left) {
    if (st[si].low == st[si].high) {
        return st[si].mx > mx_left;
    }
    if (st[si << 1].mx <= mx_left) {
        return count(si << 1 | 1, mx_left);
    }
    lli ans = count(si << 1, mx_left);
    return ans + (st[si].ans - st[si << 1].ans);
}

node merge(node a, node b) {
    node c;
    c.mx = max(a.mx, b.mx);
    c.low = a.pos;
    c.high = b.pos;
    c.pos = (a.pos) >> 1;
    c.ans = a.ans + count(b.pos, a.mx);
    return c;
}

void build(lli arr[], int ss, int se, int si) {
    if (ss == se) {
        st[si] = node(ss, se, si, arr[ss], 1);
        // cout << "(" << si << ") " << ss << " - " << se << " -> " << st[si].ans << endl;
        return;
    }
    int mid = (ss + se) >> 1;
    build(arr, ss, mid, si << 1);
    build(arr, mid + 1, se, si << 1 | 1);
    st[si] = merge(st[si << 1], st[si << 1 | 1]);
    // cout << "(" << si << ") " << ss << " - " << se << " -> " << st[si].ans << endl;
}

void update(int ss, int se, int pos, int si, lli val) {
    if (ss == se) {
        st[si].mx += val;
        return;
    }
    int mid = (ss + se) >> 1;
    if (mid < pos) {
        update(mid + 1, se, pos, si << 1 | 1, val);
    }
    else {
        update(ss, mid, pos, si << 1, val);
    }
    st[si] = merge(st[si << 1], st[si << 1 | 1]);
}

int query(int ss, int se, int qs, int qe, int si, lli val) {
    if (ss > se || ss > qe || se < qs) {
        return -1;
    }
    if (ss >= qs && se <= qe) {
        if (st[si].mx < val) {
            return -1;
        }
        if (ss == se) {
            return ss;
        }
        node tmp = st[si << 1];
        if (tmp.mx >= val) {
            return query(ss, (ss + se) >> 1, qs, qe, si << 1, val);
        } else {
            return query(((ss + se) >> 1) + 1, se, qs, qe, si << 1 | 1, val);
        }
    }
    int ans = query(ss, (ss + se) >> 1, qs, qe, si << 1, val);
    if (ans == -1) {
        ans = query(((ss + se) >> 1) + 1, se, qs, qe, si << 1 | 1, val);
    }
    return ans;
}

void solve(int ss, int se, int qs, int qe, int si, node &v) {
    if (ss > se || ss > qe || se < qs) {
        return;
    }
    if (ss >= qs && se <= qe) {
        v = merge(v, st[si]);
        return;
    }
    solve(ss, (ss + se) >> 1, qs, qe, si << 1, v);
    solve(((ss + se) >> 1) + 1, se, qs, qe, si << 1 | 1, v);
}

lli solve(int ss, int se, int qs, int qe, int si) {
    node v;
    solve(ss, se, qs, qe, si, v);
    return v.ans;
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while (t--) {
        lli n, q;
        cin >> n >> q;
        lli arr[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        st.assign((n << 2), node());
        build(arr, 0, n - 1, 1);
        while (q--) {
            char type;
            cin >> type;
            if (type == '+') {
                int idx;
                lli val;
                cin >> idx >> val;
                --idx;
                update(0, n - 1, idx, 1, val);
            } else {
                int idx, L, R;
                cin >> idx >> L >> R;
                --idx;
                int l = query(0, n - 1, idx, n - 1, 1, L);
                int h = query(0, n - 1, idx, n - 1, 1, R);
                if (l == -1) {
                    cout << 0 << endl;
                    continue;
                }
                if (h == -1) {
                    h = n - 1;
                }
                lli ans = solve(0, n - 1, l, h, 1);
                cout << ans << endl;
            }
        }
    }
    return 0;
}
