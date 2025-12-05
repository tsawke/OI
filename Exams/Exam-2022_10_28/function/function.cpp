#define USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long unll;
typedef unsigned int uint;
typedef long double ld;

#define MAXN (1100000)
#define MOD (998244353)

template < typename T = int >
inline T read(void){
    T ret(0);
    short flag(1);
    char c = getchar();
    while(!isdigit(c) && c != '-')c = getchar();
    if(c == '-')flag = -1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }return ret * flag;
}

int N, K;
int a[MAXN];

class SegTree{
private:
    ll tr[MAXN << 2];
    ll trsq[MAXN << 2];
    ll lz[MAXN << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
    #define SIZ (gr - gl + 1)
public:
    void Pushup(int p){
        tr[p] = (tr[LS] + tr[RS]) % MOD;
        trsq[p] = (trsq[LS] + trsq[RS]) % MOD;
    }
    void Pushdown(int p, int gl, int gr){
        lz[LS] = (lz[LS] + lz[p]) % MOD, lz[RS] = (lz[RS] + lz[p]) % MOD;
        trsq[LS] = (trsq[LS] + 2ll * lz[p] % MOD * tr[LS] % MOD + lz[p] * lz[p] % MOD * (MID - gl + 1) % MOD) % MOD;
        trsq[RS] = (trsq[RS] + 2ll * lz[p] % MOD * tr[RS] % MOD + lz[p] * lz[p] % MOD * (gr - MID - 1 + 1) % MOD) % MOD;
        tr[LS] = (tr[LS] + lz[p] * (MID - gl + 1) % MOD) % MOD;
        tr[RS] = (tr[RS] + lz[p]* (gr - MID - 1 + 1) % MOD) % MOD;
        lz[p] = 0;
    }
    void Build(int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return tr[p] = a[gl], trsq[p] = tr[p] * tr[p] % MOD, void();
        Build(LS, gl, MID);
        Build(RS, MID + 1, gr);
        Pushup(p);
    }
    void Modify(int l, int r, ll val, int p = 1, int gl = 1, int gr = N){
        // printf("l = %d, r = %d,  val = %lld, p = %d, gl = %d, gr = %d\n", l, r, val, p, gl, gr);
        if(l <= gl && gr <= r)
            return trsq[p] = (trsq[p] + 2ll * val % MOD * tr[p] % MOD + val * val % MOD * SIZ % MOD) % MOD,
            tr[p] = (tr[p] + val * SIZ % MOD) % MOD,
            lz[p] = (lz[p] + val) % MOD,
            void();
        Pushdown(p, gl, gr);
        if(l <= MID)Modify(l, r, val, LS, gl, MID);
        if(MID + 1 <= r)Modify(l, r, val, RS, MID + 1, gr);
        Pushup(p);
    }
    ll Query(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return trsq[p];
        Pushdown(p, gl, gr);
        return
            ((l <= MID ? Query(l, r, LS, gl, MID) : 0) +
            (MID + 1 <= r ? Query(l, r, RS, MID + 1, gr) : 0)) % MOD;
    }
}st;

int main(){
    freopen("function.in", "r", stdin);
    freopen("function.out", "w", stdout);

    N = read(), K = read();
    for(int i = 1; i <= N; ++i)a[i] = read();
    st.Build();
    ll ans(0);
    for(int i = 1; i <= K; ++i){
        int sp = -(int)ceil((double)(K + 1) / 2.0);
        auto ptr = lower_bound(a + 1, a + N + 1, sp);
        int idx = distance(a + 1, ptr + 1);
        st.Modify(1, idx - 1, 1);
        st.Modify(idx, N, i);
        ans = (ans + st.Query(1, N));
        st.Modify(1, idx - 1, -1);
        st.Modify(idx, N, -i);
        // int mn(1), mx(i);
        // for(int j = 1; j <= N; ++j){
        //     ll val = max(abs(a[j] + mn), abs(a[j] + mx));
        //     // printf("val: %lld\n", val);
        //     ans = (ans + val * val % MOD) % MOD;
        // }
        // // printf("Cur ans : %lld\n", ans);
        // printf("Curans : %d = %lld\n", i, ans);
    }printf("%lld\n", ans);

    return 0;
}