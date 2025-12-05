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

#define int ll

template<typename T = int>
inline T read(void);

struct Vec{
    ll x, y;
    friend Vec operator +(const Vec a, const Vec b){
        return Vec{a.x + b.x, a.y + b.y};
    }
    friend ll operator -(const Vec a, const Vec b){
        return (a.x * a.x + a.y * a.y) - (b.x * b.x + b.y * b.y);
    }
    friend bool operator <(const Vec a, const Vec b){
        return (a.x * a.x + a.y * a.y) < (b.x * b.x + b.y * b.y);
    }
}v[210000];
int N;


ll ans(0);
void Luangao(void){
    bool vis[210000];
    memset(vis, false, sizeof(vis));
    Vec cur{0, 0};
    double T = 3000000;
    double k = 0.99;
    double cold = 1;
    int cnt(0);
    while(T > cold){
        // printf("T = %.6lf\n", T);
        T *= k;
        int nxt = rndd(1, N);
        if(cnt == N)return;
        while(vis[nxt])nxt = rndd(1, N);
        vis[nxt] = true; ++cnt;
        Vec nxtv = v[nxt] + cur;
        double delta = (double)sqrtl(ld(nxtv - cur));
        if(cur < nxtv)cur = nxtv;
        else if(exp(-(double)delta / T) > ((double)rndd(1, 114514) / 114514))cur = nxtv;
        ans = max(ans, cur.x * cur.x + cur.y * cur.y);
    }
}

signed main(){
    N = read();
    for(int i = 1; i <= N; ++i)v[i].x = read<ll>(), v[i].y = read<ll>();
    while((double)clock() / CLOCKS_PER_SEC < 0.95)Luangao();
    printf("%lld\n", ans);
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