/*
	ID: zdzapple
	LANG: C++
	TASK: concom
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

const string input_file = "concom.in";
const string out_file = "concom.out";

ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }


#define NCOM 101

int owns[NCOM][NCOM];        /* [i,j]: how much of j do i and its
                                controlled companies own? */
int controls[NCOM][NCOM];    /* [i, j]: does i control j? */

void addController(int a, int b)
{
    if (a == b)
        return;
    if (controls[a][b] == 1)
        return;
    controls[a][b] = 1;
    int i, j;
    for (i = 0; i < NCOM; ++ i)
    {
        owns[a][i] += owns[b][i];
    }
    for (i = 0; i < NCOM; ++ i)
    {
        if (controls[i][a])
            addController(i, b);
    }
    for (i = 0; i < NCOM; ++ i)
    {
        if (owns[a][i] > 50)
            addController(a, i);
    }
}

void addowner(int a, int b, int p)
{
    if (a == b)
        return;
    int i, j;
    for (i = 0; i < NCOM; ++ i)
    {
        if (controls[i][a])
            owns[i][b] += p;
    }

    for (i = 0; i < NCOM; ++ i)
        if (owns[i][b] > 50)
            addController(i, b);

}

void solve()
{
    int i, j, n, a, b, p;
    fin >> n;
    for (i = 0; i < NCOM; i++)
        controls[i][i] = 1;
    for (i = 0; i < n; i ++)
    {
        fin >> a >> b >> p;
        addowner(a, b, p);
    }
    for (i = 0; i < NCOM; i++)
    for (j = 0; j < NCOM; j++)
        if(i != j && controls[i][j])
            fout << i << " " << j << endl;
}

int main()
{
    openfile();
    solve();
    closefile();
    return 0;
}
