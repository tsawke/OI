#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

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

int N, K;
// int A[4100000];
int lft[4100000];
// ll dp[4100000];
ll dp;

ll tr[4100000];

class SegTree{
private:
    int tr[4100000 << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Pushup(int p){tr[p] = __gcd(tr[LS], tr[RS]);}
    void Build(int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return tr[p] = ::tr[gl = gr], void();
        Build(LS, gl, MID), Build(RS, MID + 1, gr);
        Pushup(p);
    }
    int Query(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return tr[p];
        if(l > MID)return Query(l, r, RS, MID + 1, gr);
        if(r < MID + 1)return Query(l, r, LS, gl, MID);
        return __gcd(Query(l, r, RS, MID + 1, gr), Query(l, r, LS, gl, MID));
    }
}st;

class BIT{
private:
public:
    // BIT(void){memset(tr, 0x3f, sizeof tr);}
    int lowbit(int x){return x & -x;}
    void Modify(int x, ll v){while(x <= N)tr[x] = min(tr[x], v), x += lowbit(x);}
    ll Query(int x){ll ret(LONG_LONG_MAX); while(x)ret = min(ret, tr[x]), x -= lowbit(x); return ret;}
}bit;

int main(){
    // freopen("D.in", "r", stdin);
    // freopen("out.txt", "w", stdout);
    N = read(), K = read();
    for(int i = 1; i <= N; ++i)tr[i] = read();
    int cur = tr[1];
    for(int i = 2; i <= N; ++i)cur = __gcd(cur, (int)tr[i]);
    for(int i = 1; i <= N; ++i)tr[i] /= cur;
    st.Build();
    for(int l = 0, r = 1; r <= N; ++r){
        while(l + 1 <= r && st.Query(l + 1, r) == 1)++l;
        lft[r] = l;
    }
    memset(tr, 0x3f, sizeof tr);
    bit.Modify(1, 0);
    for(int i = 1; i <= N; ++i){
        if(lft[i] == i)dp = dp;
        else if(lft[i] == 0)dp = LONG_LONG_MAX >> 1;
        else dp = bit.Query(lft[i]) + i + K;
        bit.Modify(i + 1, dp - i);
    }printf("%lld\n", dp);
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