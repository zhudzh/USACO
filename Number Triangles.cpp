/*
	ID: zdzapple
	LANG: C++
	TASK: numtri
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
ifstream fin ("numtri.in");
ofstream fout ("numtri.out");

int main()
{
	int row;
	fin >> row;
	vector<int> sum(row + 1, 0);
	vector<int> sum2(row + 1, 0);
	for (int i = 1; i <= row; ++ i)
    {
        for (int j = 1; j <= i; ++ j)
        {
            fin >> sum2[j];
        }
        for (int j = i; j >= 1; -- j)
        {
            if (j == 1) {
                sum[j] += sum2[j];
            } else if (j == i) {
                sum[j] = sum[j - 1] + sum2[j];
            } else {
                sum[j] = max(sum[j], sum[j-1]) + sum2[j];
            }
        }
    }
    int result = INT_MIN;
    for (int i = 1; i <= row; ++i)
        if (result < sum[i])
            result = sum[i];
    fout << result << endl;
	return 0;
}
