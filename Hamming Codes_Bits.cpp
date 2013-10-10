/*
	ID: zdzapple
	LANG: C++
	TASK: hamming
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

const string input_file = "hamming.in";
const string out_file = "hamming.out";

ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

int i, j, k, N, B, D, maxval;
const int MAX = (1 << 8 + 1);
const int NMAX = 65;
const int BMAX = 10;
const int DMAX = 10;

int nums[NMAX], dist[MAX][MAX];

void findGroups(int cur, int start)
{
    if (cur == N) {
        for (i = 0; i < cur; ++ i)
        {
            if (i % 10)
                fout << " ";
            fout << nums[i];
            if (i % 10 == 9 || i == cur - 1)
                fout << endl;
        }
        exit(0);
    }
    int canuse;
    for (i = start; i < maxval; ++ i)
    {
        canuse = 1;
        for (j = 0; j < cur; ++ j)
        {
            if (dist[nums[j]][i] < D) {
                canuse = 0;
                break;
            }
        }
        if (canuse) {
            nums[cur] = i;
            findGroups(cur + 1, i + 1);
        }
    }
}

void solve()
{
    fin >> N >> B >> D;
    maxval = (1 << B);
    for (i = 0; i < maxval; ++ i)
    {
        for (j = 0; j < maxval; ++ j)
        {
            int num = i ^ j;
            dist[i][j] = 0;
            while (num != 0)
            {
                if (num & 0x01)
                    dist[i][j] ++;
                num >>= 1;
            }
        }
    }
    nums[0] = 0;
    findGroups(1, 1);
}

int main()
{
    openfile();
    solve();
    closefile();
    return 0;
}
