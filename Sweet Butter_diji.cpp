/*
	ID: zdzapple
	LANG: C++
	TASK: butter
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

const string input_file = "butter.in";
const string out_file = "butter.out";
ifstream fin;
ofstream fout;

void openfile() { fin.open(input_file.c_str()); fout.open(out_file.c_str()); }
void closefile() { fin.close(), fout.close(); }

#define MAXPASTURE 801
#define MAXN 801
#define INF INT_MAX
#define MIN(X,Y) ((X)<(Y)?(X):(Y))

int n,p,c;
int pastureOfCow[MAXN];

//单源最短路径,dijkstra算法+二分堆,邻接表形式,复杂度O(mlogm)
//求出源s到所有点的最短路经,传入图的大小n和邻接表list
//返回到各点最短距离min[]和路径pre[],pre[i]记录s到i路径上i的父结点,pre[s]=-1
//可更改路权类型,但必须非负!

typedef int elem_t;
struct edge_t{
	int from,to;
	elem_t len;
	edge_t* next;
	edge_t(){next = NULL;}
	edge_t(int _f, int _t, int _len)
	{
	    from = _f, to = _t, len = _len;
	    next = NULL;
	}
};

#define _cp(a,b) ((a).d<(b).d)
struct heap_t{elem_t d;int v;};
struct heap{
	heap_t h[MAXN*MAXN];
	int n,p,c;
	void init(){n=0;}
	void ins(heap_t e){
		for (p=++n;p>1&&_cp(e,h[p>>1]);h[p]=h[p>>1],p>>=1);
		h[p]=e;
	}
	int del(heap_t& e){
		if (!n) return 0;
		for (e=h[p=1],c=2;c<n&&_cp(h[c+=(c<n-1&&_cp(h[c+1],h[c]))],h[n]);h[p]=h[c],p=c,c<<=1);
		h[p]=h[n--];return 1;
	}
};

void dijkstra(int n,edge_t* list[],int s,elem_t* min,int* pre){
	heap h;
	edge_t* t;heap_t e;
	int v[MAXN],i;
	for (i=0;i<n;i++)
		min[i]=INF,v[i]=0,pre[i]=-1;

	h.init();min[e.v=s]=e.d=0,h.ins(e);
	while (h.del(e))
		if (!v[e.v])
			for (v[e.v]=1,t=list[e.v];t;t=t->next)
				if (!v[t->to]&&min[t->from]+t->len<min[t->to])
					pre[t->to]=t->from,min[e.v=t->to]=e.d=min[t->from]+t->len,h.ins(e);
}

edge_t* list[MAXPASTURE];
int dist[MAXPASTURE];
int pre[MAXPASTURE];
void insertEdge()
{
    int i;
    for (i = 1; i <= c; i++)
    {
		int u, v, cost;
        fin >> u >> v >> cost;
		//u->v
		u--, v--;
		edge_t* t = list[u];
        if (t == NULL)
            list[u] = new edge_t(u, v, cost);
        else {
            while (t->next != NULL)
                t = t->next;
            t->next = new edge_t(u, v, cost);
        }


		//v->u
		t = list[v];
		if (t == NULL)
            list[v] = new edge_t(v, u, cost);
        else {
            while (t->next != NULL)
                t = t->next;
            t->next = new edge_t(v, u, cost);
        }
	}

}

int solve()
{
    int i, j;
	int min = INF;
	for (i = 0; i < p; i ++)
    {//选择第i个pasture
		dijkstra(p, list, i, dist, pre);

		int cost = 0;
		for (j = 1; j <= n; j ++)
        {
			cost += dist[pastureOfCow[j]-1];
		}
		if(cost < min)
			min=cost;

	}
	return min;
}

int main()
{
	openfile();
	//初始化

	int i, j;
	fin >> n >> p >> c;
    //for (i = 0; i < MAXPASTURE; ++ i)
      //  list[i] = new edge_t();

	for(i = 1; i <= n; i ++)
    {
        fin >> pastureOfCow[i];
	}
    insertEdge();
	int ret = solve();
	fout << ret << endl;
	closefile();
	return 0;
}
