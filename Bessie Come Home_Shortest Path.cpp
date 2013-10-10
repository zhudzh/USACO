/*
	ID: zdzapple
	LANG: C++
	TASK: comehome
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

const string input_file = "comehome.in";
const string out_file = "comehome.out";
ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }


int edgeNum = 0;
int dist[52][52];
int m[256];
int main()
{
    openfile();

    int i, j, d;
    char ch1, ch2;
    for (i = 0; i < 256; ++ i)
        m[i] = -1;
    fin >> edgeNum;
    int index = 0;
    for (i = 0; i < 52; ++ i)
    for (j = 0; j < 52; ++ j)
        dist[i][j] = 60000 ;
    for (i = 0; i < 52; ++ i)
        dist[i][i] = 0;
    for (i = 0; i < edgeNum; ++ i)
    {
        fin >> ch1 >> ch2 >> d;
        if (m[ch1] == -1)
            m[ch1] = index ++;
        if (m[ch2] == -1)
            m[ch2] = index ++;
        if (dist[m[ch1]][m[ch2]] > d)
            dist[m[ch1]][m[ch2]] = dist[m[ch2]][m[ch1]] = d;
    }

    /* floyd warshall all pair shortest path */
    for(int k=0; k<52; k++)
    for(i=0; i<52; i++)
    for(j=0; j<52; j++)
    if(dist[i][k]+dist[k][j] < dist[i][j])
        dist[i][j] = dist[i][k]+dist[k][j];


    int result = INT_MAX;
    char cow;
    for (i = 'A'; i <= 'Y'; ++ i)
    {
        if (m[i] != -1) {
              //  cout << dist[m[i]][m['Z']] << endl;
            if (result > dist[m[i]][m['Z']])
                result = dist[m[i]][m['Z']], cow = i;
        }
    }

    fout << cow << " " << result << endl;

    closefile();
    return 0;
}

