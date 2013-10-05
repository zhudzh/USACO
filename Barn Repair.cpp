/*
	ID: zdzapple
	LANG: C++
	TASK: barn1
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
using namespace std;

ifstream fin ("barn1.in");
ofstream fout ("barn1.out");

void solve()
{
	int M, S, C, i, j;
	fin >> M >> S >> C;
    vector<int> barn(C, 0);
	for (i = 0; i < C; ++ i)
	{
		fin >> barn[i];
	}
	sort(barn.begin(), barn.end());
	int result = barn[C-1] - barn[0] + 1;
	vector<int> barnDiff;
	for (i = 0; i < C-1; ++ i)
        barnDiff.push_back(barn[i+1] - barn[i] - 1);
    sort(barnDiff.begin(), barnDiff.end(), greater<int>());
    for (i = 0; i < min(M - 1, (int)barnDiff.size()); ++ i)
        result -= barnDiff[i];
    fout << result << endl;
}

int main()
{
	solve();
	return 0;
}
