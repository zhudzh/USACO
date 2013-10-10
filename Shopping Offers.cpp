/*
	ID: zdzapple
	LANG: C++
	TASK: shopping
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

const string input_file = "shopping.in";
const string out_file = "shopping.out";
ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

struct Reduce
{
    int items[5];
    int nums[5];
    int n;
    int price;
};
struct product
{
    int code;
    int k;
    int p;
};
int s;
product products[6];
Reduce reduces[100];
int dp[6][6][6][6][6];

int main(int argc, char **argv)
{
    openfile();

    int i, j, k, n, p, c, b;
    int i1, i2, i3, i4, i5;
    for (i = 0; i < 100; ++ i)
    {
        memset(reduces[i].items, 0, sizeof(reduces[i].items));
        memset(reduces[i].nums, 0, sizeof(reduces[i].nums));
    }
    for (i = 0; i < 6; ++ i)
        products[i].k = products[i].p = 0;

    fin >> s;
    for (i = 0; i < s; ++ i)
    {
        fin >> n;
        for (j = 0; j < n; ++ j)
        {
            fin >> reduces[i].items[j] >> reduces[i].nums[j];

        }
        reduces[i].n = n;
        fin >> p;
        reduces[i].price = p;
    }
    fin >> b;
    int codeToIndex[1000];
    for (i = 0; i < b; ++ i)
    {
        fin >> products[i].code >> products[i].k >> products[i].p;
        codeToIndex[products[i].code] = i;
    }

    for (i1 = 0; i1 <= products[0].k; ++ i1)
    for (i2 = 0; i2 <= products[1].k; ++ i2)
    for (i3 = 0; i3 <= products[2].k; ++ i3)
    for (i4 = 0; i4 <= products[3].k; ++ i4)
    for (i5 = 0; i5 <= products[4].k; ++ i5)
    {

        dp[i1][i2][i3][i4][i5] = i1 * products[0].p + i2 * products[1].p
                + i3 * products[2].p + i4 * products[3].p + i5 * products[4].p;
        for (j = 0; j < s; ++ j)
        {
            Reduce r = reduces[j];
            int index[] = {i1, i2, i3, i4, i5};
            for (k = 0; k < r.n; ++ k)
            {
                int in = codeToIndex[r.items[k]];
            //    if (i1 == 1 && i2 == 2)
            //        cout << in <<index[in] << " " <<r.items[k] << " " << r.nums[k] << endl;
                if (index[in] < r.nums[k])
                    break;
                index[in] -= r.nums[k];
            }
           // if (i1 == 1 && i2 == 2)
         //       cout << index[0] <<index[1]<<index[2]<<index[3]<<index[4]<<endl;
            if (k >= r.n) {
                dp[i1][i2][i3][i4][i5] = min(dp[i1][i2][i3][i4][i5],
                dp[index[0]][index[1]][index[2]][index[3]][index[4]] + r.price);
            }
          
        }
    }
    fout << dp[products[0].k][products[1].k][products[2].k][products[3].k][products[4].k] << endl;

    closefile();

    return 0;
}
