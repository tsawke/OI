#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr

******************************/

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define BLOCK(x) (x / B + 1)
#define MAXN 110000

template<typename T = int>
inline T read(void);

int N, M;
int B;
int maxV(-1);
int blk[MAXN], blkv[MAXN];
int a[MAXN];
int sum_pos[MAXN];
int sum_blk[MAXN], sum_blk_exist[MAXN];
pair < int, int > ans[MAXN];

struct Query{
    int l, r;
    int a, b;
    int idx;
    friend const bool operator < (const Query x, const Query y){
        if(blk[x.l] != blk[y.l])return x.l < y.l;
        return blk[x.l] & 1 ? x.r < y.r : x.r > y.r;
    }
};
vector < Query > Q;
pair < int, int > QueryBlk(int l, int r){
    if(l > maxV)return {0, 0};
    r = min(r, maxV);
    int bl = blkv[l], br = blkv[r];
    int ret1(0), ret2(0);
    if(bl == br){
        for(int i = l; i <= r; ++i)ret1 += sum_pos[i], ret2 += (bool)sum_pos[i];
        return {ret1, ret2};
    }
    if(blkv[l - 1] == bl){
        for(int i = l; blkv[i] == bl && i <= maxV; ++i)
            ret1 += sum_pos[i], ret2 += (bool)sum_pos[i];
        ++bl;
    }
    if(blkv[r + 1] == br){
        for(int i = r; blkv[i] == br && i >= 1; --i)
            ret1 += sum_pos[i], ret2 += (bool)sum_pos[i];
        --br;
    }
    for(int i = bl; i <= br; ++i)
        ret1 += sum_blk[i], ret2 += sum_blk_exist[i];
    return {ret1, ret2};
}
void add(int x){
    ++sum_blk[blkv[x]];
    if(++sum_pos[x] == 1)++sum_blk_exist[blkv[x]];
}
void del(int x){
    --sum_blk[blkv[x]];
    if(--sum_pos[x] == 0)--sum_blk_exist[blkv[x]];
}
int main(){
    N = read(), M = read();
    B = (double)N / sqrt(M) + 1;
    for(int i = 1; i <= N; ++i)
        a[i] = read(), blk[i] = i / B + 1, maxV = max(maxV, a[i]);
    B = sqrt(maxV) + 1;
    for(int i = 1; i <= maxV; ++i)
        blkv[i] = i / B + 1;
    for(int i = 1; i <= M; ++i){
        int l = read(), r = read(), a = read(), b = read();
        Q.emplace_back(Query{l, r, a, b, i});
    }sort(Q.begin(), Q.end());
    int gl(0), gr(0);
    for(auto ask : Q){
        while(gl > ask.l)add(a[--gl]);
        while(gr < ask.r)add(a[++gr]);
        while(gl < ask.l)del(a[gl++]);
        while(gr > ask.r)del(a[gr--]);
        ans[ask.idx] = QueryBlk(ask.a, ask.b);
    }
    for(int i = 1; i <= M; ++i)printf("%d %d\n", ans[i].first, ans[i].second);

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template<typename T>
inline T read(void){
    T ret(0);
    short flag(1);
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