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
#define CalLen(l, r) ((r) - (l) + (1))

using namespace std;
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);

class SegT{
    public:
        ll value;
        ll addTag;
        ll mulTag;
        SegT(void):value(0), addTag(0), mulTag(1){}
};
SegT segT[110000 * 4];
int N, M;
ll MOD;
void Build(int, int, int);
void PushDown(int, int, int);
void UpdateAdd(int, int, int, const int, const int, const ll);
void UpdateMul(int, int, int, const int, const int, const ll);
ll Query(int, int, int, const int, const int);
void MakeMod(int n){segT[n].value %= MOD; segT[n].addTag %= MOD; segT[n].mulTag %= MOD;}
void DescSegTree(int);
int main(){
    N = read(), M = read(), MOD = read<ll>();
    Build(1, 1, N);
    // DescSegTree(N);
    for(int i = 1; i <= M; ++i){
        int mode = read();
        switch(mode){
            case 1:{
                int L = read(), R = read(); ll mulV = read<ll>();
                UpdateMul(1, 1, N, L, R, mulV);
                break;
            }
            case 2:{
                int L = read(), R = read(); ll addV = read<ll>();
                UpdateAdd(1, 1, N, L, R, addV);
                break;
            }
            case 3:{
                int L = read(), R = read();
                printf("%lld\n", Query(1, 1, N, L, R));
                break;
            }
        }
        // DescSegTree(N);
    }
    return 0;
}
void Build(int n, int lR, int rR){
    if(lR == rR){segT[n].value = read() % MOD; return;}
    int mid = (lR + rR) >> 1;
    Build(n * 2, lR, mid);
    Build(n * 2 + 1, mid + 1, rR);
    segT[n].value = (segT[n * 2].value + segT[n * 2 + 1].value) % MOD;
} 
void PushDown(int n, int lR, int rR){
    if(lR == rR)return;
    if(!segT[n].addTag && segT[n].mulTag == 1)return;
    int mid = (lR + rR) >> 1;
    segT[n * 2].value = (segT[n * 2].value * segT[n].mulTag + segT[n].addTag * CalLen(lR, mid)) % MOD;
    // printf("@@st[9]=%d\n", segT[9].value);
    // printf("N add tag is %d\n", segT[n].addTag);
    // printf("callen is %d\n", CalLen(mid + 1, rR));
    // printf("mid=%d lr=%d rr=%d\n", mid, lR, rR);

    segT[n * 2 + 1].value = (segT[n * 2 + 1].value * segT[n].mulTag + segT[n].addTag * CalLen(mid + 1, rR)) % MOD;
    // segT[n * 2].addTag += segT[n].addTag;
    // segT[n * 2].mulTag *= segT[n].mulTag;
    // segT[n * 2 + 1].addTag += segT[n].addTag;
    // segT[n * 2 + 1].mulTag *= segT[n].mulTag;
    
    segT[n * 2].mulTag = (segT[n * 2].mulTag * segT[n].mulTag) % MOD;
    segT[n * 2 + 1].mulTag = (segT[n * 2 + 1].mulTag * segT[n].mulTag) % MOD;
    segT[n * 2].addTag = (segT[n * 2].addTag * segT[n].mulTag) % MOD;
    segT[n * 2 + 1].addTag = (segT[n * 2 + 1].addTag * segT[n].mulTag) % MOD;

    segT[n * 2].addTag = (segT[n * 2].addTag + segT[n].addTag) % MOD;
    segT[n * 2 + 1].addTag = (segT[n * 2 + 1].addTag + segT[n].addTag) % MOD;
    
    segT[n].addTag = 0;
    segT[n].mulTag = 1;
    // printf("st[9]=%d\n", segT[9].value);
    // if(n == 4)printf("n is 4 lR=%d rR=%d\n", lR, rR);
}
void UpdateAdd(int n, int lR, int rR, const int L, const int R, const ll addV){
    int mid = (lR + rR) >> 1;
    if(lR > R || rR < L)return;
    if(L <= lR && rR <= R){
        // segT[n].value += addV * CalLen(lR, rR);
        // segT[n].addTag += addV;
        // MakeMod(n);
        segT[n].value = (segT[n].value + addV * CalLen(lR, rR)) % MOD;
        segT[n].addTag = (segT[n].addTag + addV) % MOD;
        return;
    }
    PushDown(n, lR, rR);
    UpdateAdd(n * 2, lR, mid, L, R, addV);
    UpdateAdd(n * 2 + 1, mid + 1, rR, L, R, addV);
    segT[n].value = (segT[n * 2].value + segT[n * 2 + 1].value) % MOD;
}
void UpdateMul(int n, int lR, int rR, const int L, const int R, const ll mulV){
    int mid = (lR + rR) >> 1;
    if(lR > R || rR < L)return;
    if(L <= lR && rR <= R){
        // segT[n].value *= mulV;
        // segT[n].addTag *= mulV;
        // segT[n].mulTag *= mulV;
        // MakeMod(n);
        segT[n].value = (segT[n].value * mulV) % MOD;
        segT[n].addTag = (segT[n].addTag * mulV) % MOD;
        segT[n].mulTag = (segT[n].mulTag * mulV) % MOD;
        return;
    }
    PushDown(n, lR, rR);
    UpdateMul(n * 2, lR, mid, L, R, mulV);
    UpdateMul(n * 2 + 1, mid + 1, rR, L, R, mulV);
    segT[n].value = (segT[n * 2].value + segT[n * 2 + 1].value) % MOD;
}
ll Query(int n, int lR, int rR, const int L, const int R){
    // printf("Query-> n=%d  l=%d  r=%d\n", n, lR, rR);
    int mid = (lR + rR) >> 1;
    if(lR > R || rR < L)return 0;
    if(L <= lR && rR <= R)return segT[n].value;
    PushDown(n, lR, rR);
    // printf("n = %d l = %d r = %d   VAL: %d\n", n, lR, rR, ret);
    return (Query(n * 2, lR, mid, L, R) % MOD + Query(n * 2 + 1, mid + 1, rR, L, R) % MOD) % MOD;
}
void DescSegTree(int N){
    printf("\nPrintSegTree[]: \n");
    int i = 1;
    int base(1), baseN(0);
    while(i <= N * 2){
        printf("[%lld---%lld&%lld]  ", segT[i].value, segT[i].addTag, segT[i].mulTag);
        ++baseN;
        ++i;
        if(baseN == base){
            printf("\n");
            base <<= 1;
            baseN = 0;
        }
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