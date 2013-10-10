/*
	ID: zdzapple
	LANG: C++
	TASK: msquare
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

const string input_file = "msquare.in";
const string out_file = "msquare.out";
ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

struct node
{
    string squares;
    string trans;
    int d;
    node(string _s, string _t, int _d)
    {
        squares = _s; trans = _t; d = _d;
    }
};
string target = "";
string defaultT = "12345678";
set<string> s;
queue<node> q;

node bfs()
{
    node result("", "", 0);
    s.insert(defaultT);
    q.push(node(defaultT, "", 0));
    if (target == defaultT) return node("", "", 0);
    while (!q.empty())
    {
        node n = q.front();
        q.pop();
        // A
        string temp = n.squares;
        reverse(temp.begin(), temp.end());
        string t = temp;
        if (t == target) return node(t, n.trans + "A", n.d + 1);
        if (s.find(t) == s.end()) {
            s.insert(t);
            q.push(node(t, n.trans + "A", n.d + 1));
        }
        // B
        t = n.squares.substr(3, 1) + n.squares.substr(0, 3) +
            n.squares.substr(5, 3) + n.squares.substr(4, 1);
        if (t == target) return node(t, n.trans + "B", n.d + 1);
        if (s.find(t) == s.end()) {
            s.insert(t);
            q.push(node(t, n.trans + "B", n.d + 1));
        }
        // C
        t = n.squares;
        t[1] = n.squares[6], t[2] = n.squares[1], t[5] = n.squares[2], t[6] = n.squares[5];
        if (t == target) return node(t, n.trans + "C", n.d + 1);
        if (s.find(t) == s.end()) {
            s.insert(t);
            q.push(node(t, n.trans + "C", n.d+1));
        }
    }
}

int main()
{
    openfile();
    int i, j;

    for (i = 0; i < 8; ++ i)
    {
        fin >> j;
        target += ('0'+j);
    }
    node n = bfs();
    fout << n.d << endl << n.trans << endl;

    closefile();
}
