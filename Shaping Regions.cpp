/*
	ID: zdzapple
	LANG: C++
	TASK: rect1
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

const string input_file = "rect1.in";
const string out_file = "rect1.out";
ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

typedef struct
{
    long px, py, qx, qy, color;
}rectangular;
#define MAX 1001
long A, B, n, cur_c;
long sq[MAX];
rectangular R[MAX];

void compute(long px, long py, long qx, long qy, long posi)
{
    do {
        posi ++;
    } while (posi <= n &&
             (R[posi].px >= qx || R[posi].py >= qy
              || R[posi].qx <= px || R[posi].qy <=py));
    if (posi > n)
        sq[cur_c] += (qx - px) * (qy-py);
    else {
        if (px < R[posi].px) {
            compute(px, py, R[posi].px, qy, posi);
            px = R[posi].px;
        }
        if (qx > R[posi].qx) {
            compute(R[posi].qx, py, qx, qy, posi);
            qx = R[posi].qx;
        }
        if (py < R[posi].py)
            compute(px, py, qx, R[posi].py, posi);
        if (qy > R[posi].qy)
            compute(px, R[posi].qy, qx, qy, posi);
    }
}

int main()
{
    openfile();

    int i, j, k, d;
    int px, py, qx, qy, color;
    fin >> A >> B >> n;

    for (i = 1; i <= n; ++ i)
    {
        fin >> R[i].px >> R[i].py >> R[i].qx >> R[i].qy >> R[i].color;
    }
    R[0].qx = A, R[0].qy = B, R[0].color = 1;
    for (i = n; i >= 0; -- i)
    {
        cur_c = R[i].color;
        compute(R[i].px, R[i].py, R[i].qx, R[i].qy, i);
    }
    for (i = 1; i < MAX; i ++)
        if (sq[i])
            fout << i << " " << sq[i] << endl;
    closefile();
    return 0;
}

