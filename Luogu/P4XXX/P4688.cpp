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

#define BLOCK(x) (x / blockLen + 1)
#define MAXN 110000

template<typename T = int>
inline T read(void);

int N, M;
int blockLen;
int splitM;
int a[MAXN];
int cnt[MAXN], ans{MAXN};
bitset < MAXN > cur;

struct Block{
    int l, r;
    int idx;
    friend const bool operator < (const Block &x, const Block &y){
        int xb = BLOCK(x.l), yb = BLOCK(y.l);
        if(xb != yb)return xb < yb;
        return xb & 1 ? x.r < y.r : x.r > y.r;
    }
};
void add(int v){cur.set(v + cnt[v]); ++cnt[v];}
void del(int v){--cnt[v]; cur.reset(v + cnt[v]);}
void Solve(void){
    memset(cnt, 0, sizeof(cnt));
    cur.reset();
    int ccnt(0);
    for(int t = 1; t <= splitM && M--; ++t){
        
    }
}

int main(){
    N = read(), M = read();
    vector < int > arr;
    for(int i = 1; i <= N; ++i)a[i] = read(), arr.push_back(a[i]);
    blockLen = sqrt(N), splitM = M / 3 + 1;
    sort(arr.begin(), arr.end());
    for(int i = 1; i <= N; ++i)a[i] = distance(arr.begin(), lower_bound(arr.begin(), arr.end(), a[i])) + 1;


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