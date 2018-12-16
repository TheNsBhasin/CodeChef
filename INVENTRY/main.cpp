//
//  main.cpp
//  INVENTRY
//
//  Created by Nirmaljot Singh Bhasin on 03/11/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef long long int lli;
const int MAXN = 102;

int main(int argc, const char *argv[]) {
    lli t, n, m, i, j;
    cin >> t;
    while (t--) {
        cin >> n;
        string s;
        cin >> s;
        lli val = 0;

        lli c = 0;

        for (i = 0; i < n; i++) {
            if (s[i] == '#') {
                if (i != c)
                    val++;
                c++;
            } else if (val > 0)
                val--;
        }

        if (val > 0) {
            cout << -1 << '\n';
            continue;
        }
        stack<lli> st;
        vector<lli> b(n, 0);

        lli cnt = 0;

        for (i = 0; i < n; i++)
            if (s[i] == '#') {
                if (i != cnt)
                    st.push(i);
                cnt++;
            } else if (!st.empty())
                b[st.top()] = st.size() - 1ll, st.pop();

        lli ans = 0;

        for (i = 0; i < n; i++)
            ans += 2 * b[i];

        lli pos = 0;
        for (i = 0; i < n; i++)
            if (s[i] == '#') {
                ans += i - pos;
                pos++;
            }
        cout << ans << '\n';
    }
    return 0;
}
