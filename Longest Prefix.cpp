/*
	ID: zdzapple
	LANG: C++
	TASK: prefix
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

const string input_file = "prefix.in";
const string out_file = "prefix.out";

ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

const int maxp = 200;
const int maxl = 10;

char prim[maxp + 1][maxl + 1];
int nump = 0;

int dp[2000001];
char data[2000001];
int ndata;

void solve()
{
    int best, i, j, k;
    while (true)
    {
        fin >> prim[nump];
        if (prim[nump][0] != '.')
            nump ++;
        else
            break;
    }
    ndata = 0;
    string s;
    while (getline(fin, s))
    {
        for (i = 0; i < s.size(); ++ i)
            data[ndata ++] = s[i];
    }
    dp[0] = 1;
    best = 0;
    for (i = 0; i < ndata; ++ i)
    {
        if (dp[i]) {
            best = i;
            for (j = 0; j < nump; ++ j)
            {
                for (k = 0; i + k < ndata && prim[j][k] &&
                        prim[j][k] == data[i + k]; k ++)
                            ;
                if (!prim[j][k])
                    dp[i + k] = 1;
            }
        }
    }
    if (dp[ndata]) best = ndata;
    fout << best << endl;
    /*
    ndata = 0;
  while (fscanf (fin, "%s", data+ndata) == 1)
    ndata += strlen(data+ndata);
    */
}

int main()
{
    openfile();
    solve();
    closefile();
    return 0;
}
