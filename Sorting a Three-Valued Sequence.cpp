/*
	ID: zdzapple
	LANG: C++
	TASK: sort3
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

const string input_file = "sort3.in";
const string out_file = "sort3.out";

ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

int i, j, N;
vector<int> nums;


void solve()
{
    int n;
    fin >> N;
    int count[4] = {0};
    int sn[4][4] = {0};
    for (i = 1; i <= N; ++ i)
    {
        fin >> n;
        nums.push_back(n);
        count[n] ++;
    }
    int index = 0;
    for (i = 1; i <= 3; ++ i)
    {
        for (j = 1; j <= count[i]; ++ j)
        {
            sn[i][nums[index ++]] ++;
        }
    }
    int result = 0;
    for (i = 1; i <= 3; ++ i)
    {
        for (j = i + 1; j <= 3; ++ j)
        {
            int s = min(sn[i][j], sn[j][i]);
            result += s;
            sn[i][j] -= s;
            sn[j][i] -= s;
        }
    }
    result += 2 * (sn[1][2] + sn[1][3]);
    fout << result << endl;

}

int main()
{
    openfile();
    solve();
    closefile();
    return 0;
}
