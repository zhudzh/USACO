/*
	ID: zdzapple
	LANG: C++
	TASK: kimbits
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

const string input_file = "kimbits.in";
const string out_file = "kimbits.out";
ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

int N, L;
long long I;
int bits[32];
long long sizeofBits[33][33];
int initSizeOfBits()
{
    int i, j;
    for (i = 0; i <= 32; ++ i)
        sizeofBits[0][i] = 1;
    for (i = 1; i <= 32; ++ i)
    for (j = 0; j <= 32; ++ j)
        if (j == 0)
            sizeofBits[i][j] = 1;
        else
            sizeofBits[i][j] = sizeofBits[i-1][j-1] + sizeofBits[i-1][j];
}

void printBits(int number, int ones, long long index)
{
    if (number == 0)
        return;
    long long s = sizeofBits[number-1][ones];
    if (s <= index) {
        fout << 1;
        printBits(number-1, ones-1, index-s);
    } else {
        fout << 0;
        printBits(number-1, ones, index);
    }
}

int main()
{
    openfile();
    int i, j, k;

    fin >> N >> L >> I;
    initSizeOfBits();
    printBits(N, L, I-1);
    fout << endl;
    closefile();
}
