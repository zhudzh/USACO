/*
	ID: zdzapple
	LANG: C++
	TASK: castle
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

const string input_file = "castle.in";
const string out_file = "castle.out";

ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

#define maxN 110
int castle[maxN][maxN];
int M, N, row, col;
int numComponents, maxSize = 0;
int maxResultR, maxResultC, maxResultSize = 0;
char direct;
int components[maxN / 2][maxN / 2];
map<int, int> sizeComponents;
int direction[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int wallDirection[2][2] = {{-1, 0}, {0, 1}};

void floodFill(int newComponent)
{
    int numVisited, i, j;
    int maxVisited = 0;
    do {
        numVisited = 0;
        for (i = 1; i <= M; ++ i)
        {
            for (j = 1; j <= N; ++ j)
            {
                if (components[i][j] == -2) {
                    numVisited ++;
                    maxVisited ++;
                    components[i][j] = newComponent;
                    //cout << i << " " << j << endl;
                     // for all neighbors
                    for (int k = 0; k < 4; ++ k)
                    {
                        if (castle[i * 2 + direction[k][0]][j * 2 + direction[k][1]] != 1) {
                            int newRow = i + direction[k][0];
                            int newCol = j + direction[k][1];
                            if (components[newRow][newCol]  == -1) {
                                components[newRow][newCol] = -2;
                            }

                        }

                    }
                }

            }
        }

    } while (numVisited != 0);
    maxSize = max(maxSize, maxVisited);
    sizeComponents[newComponent] = maxVisited;
}

void findComponents()
{
    numComponents = 0, maxSize = 0;
    int i, j;
    for (i = 1; i <= M; ++ i)
    {
        for (j = 1; j <= N; ++ j)
            components[i][j] = -1;
    }
    for (i = 1; i <= M; ++ i)
    {
        for (j = 1; j <= N; ++ j)
        {
            if (components[i][j] == -1) {
                numComponents ++;
                components[i][j] = -2;
                floodFill(numComponents);
            }
        }
    }
    fout << numComponents << endl << maxSize << endl;
    /*for (i = 1; i <= M; ++ i)

    {
        for (j = 1; j <= N; ++ j)
            cout << components[i][j] << " ";
        cout << endl;
    }
    map<int, int>::iterator it = sizeComponents.begin();
    while (it != sizeComponents.end())
        cout << it->second << endl, it ++;*/
}

void readData()
{
    int i, j, num;
    fin >> N >> M;
    row = 2 * M + 1;
    col = 2 * N + 1;
    for (i = 1; i <= row; ++ i)
        for (j = 1; j <= col; ++ j)
        {
            if (i == 1 || j == 1 || i == row || j == col)
                castle[i][j] = 1;
            else
                castle[i][j] = 0;
        }
    for (i = 1; i <= M; ++ i)
    {
        for (j = 1; j <= N; ++ j)
        {
            fin >> num;
            for (int k = 0; k < 4; ++k)
            {
                int bit = num & 0x01;
                if (bit){
                    int wallR = direction[k][0];
                    int wallC = direction[k][1];
                    castle[i * 2 + wallR][j * 2 + wallC] = 1;
                }
                num = num >> 1;
            }
        }
    }
    /*for (i = 1; i <= row; ++ i)

    {
        for (j = 1; j <= col; ++ j)
            cout << castle[i][j] << " ";
        cout << endl;
    }*/

}
void findWall()
{
    int i, j;
    for (j = 1; j <= N; ++ j)
    {
        for (i = M; i >= 1; -- i)
        
        {
            for (int k = 0; k < 2; ++ k)
            {
                int newRow = i * 2 + wallDirection[k][0];
                int newCol = j * 2 + wallDirection[k][1];
                if (newRow == 1 || newRow == row || newCol == 1 || newCol == col)
                    continue;
                if (castle[newRow][newCol] == 1) {
                       if (components[i][j] !=
                           components[i + wallDirection[k][0]][j + wallDirection[k][1]]){
                            int s = sizeComponents[components[i][j]] +
                                sizeComponents[components[i + wallDirection[k][0]][j + wallDirection[k][1]]];
                            if (maxResultSize < s)
                            {
                                maxResultSize = s;
                                maxResultR = i;
                                maxResultC = j;
                                direct = (k == 0 ? 'N' : 'E');
                            }
                       }
                }

            }
        }
    }
    fout << maxResultSize << endl << maxResultR << " " << maxResultC << " " << direct << endl;
}

int main()
{
    openfile();
    readData();
    findComponents();
    findWall();
    closefile();
    return 0;
}
