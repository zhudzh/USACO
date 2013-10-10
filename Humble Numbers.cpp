/*
	ID: zdzapple
	LANG: C++
	TASK: humble
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
#include <assert.h>
#include <stdio.h>
#include <string.h>
using namespace std;

const string input_file = "humble.in";
const string out_file = "humble.out";
ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

int N, K;
long num[102], dex[102];
long humble[100002];

int main()
{
    openfile();

    int i, j, k, d;
    fin >> K >> N;
    humble[0] = 1;
    for (i = 0; i < K; ++ i)
    {
        fin >> num[i];
        dex[i] = 0;
    }
    int index = 0;
    while (index < N)
    {
        long minHumble = INT_MAX;
        for (j = 0; j < K; ++ j)
        {
            while ((long long) num[j] * humble[dex[j]] <= humble[index])
                dex[j] ++;
            if (minHumble > (long long) num[j] * humble[dex[j]])
                minHumble = num[j] * humble[dex[j]];
        }
        humble[++ index] = minHumble;
    }
    fout << humble[N] << endl;

    closefile();
    return 0;
}


