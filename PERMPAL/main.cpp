/*input
4
aa
baa
abc
abab
*/

//
//  main.cpp
//  PERMPAL
//
//  Created by Nirmaljot Singh Bhasin on 03/02/18.
//  Copyright © 2018 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

const int MAXN = 26;
typedef long long int lli;

string reverse(string str) {
	string rev = str;
	reverse(rev.begin(), rev.end());
	return rev;
}

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		lli len = str.length();
		lli freq[MAXN];
		queue<lli> idx[MAXN];
		memset(freq, 0, sizeof(freq));

		for (int i = 0; i < len; ++i) {
			++freq[str[i] - 'a'];
			idx[str[i] - 'a'].push(i + 1);
		}
		lli odd = 0;
		for (int i = 0; i < MAXN; ++i) {
			if (freq[i] & 1) {
				++odd;
			}
		}
		if (((len & 1) && odd == 1) || (!(len & 1) && odd == 0)) {
			string pali;
			char c;
			for (int i = 0; i < MAXN; ++i) {
				if (freq[i] & 1) {
					c = i + 'a';
				}
				pali += string(freq[i] >> 1, i + 'a');
			}
			string rev = reverse(pali);
			if (len & 1) {
				pali += c;
			}
			pali += rev;
			lli ans[pali.length()];
			for (int i = 0; i < pali.length(); ++i) {
				ans[i] = idx[pali[i] - 'a'].front();
				idx[pali[i] - 'a'].pop();
			}
			for (int i = 0; i < pali.length(); ++i) {
				cout << ans[i] << " ";
			}
			cout << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}
