#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

template < typename T = int >
inline T read(void);

int N;
int Pre[210000], In[210000];
int posP[210000], posI[210000];
pair < int, int > son[210000];

int dfs(int lp = 1, int rp = N, int li = 1, int ri = N){
    // printf("In dfs(%d ~ %d, %d ~ %d)\n", lp, rp, li, ri);
    if(lp > rp)return 0;
    int rt = Pre[lp];
    if(posI[rt] < li || posI[rt] > ri)puts("-1"), exit(0);
    if(lp == rp)return rt;
    int lsiz = (posI[rt] - 1) - li + 1;
    son[rt].first = dfs(lp + 1, lp + lsiz, li, posI[rt] - 1);
    son[rt].second = dfs(lp + lsiz + 1, rp, posI[rt] + 1, ri);
    return rt;
}

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)posP[Pre[i] = read()] = i;
    for(int i = 1; i <= N; ++i)posI[In[i] = read()] = i;
    if(Pre[1] != 1)puts("-1"), exit(0);
    dfs();
    for(int i = 1; i <= N; ++i)printf("%d %d\n", son[i].first, son[i].second);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    int flag(1);
    char c = getchar();
    while(c != '-' && !isdigit(c))c = getchar();
    if(c == '-')flag = -1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}