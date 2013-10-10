/*
	ID: zdzapple
	LANG: C++
	TASK: holstein
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

const string input_file = "holstein.in";
const string out_file = "holstein.out";

ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

int i, j, V, G;
vector<int> minRe;
vector<vector<int> > vitamin;
vector<int> best;
vector<int> ans;
int ansSize = 50000;
vector<int> current;

void dfs(int level)
{

    for (i = 0; i < V; ++ i)
        if (current[i] < minRe[i])
            break;
    if (i == V) {
        if (ansSize > best.size()) {
            ans.assign(best.begin(), best.end());
            ansSize = ans.size();
            //cout << ansSize << endl;
        }
        return;
    }
    if (level == G) {
        return;
    }
    best.push_back(level + 1);
    for (i = 0; i < V; ++ i)
        current[i] += vitamin[level][i];

    dfs(level + 1);
    best.pop_back();
    for (i = 0; i < V; ++ i)
        current[i] -= vitamin[level][i];
    dfs(level + 1);
}

void solve()
{
    fin >> V;
    minRe.assign(V, 0);
    current.assign(V, 0);
    int num;
    for (i = 0; i < V; ++ i)
    {
        fin >> minRe[i];
    }
    fin >> G;
    for (i = 0; i < G; ++ i)
    {
        vector<int> t(V, 0);
        vitamin.push_back(t);
        for (j = 0; j < V; ++ j)
            fin >> vitamin[i][j];
    }
    dfs(0);
    fout << ans.size();
    for (i = 0; i < ans.size(); ++ i)
        fout << " " << ans[i];
    fout << endl;
}

int main()
{
    openfile();
    solve();
    closefile();
    return 0;
}
