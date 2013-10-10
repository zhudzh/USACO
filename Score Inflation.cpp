/*
	ID: zdzapple
	LANG: C++
	TASK: inflate
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

const string input_file = "inflate.in";
const string out_file = "inflate.out";
ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

int M, N;
int best[10001];

int main()
{
    openfile();

    int i, j, k, d;
    fin >> M >> N;
    for (i = 0; i < N; ++ i)
    {
        int pt, mt;
        fin >> pt >> mt;
        for (j = mt; j <= M; ++ j)
            best[j] = max(best[j], best[j-mt] + pt);
    }
    fout << best[M] << endl;

    closefile();
    return 0;
}

