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
#define MAXCOW 501
#define MAXPATH 1451
#define INF 0x3c3c3c3c
#define MIN(X,Y) ((X)<(Y)?(X):(Y))

int head[MAXPASTURE];
int e[MAXPATH<<1+1];
int next[MAXPATH<<1+1];
int weight[MAXPATH];
int dist[MAXPASTURE];

int n,p,c;
int pastureOfCow[MAXCOW];

void insertEdge()
{
    int i;
    for(i=1;i<=c;i++){//构造链式前向星结构
		int u,v,cost;
        fin >> u >> v >> weight[i];
		//u->v
		e[i<<1]=v;
		next[i<<1]=head[u];
		head[u]=i<<1;

		//v->u
		e[(i<<1)+1]=u;
		next[(i<<1)+1]=head[v];
		head[v]=(i<<1)+1;
	}
}

void spfa(int s){
	bool inQueue[MAXPASTURE];
	int queue[5*MAXPASTURE+1];
	int p,q;
	memset(dist,INF,sizeof(dist));
	memset(inQueue,false,sizeof(inQueue));

	dist[s]=0;inQueue[s]=true;
	for(queue[p=q=0]=s;p<=q;p++){
		int ei=head[queue[p]];
		for(;ei!=0;ei=next[ei]){
			if(dist[e[ei]] > dist[queue[p]]+weight[ei>>1]){//松驰
				dist[e[ei]]=dist[queue[p]]+weight[ei>>1];
				if(!inQueue[e[ei]]){//入队
					inQueue[e[ei]]=true;
					queue[++q]=e[ei];
				}
			}
		}
		inQueue[queue[p]]=false;
	}
}
int solve(){
	int i,j;
	int min = INF;
	for(i=1;i<=p;i++){//选择第i个pasture
		spfa(i);//计算到i的单源最短路径
		int cost=0;
		for(j=1;j<=n;j++){
			cost+=dist[pastureOfCow[j]];
		}
		if(cost<min)
			min=cost;

	}
	return min;
}


int main(){
	openfile();
	//初始化
	memset(head,0,sizeof(head));
	memset(next,0,sizeof(next));
	int i,j;
	fin >> n >> p >> c;

	for(i=1;i<=n;i++){
        fin >> pastureOfCow[i];
	}
    insertEdge();

	int ret=solve();
	fout << ret << endl;
	closefile();
	return 0;
}
