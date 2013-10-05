/*
	ID: zdzapple
	LANG: C++
	TASK: calfflac
*/
/**
http://www.nocow.cn/index.php/USACO/barn1
**/

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
#include <ctype.h>
#include <cstring>
using namespace std;

ifstream fin ("calfflac.in");
ofstream fout ("calfflac.out");
#define maxn  20001
char chars[maxn];

struct node
{
	int low;
	int high;
	int len;
	node(int _low, int _high, int _len)
	{
		low = _low, high = _high;
		len = _len;
	}
};

node expandAroundCenter(char* s, int l, int r, int len)
{
    int lowest = l, highest = r, alLen = 0;
    while (l >= 0 && r <= len - 1)
    {
        while (!isalpha(s[l]) && l >= 0)
            l --;
        while (!isalpha(s[r]) && r <= len - 1)
            r ++;
       // cout << s[l] << " " << s[r] << endl;
        if (l < 0 || r >= len)
            break;
        if (tolower(s[l]) == tolower(s[r])) {
            lowest = l;
            highest = r;
			alLen += l == r ?  1 : 2;
            l --;
            r ++;
			
        } else
            break;
    }
	if (!isalpha(s[lowest]) && !isalpha(s[highest]))
		return node(l, l, 0);
    return node(lowest, highest, alLen);
}

node longestPalindrome(char* s, int len)
{
    if (len <= 0)
        return node(0, 0, 0);
    node longest(0, 0, 1);
    for (int i = 0; i < len - 1; ++ i)
    {
        node s1 = expandAroundCenter(s, i, i, len);
        if (s1.len > longest.len)
            longest = s1;
        node s2 = expandAroundCenter(s, i, i + 1, len);
        if (s2.len > longest.len)
            longest = s2;
    }
    return longest;
}

void solve()
{
	char c;
	int i, j, len = 0;
    while (!fin.eof())
    {
        c = fin.get();
        chars[len ++] = c;
    }
	node result = longestPalindrome(chars, len);
	string str(chars + result.low, chars + result.high + 1);
    fout << result.len << endl << str << endl;
}

int main()
{
	solve();
	return 0;
}
