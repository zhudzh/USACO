/*
	ID: zdzapple
	LANG: C++
	TASK: transform
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

using namespace std;
ifstream fin ("transform.in");
ofstream fout ("transform.out");
char a[11][11], b[11][11], c[11][11];
bool mark;
int n;
int indea(char a[11][11], int k)
{
   char b[11][11];
   for (int i = 1; i <= n; i++)
     for (int j = 1; j <= n; j++)
       b[i][j] = a[i][j];
   for (int i = 1; i <= n; i++)
     for (int j = 1; j <= n; j++)
     {
       if (k == 1) a[i][j] = b[n - j + 1][i];
       if (k == 2) a[i][j] = b[n - i + 1][n - j + 1];
       if (k == 3) a[i][j] = b[j][n - i + 1];
       if (k == 4) a[i][j] = b[i][n - j + 1];
     }  
}
int get(void)
{
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        c[i][j] = a[i][j];
}
bool check(void)
{
   for (int i = 1; i <= n; i++)
     for (int j = 1; j <= n; j++)
       if (c[i][j] != b[i][j])
          return false;       
   return true;
}
int init(char a[11][11])
{
   for (int i = 1; i <= n; i++)
   {
     for (int j = 1; j <= n; j++)
       fin >> a[i][j];
   }
}
int main(void)
{  
 
   fin >> n;
   init(a);
   init(b);
   for (int i = 1; i <= 4; i++)
     { get(); indea(c, i); if (check()) { fout << i << endl; return 0;} }
   for (int i = 1; i <= 3; i++)
   {
     get(); indea(c,4); indea(c,i);
     if (check()) { fout << 5 << endl;  return 0;} 
   }
   get(); if (check()) { fout << 6 << endl; return 0;}
   fout << 7 << endl;  return 0;
}