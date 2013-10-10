/*
	ID: zdzapple
	LANG: C++
	TASK: money
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

const string input_file = "money.in";
const string out_file = "money.out";

ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

#define MAXTOTAL 10000

long long nway[MAXTOTAL + 1] = {0};
int values[26];
int V, N;

void solve()
{
    fin >> V >> N;
    int i, j, c;
    nway[0] = 1;
    for (i = 0; i < V; ++ i)
        fin >> values[i];
    for (i = 0; i < V; ++ i)
    {
        for (j = values[i]; j <= N; ++ j)
            nway[j] += nway[j - values[i]];
    }
    fout << nway[N] << endl;
}

int main()
{
    openfile();
    solve();
    closefile();
    return 0;
}
