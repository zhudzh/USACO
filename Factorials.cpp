/*
	ID: zdzapple
	LANG: C++
	TASK: fact4
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

const string input_file = "fact4.in";
const string out_file = "fact4.out";
ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

int N;

int main()
{
    openfile();

    int i, j, k;
    fin >> N;
    int fac = 1;
    for (i = 1; i <= N; ++i)
    {
        fac *= i;
        while (fac % 10 == 0)
            fac /= 10;
        if (fac > 1000)
            fac %= 1000;
    }
    fout << fac%10 << endl;

    closefile();
}
