/*
	ID: zdzapple
	LANG: C++
	TASK: sprime
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

ifstream fin ("sprime.in");
ofstream fout ("sprime.out");

bool isprime(long n)
{
    long i;

    if (n == 2)
        return true;

    if (n%2 == 0)
        return false;

    for (i = 3; i*i <= n; i += 2)
        if (n%i == 0)
            return false;

    return true;
}

vector<int> solve(int N)
{
    int i, j;
    if (N == 1) {
        vector<int> r;
        r.push_back(2);
        r.push_back(3);
        r.push_back(5);
        r.push_back(7);
        return r;
    }
    vector<int> pre = solve(N - 1);
    vector<int> now;
    for (i = 0; i < pre.size(); ++ i)
    {
        for (j = 1; j <= 9; j += 2)
        {
            int num = pre[i] * 10 + j;
            if (isprime(num))
                now.push_back(num);
        }

    }
    return now;

}

int main()
{
    int N, i, j;
    fin >> N;
    vector<int> result = solve(N);
    for (i = 0; i < result.size(); ++ i)
    {
        fout << result[i] << endl;
    }
    return 0;
}
