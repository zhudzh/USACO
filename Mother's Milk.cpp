/*
	ID: zdzapple
	LANG: C++
	TASK: milk3
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
#include <string.h>
#include <iomanip>
#include <stdlib.h>
 
using namespace std;
 
ifstream fin ("milk3.in");
ofstream fout ("milk3.out");
 
long ans[50],p=-1;
long a,b,c;      //各桶上限 
bool found[50][50][50];     //搜索记录 
 
bool isIn(long C)
{
     bool in=false;
     for (long i=0;i<=p;i++)
     {
         if (ans[i]==C)
         {
            in=true;
            break;
         }
     }
     return in;
}
 
void DFS(long A,long B,long C)
{
     if (found[A][B][C]) return;
     found[A][B][C]=true;
     if (A==0)
     {
        if (!isIn(C))
        {
           ans[++p]=C;
        }
     }
     if (A<=b-B) DFS(0,B+A,C);             //A->B     
     else DFS(A-(b-B),b,C);
     if (A<=c-C) DFS(0,B,C+A);             //A->C
     else DFS(A-(c-C),B,c);
     if (B<=a-A) DFS(A+B,0,C);             //B->A     
     else DFS(a,B-(a-A),C);
     if (B<=c-C) DFS(A,0,C+B);             //B->C
     else DFS(A,B-(c-C),c);
     if (C<=a-A) DFS(A+C,B,0);             //C->A     
     else DFS(a,B,C-(a-A));
     if (C<=b-B) DFS(A,B+C,0);             //C->B
     else DFS(A,b,C-(b-B));
     return;
}
 
int main()
{
    memset (ans,0,sizeof(ans));
    memset (found,0,sizeof(found));
    fin >>a >>b >>c;
    DFS(0,0,c);
    sort(ans,ans+p+1);
    for (long i=0;i<=p;i++)     //输出
    {
        if (i!=0) fout <<' ';
        fout <<ans[i];
    }
    fout <<endl;
    return 0;
}

/**
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#define MAX 20

typedef struct State	State;
struct State {
    int a[3];
};

int seen[MAX+1][MAX+1][MAX+1];
int canget[MAX+1];

State
state(int a, int b, int c)
{
    State s;

    s.a[0] = a;
    s.a[1] = b;
    s.a[2] = c;
    return s;
}

int cap[3];

/* pour from bucket "from" to bucket "to" */
State
pour(State s, int from, int to)
{
    int amt;

    amt = s.a[from];
    if(s.a[to]+amt > cap[to])
	amt = cap[to] - s.a[to];

    s.a[from] -= amt;
    s.a[to] += amt;
    return s;
}

void
search(State s)
{
    int i, j;

    if(seen[s.a[0]][s.a[1]][s.a[2]])
	return;

    seen[s.a[0]][s.a[1]][s.a[2]] = 1;

    if(s.a[0] == 0)	/* bucket A empty */
	canget[s.a[2]] = 1;

    for(i=0; i<3; i++)
    for(j=0; j<3; j++)
	search(pour(s, i, j));	
}

void
main(void)
{
    int i;
    FILE *fin, *fout;
    char *sep;

    fin = fopen("milk3.in", "r");
    fout = fopen("milk3.out", "w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%d %d %d", &cap[0], &cap[1], &cap[2]);

    search(state(0, 0, cap[2]));

    sep = "";
    for(i=0; i<=cap[2]; i++) {
	if(canget[i]) {
	    fprintf(fout, "%s%d", sep, i);
	    sep = " ";
	}
    }
    fprintf(fout, "\n");

    exit(0);
}



**/