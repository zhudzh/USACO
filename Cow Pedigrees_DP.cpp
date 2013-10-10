/*
	ID: zdzapple
	LANG: C++
	TASK: nocows
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

const string input_file = "nocows.in";
const string out_file = "nocows.out";

ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

#define MOD 9901
int dp[101][202], N, K;
int smalltrees[101][202];

void solve()
{
    int i, j, k;
    fin >> N >> K;

    dp[1][1] = 1;


    for (i = 2; i <= K; i ++)// depth
    {
        for (j = 1; j <= N; j += 2) // ndoes
        {
            for (k = 1; k <= j - 1 - k; k += 2)
            {
                int c = 2;
                if (k == j - 1 - k) c = 1;
                dp[i][j] += c *
                    (smalltrees[i-2][k] * dp[i-1][j-1-k]
                     + dp[i-1][k] * smalltrees[i-2][j-1-k]
                     + dp[i-1][k] * dp[i-1][j-1-k]);
                dp[i][j] %= MOD;
            }

        }
         for (k = 0; k <= N; ++ k)
            {
                smalltrees[i-1][k] += smalltrees[i-2][k] + dp[i-1][k];
                smalltrees[i-1][k] %= MOD;
            }
    }
    fout << dp[K][N] << endl;
}

int main()
{
    openfile();
    solve();
    closefile();
    return 0;
}
