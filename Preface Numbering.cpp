/*
	ID: zdzapple
	LANG: C++
	TASK: preface
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

const string input_file = "preface.in";
const string out_file = "preface.out";

ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

int N;

const string encode[] = {"", "I", "II", "III", "IV",
            "V", "VI", "VII", "VIII", "IX", "X"};

string romandigit(int digit, string base)
{
    string result;
    string b = encode[digit % 10];
    if (b.empty())
        return "";
    for (int i = 0; i < b.size(); ++ i)
    {
        switch (b[i])
        {
        case 'I':
            result += base[0];
            break;
        case 'V':
            result += base[1];
            break;
        case 'X':
            result += base[2];
            break;
        }
    }
    return result;
}

string intToRoman(int n)
{
    string result = "";
    result += romandigit(n / 1000, "M");
    result += romandigit(n / 100,  "CDM");
    result += romandigit(n / 10,   "XLC");
    result += romandigit(n / 1,    "IVX");
    return result;
}

void solve()
{
    int i, j;
    fin >> N;
    int count[256] = {0};
    string s = "IVXLCDM";
    for (i = 1; i <= N; ++ i)
    {
        string r = intToRoman(i);
        for (j = 0; j < r.size(); ++ j)
        {
            count[r[j]] ++;
        }
    }
    for (i = 0; i < s.size(); ++ i)
    {
        if (count[s[i]])
            fout << s[i] << " " << count[s[i]] << endl;
    }
}

int main()
{
    openfile();
    solve();
    closefile();
    return 0;
}
