/*
	ID: zdzapple
	LANG: C++
	TASK: crypt1
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <list>
using namespace std;
 
FILE *in, *out;
 
void openfile() { in = fopen("crypt1.in", "r"); out = fopen("crypt1.out", "w+"); }
void closefile() { fclose(in); fclose(out); }
 
int arr[10], n;
bool ex[10];
 
int main()
{
    openfile();
    fscanf(in, "%d", &n);
    memset(ex, 0, sizeof(ex));
    for(int i = 0; i < n; i++)
    {
        fscanf(in, "%d", arr + i);
        ex[arr[i]] = true;
    }
 
    int r = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                for(int l = 0; l < n; l++)
                    for(int m = 0; m < n; m++)
                    {
                        int a = arr[i] * 100 + arr[j] * 10 + arr[k];
                        int b = a * arr[l], c = a * arr[m], d = b + c * 10;
                        if(b > 1000 || c > 1000 || d > 10000) continue;
                        if(!ex[b % 10] || !ex[c % 10] || !ex[d % 10]) continue;
                        b /= 10, c /= 10, d /= 10;
                        if(!ex[b % 10] || !ex[c % 10] || !ex[d % 10]) continue;
                        d /= 10;
                        if(!ex[b / 10] || !ex[c / 10] || !ex[d % 10] || !ex[d / 10]) continue;
 
                        r++;
                    }
 
    fprintf(out, "%d\n", r);
 
    closefile();
    return 0;
}