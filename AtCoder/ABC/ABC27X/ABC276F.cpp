#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define LIM (210000)
#define MOD (998244353ll)

template < typename T = int >
inline T read(void);

class SegTree{
private:
    int cnt[LIM << 2]; ll sum[LIM << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Pushup(int p){
        cnt[p] = cnt[LS] + cnt[RS];
        sum[p] = (sum[LS] + sum[RS]) % MOD;
    }
    void Modify(int val, int p = 1, int gl = 1, int gr = LIM){
        if(gl == gr)return ++cnt[p], (sum[p] += gl) %= MOD, void();
        if(val <= MID)Modify(val, LS, gl, MID);
        else Modify(val, RS, MID + 1, gr);
        Pushup(p);
    }
    ll QueryCnt(int l, int r, int p = 1, int gl = 1, int gr = LIM){
        if(l <= gl && gr <= r)return cnt[p];
        if(l > gr || r < gl)return 0;
        return QueryCnt(l, r, LS, gl, MID) + QueryCnt(l, r, RS, MID + 1, gr);
    }
    ll QuerySum(int l, int r, int p = 1, int gl = 1, int gr = LIM){
        if(l <= gl && gr <= r)return sum[p];
        if(l > gr || r < gl)return 0;
        return (QuerySum(l, r, LS, gl, MID) + QuerySum(l, r, RS, MID + 1, gr)) % MOD;
    }
}st;

int N;
ll cur(0);
ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

int main(){
    N = read();
    for(int K = 1; K <= N; ++K){
        int val = read();
        ll cntMn = st.QueryCnt(1, val);
        ll sumMx = st.QuerySum(val + 1, LIM);
        // printf("Querying %lld %lld\n", cntMn, sumMx);
        (cur += (cntMn * val % MOD * 2 % MOD + (sumMx * 2 % MOD + val) % MOD) % MOD) %= MOD;
        // printf("cur = %lld\n", cur);
        st.Modify(val);
        printf("%lld\n", cur * qpow((ll)K * K % MOD, MOD - 2) % MOD);
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