/*
	ID: zdzapple
	LANG: C++
	TASK: fracdec
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

const string input_file = "fracdec.in";
const string out_file = "fracdec.out";
ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

int N, D;
#define MAXDIGIT 100100

char dec[MAXDIGIT];
int m[MAXDIGIT];
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return(b, a % b);
}

string intToStr(int i)
{
    char temp[64];
    sprintf(temp, "%d", i);
    string str(temp);
    return str;
}

int main()
{
    openfile();

    int i, j, d;
    fin >> N >> D;
    vector<int> decimal;
    string result = intToStr(N / D);
    result += ".";
    int rem = N%D;
for(i = 0; i < MAXDIGIT; i++)
        m[i] = -1;
    int pos = 0;
    while (rem != 0)
    {
        if (m[rem] == -1) {
            m[rem] = pos ++;
         //   cout << rem << " " << m[rem] << endl;
        } else
            break;

        N = rem * 10;
        rem = N%D;
        //cout << rem << " " << N/D << " " << endl;
        decimal.push_back(N/D);

        /* 不是在下面，因为首先要计算出值来，才能判断是否重复
        if (m.find(rem) == m.end()) {
                    m[rem] = pos ++;
                    cout << rem << " " << m[rem] << endl;
                } else
                    break;
        */
    }

    if (rem == 0) {
        pos = decimal.size();
        if (pos == 0)
            result += intToStr(0);
        else
        for (i = 0; i < pos; ++ i)
            result += intToStr(decimal[i]);

    } else {
        pos = m[rem];
        for (i = 0; i < pos; ++ i)
            result += intToStr(decimal[i]); // 可能会出现连续的0，所以一位一位地加

        result += "(";
        for (i = pos; i < decimal.size(); ++ i)
            result += intToStr(decimal[i]);
        result += ")";
    }
    for (int i = 0; i < result.size(); ++ i)
    {
        if (i % 76 == 0 && i != 0)
            fout << endl;
        fout << result[i];
    }
	fout << endl;
    closefile();
    return 0;
}

/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXDIGIT 100100

char dec[MAXDIGIT];
int lastrem[MAXDIGIT];
char buf[MAXDIGIT];

void
main(void)
{
    FILE *fin, *fout;
    int n, d, k, i, rem, len;

    fin = fopen("fracdec.in", "r");
    fout = fopen("fracdec.out", "w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%d %d", &n, &d);
    sprintf(buf, "%d.", n/d);

    for(i=0; i<MAXDIGIT; i++)
	lastrem[i] = -1;

    rem = n % d;
    for(i=0;; i++) {
	if(rem == 0) {
	    if(i == 0)
		sprintf(buf+strlen(buf), "0");
	    else
		sprintf(buf+strlen(buf), "%s", dec);
	    break;
	}
	if(lastrem[rem] != -1) {
	    k = lastrem[rem];
	    sprintf(buf+strlen(buf), "%.*s(%s)", k, dec, dec+k);
	    break;
	}

	lastrem[rem] = i;
	n = rem * 10;
	dec[i] = n/d + '0';
	rem = n%d;
    }

    len = strlen(buf);
    for(i=0; i<len; i+=76) {
    	fprintf(fout, "%.76s\n", buf+i);
    }
    exit(0);
}

*/