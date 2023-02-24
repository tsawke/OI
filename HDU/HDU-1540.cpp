//C++11 - Template
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <climits>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <unistd.h>
#define LS (vert * 2)
#define RS (vert * 2 + 1)

using namespace std;
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
int N, M;
struct Vertex{
    ll maxlen;
    ll lazytag;
    ll lmaxlen;
    ll rmaxlen;
    int lRange, rRange;
    int GetVertexN(void){return this->rRange - this->lRange + 1;}
};
Vertex segTree[110000 * 4];
void upd(int, int, int = 1);
void upd_rec(int);
ll query(int);
void build(int, int, int);
void pushup(int, int, int);
int lastD = 0;
int main(){
	N = read(), M = read();
    char c;
    for(int m = 1; m <= M; ++m){
        while((c = getchar()) < 'A' || c > 'Z');
        switch(c){
            case 'D':{
                int v = read();
                upd(v, 0);
                lastD = v;
                break;
            }
            case 'Q':{
                int v = read();
                printf("%lld\n", query(v));
                break;
            }
            case 'R':{
                upd_rec(lastD);
                break;
            }
        }
    }
    return 0;
}
void pushup(int lR, int rR, int vert){
    int mid = (rR + lR) >> 1;
    if(segTree[LS].maxlen == mid - lR + 1)segTree[vert].lmaxlen = segTree[LS].maxlen + segTree[RS].lmaxlen;
    else segTree[vert].lmaxlen = segTree[LS].lmaxlen;
    if(segTree[RS].maxlen == rR - mid + 1)segTree[vert].rmaxlen = segTree[RS].maxlen + segTree[LS].rmaxlen;
    else segTree[vert].rmaxlen = segTree[RS].rmaxlen;
    segTree[vert].maxlen = max(segTree[LS].rmaxlen + segTree[LS + 1].lmaxlen, max(segTree[LS].maxlen, segTree[LS + 1].maxlen));
}
void build(int lR, int rR, int vert){
    if(lR == rR){
        segTree[vert].lmaxlen = segTree[vert].rmaxlen = segTree[vert].maxlen = 1;
        segTree[vert].lRange = segTree[vert].rRange = lR;
        return;
    }
    int mid = (lR + rR) / 2;
    build(lR, mid, LS);
    build(mid + 1, rR, LS + 1);
    pushup(lR, rR, vert);
    segTree[vert].lRange = lR;
    segTree[vert].rRange = rR;
}
void upd(int updV, int mode, int vert){
    if(segTree[vert].lRange == segTree[vert].rRange){
        segTree[vert].maxlen = segTree[vert].lmaxlen = segTree[vert].rmaxlen = mode;
        return;
    }
    int mid = (segTree[vert].lRange + segTree[vert].rRange) >> 1;
    if(updV <= mid)upd(updV, mode, LS);
    else upd(updV, mode, RS);
}
void upd_rec(int updV){
    upd(updV, 1);
}
ll query(int qV, int vert){
    if(segTree[vert].lRange == segTree[vert].rRange)return segTree[vert].maxlen;
    int mid = (segTree[vert].lRange + segTree[vert].rRange) >> 1;
    if(qV <= mid){
        if(segTree[LS].rmaxlen + qV - 1 >= mid)return segTree[LS].rmaxlen + segTree[RS].lmaxlen;
        else return query(qV, LS);
    }
    else{
        if(-segTree[RS].lmaxlen + qV <= mid)return segTree[RS].lmaxlen + segTree[LS].rmaxlen;
        else return query(qV, RS);
    }
}

template <typename T = int>
inline T read(void)
{
	T ret(0);
	short flag(1);
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')flag = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10, ret += (c - '0');
		c = getchar();
    }
    ret *= flag;
	return ret;
}