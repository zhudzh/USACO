/*
	ID: zdzapple
	LANG: C++
	TASK: zerosum
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

const string input_file = "zerosum.in";
const string out_file = "zerosum.out";

ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

int N;

int eval(string str)
{
    int term = 0, sign = 1, sum = 0;
    for (int i = 0; i < str.size(); ++ i)
    {
        switch (str[i])
        {
        case '+':
        case '-':
            sum += sign * term;
            term = 0;
            sign = str[i] == '+' ? 1 : -1;
            break;
        case ' ':
            break;
        default:
            term = term * 10 - (str[i] - '0');
        }
    }
    sum += sign * term;
    return sum;
}

void dfs(int level, string &current, vector<int> &nums)
{
    if (level == N) {
        if (eval(current) == 0) {
            fout << current << endl;
        }
        return;
    }

    // space
    string s;
    char ch = ('0' + nums[level]);
    string n(1, ch);
    s = current + " " +  n;
    dfs(level + 1, s, nums);
    // plus
    s = current + "+" + n;
    dfs(level + 1, s, nums);
    // sub
    s = current + '-' + n;
    dfs(level + 1, s, nums);


}

void solve()
{
   fin >> N;
   vector<int> nums;
   for (int i = 1; i <= N; ++ i)
   {
       nums.push_back(i);
   }
   int sum = 1;
   string current = "1";
   dfs(1, current, nums);
}

int main()
{
    openfile();
    solve();
    closefile();
    return 0;
}
