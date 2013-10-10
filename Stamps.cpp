/*
	ID: zdzapple
	LANG: C++
	TASK: stamps
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

const string input_file = "stamps.in";
const string out_file = "stamps.out";
ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

int     minstamps[10000 * (200 + 3) + 3];
int     N, K;
int     value[200];

int main()
{
    openfile();

    int i, j, k;
    fin >> N >> K;
    for (i = 0; i < K; ++ i)
        fin >> value[i];
    minstamps[0] = 0;
    for (i = 1; i < 10000 * (200 + 3) + 3; ++i)
        minstamps[i] = INT_MAX;
    for (i = 1; ; ++i)
    {
        for (j = 0; j < K; ++ j)
        {
            if (value[j] <= i && minstamps[i-value[j]] + 1 < minstamps[i])
                minstamps[i] = minstamps[i-value[j]] + 1;
        }
        if (minstamps[i] == INT_MAX || minstamps[i] > N)
            break;
        ///cout << i << " " << minstamps[i] << endl;
    }
    fout << i-1 << endl;

    closefile();
}
