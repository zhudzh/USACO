/*
	ID: zdzapple
	LANG: C++
	TASK: game1
*/
#include <fstream>

using namespace std;

#define min(a,b) ((a<b)?a:b)

ifstream fin("game1.in");
ofstream fou("game1.out");

int n;
int sum[101];
int best[101][101];

int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++) {
        fin >> best[i][i];
        sum[i] = sum[i-1] + best[i][i];
    }
   
    for(int i = 1; i <= n; i++)
    for(int j = 1; j+i <= n; j++)
        best[j+i][j] = sum[j+i]-sum[j-1] - min(best[j+i-1][j], best[j+i][j+1]);
    fou << best[n][1] << " " << sum[n] - best[n][1] << endl;
	return 0;
}