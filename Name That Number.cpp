/*
	ID: zdzapple
	LANG: C++
	TASK: namenum
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <climits>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;

using namespace std;
ifstream fin ("namenum.in");
ofstream fout ("namenum.out");
ifstream dictIn("dict.txt");
map<string, vector<string> > dict; 

const char code[26] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','0','7','7','8','8','8','9','9','9','0'}; 
const string codeToChar[] = {"0", "0", "A", "D", "G", "J", "M", "P", "T", "W"};

void init()
{
	string str, key;
	int i, j;
	while (dictIn >> str)
	{
		key = str;
		for (i = 0; i < key.size(); ++ i)
		{
			if (key[i] < 'Q') 
				key[i] = (key[i] - 'A') / 3 + 2 + 48;
            else 
				key[i] = (key[i] - 'A' - 1) / 3 + 50;
		}
		if (dict.find(key) == dict.end()) {
			vector<string> st;
			dict[key] = st;
		}
		dict[key].push_back(str);
	}
}

void solve()
{
	string key;
	fin >> key;
	if (dict.find(key) == dict.end()) {
		fout << "NONE" << endl;
	} else {
		map<string, vector<string> >::iterator it = dict.find(key);
		vector<string> result = it->second;
		for (int i = 0; i < result.size(); ++ i)
			fout << result[i] << endl;
	}
}

int main()
{
	init();
	solve();
	return 0;
}