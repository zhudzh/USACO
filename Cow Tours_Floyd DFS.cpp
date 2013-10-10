/*
	ID: zdzapple
	LANG: C++
	TASK: cowtour
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

const string input_file = "cowtour.in";
const string out_file = "cowtour.out";
ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

#define INF    INT_MAX

typedef struct Point Point;
struct Point
{
    int x, y;
};

#define MAXPASTURE 150

int N;
double dist[MAXPASTURE][MAXPASTURE];
double diam[MAXPASTURE]; // pt i's longest distance to the pts in its field
double fielddiam[MAXPASTURE];// field j 's diameter
Point pt[MAXPASTURE];
int field[MAXPASTURE];  // the field of pt i
int nfield = 0;

double ptdist(Point a, Point b)
{
    return sqrt((double)(b.x-a.x) * (b.x-a.x) + (double)(b.y-a.y)*(b.y-a.y));
}

void markFiled(int id, int mark)
{
    if (field[id] != -1) {
        assert(field[id] == mark);
        return;
    }
    field[id] = mark;
    for (int i = 0; i < N; ++ i)
        if (dist[id][i] < INF / 2 )
            markFiled(i, mark);
}

int main()
{
    openfile();

    double newdiam = INF, d;
    fin >> N;
    int i, j, k;
    for (i = 0; i < N; ++ i)
    {
        fin >> pt[i].x >> pt[i].y;
    }
    for (i = 0; i < N; ++ i)
    {
        for (j = 0; j < N; ++ j)
        {
            char ch;
            fin >> ch;
            if (i == j) {
                dist[i][j] = 0;
            } else if (ch == '0')
                dist[i][j] = INF;
            else
                dist[i][j] = ptdist(pt[i], pt[j]);
        }
    }


    // cal the distance between two pts
    for (k = 0; k < N; k++)
    for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
        if (dist[i][k] + dist[k][j] < dist[i][j])
            dist[i][j] = dist[i][k] + dist[k][j];

    // mark the field using dfs
    for (i = 0; i < N; ++i)
        field[i] = -1;
    for (i = 0; i < N; ++ i)
        if (field[i] == -1)
            markFiled(i, nfield ++);
    // cal the  diameter
    for (i = 0; i < N; ++ i)
        diam[i] = 0;
    for (i = 0; i < nfield; ++ i)
        fielddiam[i] = 0;
    for (i = 0; i < N; ++ i)
    {
        for (j = 0; j < N; ++ j)
            if (diam[i] < dist[i][j] && dist[i][j] < INF / 2)
                diam[i] = dist[i][j];
        if (diam[i] > fielddiam[field[i]])
            fielddiam[field[i]] = diam[i];
    }

    // cal the result
    for (i = 0; i < N; ++ i)
    for (j = 0; j < N; ++ j)
    {
        if (field[i] != field[j]) {
            d = max(diam[i] + diam[j] + ptdist(pt[i], pt[j]),
                    max(fielddiam[field[i]], fielddiam[field[j]]));

            newdiam = min(newdiam, d);
        }
    }
    fout << setiosflags(ios::fixed) << setprecision(6) << newdiam << endl;
    closefile();
    return 0;
}

