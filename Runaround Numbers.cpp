/*
	ID: zdzapple
	LANG: C++
	TASK: runround
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
using namespace std;
ifstream fin("runround.in");
ofstream fout("runround.out");

int a[10];
int num;

void trans(unsigned int n)
{
    num = 0;
    int temp = n;
    int i = 0;


    while (temp != 0)
    {
        temp /= 10;
        num ++;
    }


    while ((n/10) != 0)
    {
        a[num-i] = n % 10;
        n /= 10;
        i ++;
    }
    a[1] = n;
}


bool all(char vis[])
{
    for (int i = 1; i <= num; i ++)
        if (!vis[i]) return false;
    return true;
}


bool judge(unsigned int n)
{
    int ill = 1;
    trans(n);

    for (int i = 1; i <= num; i ++)
        if (a[i] == 0) return false;

    int hash[10];

    memset(hash, 0, sizeof(hash));
    for (int i = 1; i <= num; i ++)
        {
            hash[a[i]] ++;
            if (hash[a[i]] > 1) return false;
        }


    char vis[10] = {0};

    while( !all(vis))
    {
        ill = (ill + a[ill]) % num;
        if (ill == 0) ill = num;
        if (vis[ill] == 1)    return false;
        vis[ill] = 1;
    }
    if (ill == 1) return true;
        else return false;


}


int main()
{
    unsigned int n;
    fin >> n;
    for (int i = n+1; ;i ++)
    {
        memset(a, 0, sizeof(a));
        if (judge(i))
        {
            fout << i << endl;
            return 0;
        }
    }


    return 0;
}