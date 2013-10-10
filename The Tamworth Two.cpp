/*
	ID: zdzapple
	LANG: C++
	TASK: ttwo
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

const string input_file = "ttwo.in";
const string out_file = "ttwo.out";

ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }


//多源最短路径,floyd_warshall算法,复杂度O(n^3)
//求出所有点对之间的最短路经,传入图的大小和邻接阵
//返回各点间最短距离min[]和路径pre[],pre[i][j]记录i到j最短路径上j的父结点
//可更改路权类型,路权必须非负!
#define MAXN 200
#define inf 1000000000
typedef int elem_t;

void floyd_warshall(int n,elem_t mat[][MAXN],elem_t min[][MAXN],int pre[][MAXN]){
	int i,j,k;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			min[i][j]=mat[i][j],pre[i][j]=(i==j)?-1:i;
	for (k=0;k<n;k++)
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				if (min[i][k]+min[k][j]<min[i][j])
					min[i][j]=min[i][k]+min[k][j],pre[i][j]=pre[k][j];
}

char grid[10][10];

/* delta x, delta y position for moving north, east, south, west */
int directionY[] = { 0, 1, 0, -1 };
int directionX[] = { -1, 0, 1, 0 };
int steps = 0;

void move(int &x, int &y, int &d)
{
    int i, j;
    int nx = x + directionX[d];
    int ny = y + directionY[d];
    if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10 || grid[nx][ny] == 1) {
        d = (d + 1) % 4;
    } else {
        x = nx;
        y = ny;
    }
}

void solve()
{
    int i, j, fx, fy, cx, cy;
    int cd = 0, fd = 0;
    char ch;
    for (i = 0; i < 10; ++i)
    {
        for (j = 0; j< 10; ++ j)
        {
            fin >> ch;
            if (ch == '*')
                grid[i][j] = 1;
            else
                grid[i][j] = 0;
            if (ch == 'F')
                fx = i, fy = j;
            if (ch == 'C')
                cx = i, cy = j;
        }
    }
    for (i = 0; i < 160000 && (cx != fx || cy != fy); ++ i)
    {
        move(cx, cy, cd);
        move(fx, fy, fd);
        steps ++;
    }
    if (cx == fx && cy == fy)
        fout << steps << endl;
    else
        fout << 0 << endl;
}

int main()
{
    openfile();
    solve();
    closefile();
    return 0;
}
