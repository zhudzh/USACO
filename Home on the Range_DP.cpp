/*
	ID: zdzapple
	LANG: C++
	TASK: range
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXN 250

int goodsq[MAXN][MAXN];
int bigsq[MAXN][MAXN];
int tot[MAXN+1];

int
min(int a, int b)
{
    return a < b ? a : b;
}

int
main(void)
{
    FILE *fin, *fout;
    int i, j, k, l, n, sz;

    fin = fopen("range.in", "r");
    fout = fopen("range.out", "w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%d\n", &n);

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            goodsq[i][j] = (getc(fin) == '1');
        assert(getc(fin) == '\n');
    }

    /* calculate size of biggest square with lower right corner (i,j) */
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            for(k=i; k>=0; k--)
                if(goodsq[k][j] == 0)
                    break;

            for(l=j; l>=0; l--)
                if(goodsq[i][l] == 0)
                    break;

            sz = min(i-k, j-l);
            if(i > 0 && j > 0)
                sz = min(sz, bigsq[i-1][j-1]+1);

            bigsq[i][j] = sz;
        }
    }

    /* now just count squares */
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            for(k=2; k<=bigsq[i][j]; k++)
                tot[k]++;

    for(i=2; i<=n; i++)
        if(tot[i])
            fprintf(fout, "%d %d\n", i, tot[i]);

    return 0;
}
