/*
	ID: zdzapple
	LANG: C++
	TASK: milk
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

ifstream fin ("milk.in");
ofstream fout ("milk.out");

bool compare(const pair<int, int> &first, const pair<int, int> &second)
{
	if (first.first == second.first)
		return first.second < second.second;
	return first.first < second.first;
}

void solve()
{
	int N, M;
	fin >> N >> M;
	vector<pair<int, int> > milks;
	for (int i = 0; i < M; ++ i)
	{
		int P, A;
		fin >> P >> A;
		milks.push_back(make_pair(P, A));
	}
	sort(milks.begin(), milks.end(), compare);
	int price = 0;
	int i = 0;
	while (N > 0)
	{
		if (N >= milks[i].second) {
			N -= milks[i].second;
			price += milks[i].first * milks[i].second;
		} else {
			price += milks[i].first * N;
			N = 0;
		}
		i ++;
	}
	fout << price << endl;
}

int main()
{
	solve();
	return 0;
}