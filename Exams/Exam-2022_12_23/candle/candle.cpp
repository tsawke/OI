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

#define MOD P

template < typename T = int >
inline T read(void);

int N, M, P, C;
int a[51000];

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

class SegTree{
private:
    ll tr[210000 << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Pushup(int p){
        tr[p] = (tr[LS] + tr[RS]) % MOD;
    }
    void Build(int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return tr[p] = a[gl] % MOD, void();
        Build(LS, gl, MID), Build(RS, MID + 1, gr);
        Pushup(p);
    }
    void Modify(int pos, int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return tr[p] = qpow(C, tr[p]), void();
        if(pos <= MID)Modify(pos, LS, gl, MID);
        else Modify(pos, RS, MID + 1, gr);
        Pushup(p);
    }
    ll Query(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return tr[p];
        if(l > gr || r < gl)return 0;
        return (Query(l, r, LS, gl, MID) + Query(l, r, RS, MID + 1, gr)) % MOD;
    }
}st;

int main(){
    freopen("candle.in", "r", stdin);
    freopen("candle.out", "w", stdout);
    N = read(), M = read(), P = read(), C = read();
    for(int i = 1; i <= N; ++i)a[i] = read();
    st.Build();
    while(M--){
        int opt = read();
        if(opt == 0){
            int l = read(), r = read();
            for(int i = l; i <= r; ++i)st.Modify(i);
        }else{
            int l = read(), r = read();
            printf("%lld\n", st.Query(l, r));
        }
    }
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