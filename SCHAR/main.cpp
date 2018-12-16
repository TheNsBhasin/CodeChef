//
//  main.cpp
//  SCHAR
//
//  Created by Nirmaljot Singh Bhasin on 01/08/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
	int t;
	string str;
	int indexx[26];
	cin>>t;
	while(t--)
	{
		memset(indexx, -1, sizeof(indexx));
		cin>>str;
		for (int i = 0; str[i]; i++) {
			indexx[str[i]-'a']=i;
		}
	}
	return 0;
}
