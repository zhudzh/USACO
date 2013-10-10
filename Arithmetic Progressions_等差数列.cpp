/*
ID: zdzapple
LANG: C++
TASK: ariprog
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstring>
 
using namespace std;
ifstream fin("ariprog.in");
ofstream fout("ariprog.out");
const long M_MAX=250;
const long LIMIT=M_MAX*M_MAX*2;
long N,M;
vector<long> vBisquare;
bool bNumIsBisquare[(M_MAX)*(M_MAX)*2+1];
bool bFindAnswer=false;
typedef struct tagProgression
{
	int a0;
	int d;
}Progression;
vector<Progression> vProg;
 
 
void AddInVector(long x)
{
	vBisquare.push_back(x);
}
 
void InitData()
{
	long i,j;
	memset(bNumIsBisquare, false, sizeof(bNumIsBisquare));
	vBisquare.clear();
	for (i=0;i<=M;++i)
		for (j=i;j<=M;++j)
		{
			bNumIsBisquare[i*i+j*j]=true;
		}
	for (i=0;i<M*M*2+1;++i)
	{
		if (bNumIsBisquare[i]==true)
			AddInVector(i);
	}
}
 
bool CheckProgression(long a0, long d)
{
	long i;
	for (i=1; i<N;++i)
	{
		a0+=d;
		if (!bNumIsBisquare[a0])
			return false;
	}
	return true;
}
 
 
void AddToAnswer(int a0, int d)
{
	Progression p;
	p.a0 = a0;
	p.d = d;
	vProg.push_back(p);
}
 
void BubbleSortAnswer()
{
	for (int i=0;i<vProg.size()-1;++i)
	{
		for (int j=0;j<vProg.size()-1-i;++j)
		{
			if (vProg[j].d>vProg[j+1].d)
			{
				Progression t;
				t=vProg[j]; vProg[j]=vProg[j+1]; vProg[j+1]=t;
			}
		}
	}
}
void PrintAnswer()
{
	for (int i=0;i<vProg.size();++i)
		fout << vProg[i].a0 << " " << vProg[i].d << endl;
}
 
void SearchSeq()
{
	long d;
 
	for (int i=0;i<vBisquare.size()-1;++i)
	{
		int a0=vBisquare[i];
		for (int j=i+1;j<vBisquare.size();++j)
		{
			d=vBisquare[j]-a0;
			if (a0+d*(N-1) > LIMIT) break;
			if (CheckProgression(a0,d))
			{
				bFindAnswer=true;
				AddToAnswer(a0,d);
			}
		}
	}
}
 
bool CheckFoundAnswer()
{
	if (!bFindAnswer)
		return false;
	else return true;
}
 
int main()
{
 
	fin >> N;
	fin >> M;
 
	InitData();
 
	SearchSeq();
 
	if (CheckFoundAnswer())
	{
		BubbleSortAnswer();
		PrintAnswer();
	}
	else
	{
		fout << "NONE" << endl;
	}
	fin.close();
	fout.close();
    return 0;
}