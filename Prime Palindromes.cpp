/*
	ID: zdzapple
	LANG: C++
	TASK: pprime
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

ifstream fin ("pprime.in");
ofstream fout ("pprime.out");

string A, B;
int en[]= {1,10,100,1000,10000,100000};
int a, b;
int opp[100005];
void opposit()
{
    int num, temp, i;
    for (i = 1; i <= 10000; i ++)
    {
        num = i;
        temp = 0;
        while(num)
        {
            temp = temp*10 + num%10;
            num /= 10;
        }
        opp[i] = temp;
    }
}
void isprim(int x)
{
    if (x < a || x > b)
        return;
    if ((x%5==0&&x!=5)||x%3==0)
        return;
    if (x%11==0&&x!=11)
        return;
    if (x%2==0)
        return;
    int m = sqrt(x);
    for (int i = 2; i <= m; i++)
        if(x%i == 0)
            return;
    fout << x << endl;
}
void odd(int len)
{
    len = (len-1) / 2;
    int i, m, prim;
    for(i=en[len-1]; i<en[len]; i++)
        for(m=0; m<=9; m++)
        {
            prim=i*en[len+1]+m*en[len]+opp[i];
            isprim(prim);
        }
}
void even(int len)
{
    len/=2;
    int i,prim;
    for(i=en[len-1]; i<en[len]; i++)
    {
        prim=i*en[len]+opp[i];
        isprim(prim);
    }
}
int main()
{

    fin >> A >> B ;
    int a1 = A.size();
    int b1 = B.size();
    a = atoi(A.c_str());
    b = atoi(B.c_str());
    int len;
    opposit();
    for(len = a1; len <= b1; len ++)
    {
        if (len & 1)
            odd(len);
        else
            even(len);
    }
    return 0;
}
