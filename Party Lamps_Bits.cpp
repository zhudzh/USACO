/*
	ID: zdzapple
	LANG: C++
	TASK: lamps
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

const string input_file = "lamps.in";
const string out_file = "lamps.out";

ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

int N, C;
int state[17][7];
int onState[7], onStateNum;
int offState[7], offStateNum;
int LAMP = 6;
set<vector<int> > s;

void solve()
{
    fin >> N >> C;
    int number;
    int i, j, k;
    onStateNum = offStateNum = 0;
    while (fin >> number)
    {
        if (number == -1)
            break;
        while (number > 6)
            number -= 6;
        for (i = 0; i < onStateNum; ++ i)
            if (onState[i] == number)
                continue;
        onState[onStateNum ++] = number;
    }
    while (fin >> number)
    {
        if (number == -1) break;
        while (number > 6)
            number -= 6;
        for (i = 0; i < offStateNum; ++ i)
            if (offState[i] == number)
                continue;
        offState[offStateNum ++] = number;
    }
    // first 6 lamps have 128 states
    while (C > 4)
        C -= 2;
    for (i = 0; i < 16; ++ i)
    {
        for (j = 0; j < 7; ++ j)
            state[i][j] = 1;
        int counter = 0, ii = i;
        for (j = 1; j <= 4; ++ j)
        {
            int bit = ii & 0x01;
            ii >>= 1;
            if (bit)
                counter ++;
        }
        cout << counter << endl;
        if (!(counter == C || (C >= counter && C % 2 == counter % 2)))
            continue;
        ii = i;
        for (j = 1; j <= 4; ++ j)
        {
            int bit = ii & 0x01;
            ii >>= 1;
            if (bit) {
                switch (j)
                {
                case 1:
                    for (k = 1; k <= LAMP; ++ k)
                        state[i][k] = 1 - state[i][k];
                    break;
                case 2:
                    for (k = 1; k <= LAMP; k += 2)
                        state[i][k] = 1 - state[i][k];
                    break;
                case 3:
                    for (k = 2; k <= LAMP; k += 2)
                        state[i][k] = 1 - state[i][k];
                    break;
                case 4:
                    state[i][1] = 1 - state[i][1];
                    state[i][4] = 1 - state[i][4];
                    break;
                }
            }
        }
        // check

        bool isSucess = true;
        for (j = 1; j <= LAMP; ++ j)
        {
            for (k = 0; k < onStateNum; ++ k)
                if (state[i][onState[k]] != 1) {
                    isSucess = false;
                    break;
                }
        }
        if (isSucess)
        {
            for (j = 1; j <= LAMP; ++ j)
            {
                for (k = 0; k < offStateNum; ++ k)
                    if (state[i][offState[k]] != 0) {
                        isSucess = false;
                        break;
                    }
            }
        }
        if (isSucess) {
            vector<int> result(N, 0);
            int index = 1;
            while (index <= N)
            {
                int t = index;
                while (t > 6)
                    t -= 6;
                result[index - 1] = state[i][t];
                index ++;
            }
            s.insert(result);
        }
    }
	if (s.empty()) {
		fout << "IMPOSSIBLE" << endl;
		exit(0);
	}
    set<vector<int> >::iterator it = s.begin();
    while (it != s.end())
    {
        vector<int> v = *it;
        for (i = 0; i < v.size(); ++ i)
            fout << v[i];
        fout << endl;
        it ++;
    }
}

int main()
{
    openfile();
    solve();
    closefile();
    return 0;
}
