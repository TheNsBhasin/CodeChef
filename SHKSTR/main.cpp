/*input
4
abcd
abce
abcdex
abcde
4
3 abcy
3 abcde
4 abcde
4 x
*/

//
//  main.cpp
//  SHKSTR
//
//  Created by Nirmaljot Singh Bhasin on 03/06/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <memory.h>
using namespace std;

typedef long long int lli;
const int MAXN = 1000006;
const int N = 256;

vector<string> v;
vector< pair<lli, string> > qu;
map< pair<lli, string>, vector<lli> > hm;
string ans[MAXN];
lli trie[MAXN][N], finish[MAXN];
lli sz = 0;

void add(string s) {
	lli node = 0;
	// cout << node;
	for (int i = 0; i < s.length(); ++i) {
		if (trie[node][s[i]] == -1) {
			trie[node][s[i]] = ++sz;
		}
		node = trie[node][s[i]];
		// cout << " -> " << node;
	}
	// cout << endl;
	++finish[node];
}

string solve(string s) {
	string res;
	lli node = 0;
	// cout << node;
	for (int i = 0; i < s.length(); ++i) {
		if (trie[node][s[i]] == -1) {
			break;
		}
		res += s[i];
		node = trie[node][s[i]];
		// cout << " -> " << node;
	}
	// cout << " | ";
	while (!finish[node]) {
		for (int i = 0; i < N; ++i) {
			if (trie[node][i] != -1) {
				node = trie[node][i];
				// cout << " -> " << node;
				res += char(i);
				break;
			}
		}
	}
	// cout << endl;
	return res;
}

int main(int argc, const char * argv[]) {
	memset(trie, -1, sizeof(trie));
	memset(finish, 0, sizeof(finish));
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int r;
		string s;
		cin >> r >> s;
		--r;
		qu.push_back({r, s});
		hm[ {r, s} ].push_back(i);
	}
	sort(qu.begin(), qu.end());
	lli cur = 0;
	for (auto &p : qu) {
		lli r = p.first;
		string s = p.second;
		while (cur <= r) {
			// cout << "Add " << v[cur] << " -> " << endl;
			add(v[cur]);
			++cur;
		}
		// cout << "solve (" << r << ", " << s << ") -> " << endl;
		string lcp = solve(s);
		// cout << lcp << endl;
		for (auto &i : hm[p]) {
			ans[i] = lcp;
		}
	}
	for (int i = 0; i < q; ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
