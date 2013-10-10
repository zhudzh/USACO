/*
	ID: zdzapple
	LANG: C++
	TASK: frac1
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

const string input_file = "frac1.in";
const string out_file = "frac1.out";

ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

int i, j, N;
struct fraction
{
    int p, q;
    fraction(int _p, int _q) : p(_p), q(_q)
    {    }
    bool operator<( const fraction& f ) const
    {
        return p * f.q < q * f.p;
    }

    bool operator==( const fraction& f ) const
    {
        return p * f.q == q * f.p;
    }
};

int gcd(int p, int q)
{
    if (q == 0)
        return p;
    return gcd(q, p % q);
}

bool compare(const fraction &f1, const fraction &f2)
{
    return f1.p * f2.q < f1.q * f2.p;
}

void solve()
{
    fin >> N;
    vector<fraction> fs;
    fs.push_back(fraction(0, 1));
    fs.push_back(fraction(1, 1));
    for (i = 1; i <= N - 1; ++ i)
    {
        for (j = i + 1; j <= N; ++ j)
        {
            int g = gcd(i, j);
            int p = i / g;
            int q = j / g;
            fs.push_back(fraction(p, q));
        }
    }
    sort(fs.begin(), fs.end(), compare);
    fs.erase(unique(fs.begin(), fs.end()), fs.end());
    for (i = 0; i < fs.size(); ++ i)
        fout << fs[i].p << "/" << fs[i].q << endl;
}

int main()
{
    openfile();
    solve();
    closefile();
    return 0;
}
