/*
	ID: zdzapple
	LANG: C++
	TASK: contact
*/
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
#define CLEAR(a,val) memset(a,val,sizeof (a))
#define FOR(i,a,b)   for(int i=(a);i<(b);i++)
#define FORE(i,a,b)  for(int i=(a);i<=(b);i++)
#define FORC(c,it)   for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(a)       (a).begin(),(a).end()
typedef long long LL;
using namespace std;
map<string,int> mp;
vector<pair<int,string> > vt;
bool cmp(const pair<int,string> &a,const pair<int,string> &b){
	if (a.first > b.first) return true;
	if (a.first < b.first) return false;
	int an=a.second.size();
	int bn=b.second.size();
	if (an < bn) return true;
	if (an > bn) return false;
	return a.second < b.second;
}
int A,B,N;
int main()
{
	freopen("contact.in","r",stdin);
	freopen("contact.out","w",stdout);	
	string str="";
	string line;
	scanf("%d %d %d%*c",&A,&B,&N);
	while(getline(cin,line)){
		str+=line;
	}
	mp.clear();
	vt.clear();
	FORE(len,A,B){
		for(int i=0;i+len<=str.size();i++){
			mp[str.substr(i,len)]++;
		}
	}
	map<string,int> ::iterator it=mp.begin();
	while(it!=mp.end()){
		vt.push_back(make_pair(it->second,it->first));
		++it;
	}
	sort(ALL(vt),cmp);
	int Pt=0;
	int Old=-1;
	int counter=0;
	int re=0;
	while(Pt<vt.size()){
		if (vt[Pt].first != Old){
			if (re==N) break;
			if (re!=0) printf("\n");
			++re;
			counter=0;
			printf("%d\n%s",vt[Pt].first,vt[Pt].second.c_str());
			Old=vt[Pt++].first;
		}
		else{
			counter++;
			if (counter%6==0){
				printf("\n%s",vt[Pt].second.c_str());
			}else printf(" %s",vt[Pt].second.c_str());
			++Pt;
		}		
	}
	printf("\n");
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXBITS 12
#define MAXSEQ (1<<(MAXBITS+1))

typedef struct Seq Seq;
struct Seq {
    unsigned bits;
    int count;
};

Seq seq[MAXSEQ];

/* increment the count for the n-bit sequence "bits" */
void
addseq(unsigned bits, int n)
{
    bits &= (1<<n)-1;
    bits |= 1<<n;
    assert(seq[bits].bits == bits);
    seq[bits].count++;
}

/* print the bit sequence, decoding the 1<<n stuff */
/* recurse to print the bits most significant bit first */
void
printbits(FILE *fout, unsigned bits)
{
    assert(bits >= 1);
    if(bits == 1)	/* zero-bit sequence */
	return;

    printbits(fout, bits>>1);
    fprintf(fout, "%d", bits&1);
}

int
seqcmp(const void *va, const void *vb)
{
    Seq *a, *b;

    a = (Seq*)va;
    b = (Seq*)vb;

    /* big counts first */
    if(a->count < b->count)
	return 1;
    if(a->count > b->count)
	return -1;

    /* same count: small numbers first */
    if(a->bits < b->bits)
	return -1;
    if(a->bits > b->bits)
	return 1;

    return 0;
}

void
main(void)
{
    FILE *fin, *fout;
    int i, a, b, n, nbit, c, j, k;
    unsigned bit;
    char *sep;

    fin = fopen("contact.in", "r");
    fout = fopen("contact.out", "w");
    assert(fin != NULL && fout != NULL);

    nbit = 0;
    bit = 0;

    for(i=0; i<=MAXBITS; i++)
	for(j=0; j<(1<<i); j++)
	    seq[(1<<i) | j].bits = (1<<i) | j;

    fscanf(fin, "%d %d %d", &a, &b, &n);

    while((c = getc(fin)) != EOF) {
	if(c != '0' && c != '1')
	    continue;

	bit <<= 1;
	if(c == '1')
	    bit |= 1;

	if(nbit < b)
	    nbit++;

	for(i=a; i<=nbit; i++)
	    addseq(bit, i);
    }

    qsort(seq, MAXSEQ, sizeof(Seq), seqcmp);

    /* print top n frequencies for number of bits between a and b */
    j = 0;
    for(i=0; i<n && j < MAXSEQ; i++) {
	if(seq[j].count == 0)
	    break;

	c = seq[j].count;
	fprintf(fout, "%d\n", c);

	/* print all entries with frequency c */
	sep = "";
	for(k=0; seq[j].count == c; j++, k++) {
	    fprintf(fout, sep);
	    printbits(fout, seq[j].bits);
	    if(k%6 == 5)
		sep = "\n";
	    else
		sep = " ";
	}
	fprintf(fout, "\n");
    }

    exit(0);
}

