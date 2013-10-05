/*
	ID: zdzapple
	LANG: C++
	TASK: palsquare
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
ifstream fin ("palsquare.in");
ofstream fout ("palsquare.out");

const char key[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
                   'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

string convert(int n, int base)
{
	string number;
	while (n)
	{
		number.insert(number.begin(), key[n % base]);
		n /= base;
	}
	return number;
}

bool isPalindromic(string &number)
{
	int i = 0, j = number.size() - 1;
	while (i <= j)
	{
		if (number[i ++] != number[j --])
			return false;
	}
	return true;
}

void solve()
{
	int base;
	fin >> base;
	for (int i = 1; i <= 300; ++ i)
	{
		string num = convert(i, base);
		string square = convert(i * i, base);
		if (isPalindromic(square))
			fout << num << " " << square << endl;
	}
}

int main()
{
	solve();
	return 0;
}