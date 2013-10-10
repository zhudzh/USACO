/*
	ID: zdzapple
	LANG: C++
	TASK: subset
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
#include <stdio.h>
#include <string.h>
using namespace std;

const string input_file = "subset.in";
const string out_file = "subset.out";

ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

int N;
unsigned int dp[40][400];

void solve()
{
    int i, j;
    fin >> N;
    int sum = N * (N + 1) / 2;
    if (sum % 2) {
        fout << 0 << endl;
        exit(0);
    }
    sum /= 2;
    memset(dp, 0, sizeof(dp[0]));
    dp[0][0] = 1;
    for (i = 1; i <= N; ++ i)
    {
        for (j = 0; j <= sum; ++ j)
            dp[i][j] = dp[i-1][j];
        for (j = i; j <= sum; ++ j)
            dp[i][j] += dp[i - 1][j - i];
    }
    fout << dp[N-1][sum] << endl;
}

int main()
{
    openfile();
    solve();
    closefile();
    return 0;
}
