/*
	ID: zdzapple
	LANG: C++
	TASK: dualpal
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
ifstream fin ("dualpal.in");
ofstream fout ("dualpal.out");

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
	int N, S;
	fin >> N >> S;
	for (int i = S + 1;  ; ++ i)
	{
		int count = 0;
		for (int base = 2; base <= 10; ++ base)
		{
			string num = convert(i, base);
			if (isPalindromic(num)) {
				count ++;
				if (count == 2) {
					fout << i << endl;
					N --;
					if (N == 0)
						return;
					break;
				}
			}
		}
		
	}
}

int main()
{
	solve();
	return 0;
}