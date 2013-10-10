/*
	ID: zdzapple
	LANG: C++
	TASK: maze1
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

const string input_file = "maze1.in";
const string out_file = "maze1.out";




struct edge
{
    int u;
    vector<int> neighbors;
};
char grid[220][80];
const int MAXE = 80 * 201;
vector<int> sources;
map<int, edge> m;
int W, H;
void addEdge(int u, int v)
{
  //  cout << u << " " << v << endl;
    if (m.find(u) == m.end()) {
        edge n;
        n.u = u;
        n.neighbors.push_back(v);
        m[u] = n;
    } else
        m[u].neighbors.push_back(v);


}

void lookexit(int r, int c)
{
    if (grid[r][c] == ' ')
    {
        int u = ((r-1) / 2) * W + (c-1) / 2;
        sources.push_back(u);
        cout << u << endl;
    }
}
bool isVisited[MAXE];
int minSteps[MAXE];
int findMaxPath(int s)
{
    queue<int> q;

    q.push(s);
    int steps = 1, curLevel = 1, nextLevel = 0;
    int i, j;
    for (i = 0; i <= W * H; ++ i)
        isVisited[i] = false;
    minSteps[s] = 1;
    isVisited[s] = true;
    while (true)
    {
        while (curLevel --)
        {
            int u = q.front();
            q.pop();

            vector<int> neighbors = m[u].neighbors;
            for (i = 0; i < neighbors.size(); ++ i)
            {
                if (!isVisited[neighbors[i]]) {
                    q.push(neighbors[i]);
                    isVisited[neighbors[i]] = true;
                    nextLevel ++;
                    minSteps[neighbors[i]] = min(minSteps[neighbors[i]], steps + 1);
                }

            }
        }
        steps ++;
        curLevel = nextLevel;
        nextLevel = 0;
        cout << curLevel << endl;
        if (curLevel == 0)
            break;

    }
    steps = 0;
    for (i = 0; i < W * H; ++ i)
    {
       // if (minSteps[i] != INT_MAX)
   //         cout << minSteps[i] << " ";
    }
   // cout << endl;
    return steps + 1;
}

void solve()
{
    FILE *fin, *fout;
    int n = W * H, i, j;

    fin = fopen("maze1.in", "r");
    fout = fopen("maze1.out", "w");

    fscanf(fin, "%d %d\n", &W, &H);

    int row = H * 2 + 1;
    int col = W * 2 + 1;
    for(i=0; i<row; i++)
        fgets(grid[i], sizeof(grid[i]), fin);


    cout << W << H << endl;
    for (i = 0; i < row; ++ i)
    {

        for (j = 0; j < col; ++ j)
        {
          //  grid[i][j]= str[j];
         //   cout << grid[i][j];
        }
      //  cout << endl;
    }
    for (i = 1; i < col; i += 2)
    {
        lookexit(0, i);
        lookexit(row - 1, i);
    }
    for (i = 1; i < row; i += 2 )
    {
        lookexit(i, 0);
        lookexit(i, col - 1);
    }
    for (i = 0; i < H; ++ i)
        for (j = 0; j < W; ++ j)
    {
        if (grid[i*2][j*2+1] == ' ' && i != 0)
            addEdge(i*W+j, (i-1)*W+j);
        if (grid[i*2+1][j*2+2] == ' ' && j != W-1)
            addEdge(i*W+j, i*W+j+1);
        if (grid[i*2+2][j*2+1] == ' ' && i != H-1)
            addEdge(i*W+j, (i+1)*W+j);
        if (grid[i*2+1][j*2] == ' ' && j != 0)
            addEdge(i*W+j, i*W+j-1);
    }
    for (i = 0; i <= W * H; ++ i)
        minSteps[i] = INT_MAX;
    findMaxPath(sources[0]);
    findMaxPath(sources[1]);
    int ms = 0;
    for (i = 0; i < W*H; ++ i)
        ms = max(ms, minSteps[i]);

fprintf(fout, "%d\n", ms);
}

int main()
{
   // openfile();
    solve();
   // closefile();
    return 0;
}
