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

#define MOD (998244353ll)

template < typename T = int >
inline T read(void);

int N, Q;
ll A[210000];

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

class BIT{
private:
    ll tr[210000];
public:
    int lowbit(int x){return x & -x;}
    void Modify(int x, ll v){while(x <= N)(tr[x] += v + MOD) %= MOD, x += lowbit(x);}
    ll Query(int x){ll ret(0); while(x)(ret += tr[x]) %= MOD, x -= lowbit(x); return ret;}
}bit1, bit2, bit3;

int main(){
    const ll inv2 = qpow(2, MOD - 2);
    N = read(), Q = read();
    for(int i = 1; i <= N; ++i)
        A[i] = read(),
        bit1.Modify(i, A[i]),
        bit2.Modify(i, i * A[i] % MOD),
        bit3.Modify(i, ((ll)i * i % MOD - 3ll * i % MOD + MOD) % MOD * A[i] % MOD);
    while(Q--){
        int opt = read();
        if(opt == 1){
            int x = read(); ll v = read();
            bit1.Modify(x, (v - A[x] + MOD) % MOD),
            bit2.Modify(x, x * ((v - A[x] + MOD) % MOD) % MOD),
            bit3.Modify(x, ((ll)x * x % MOD - 3ll * x % MOD + MOD) % MOD * ((v - A[x] + MOD) % MOD) % MOD);
            A[x] = v;
        }else{
            ll x = read();
            ll ret = (x * x % MOD + 3ll * x % MOD + 2) % MOD * bit1.Query(x) % MOD;
            (ret += (-2ll * x + MOD) % MOD * bit2.Query(x) % MOD) %= MOD;
            (ret += bit3.Query(x)) %= MOD;
            printf("%lld\n", ret * inv2 % MOD);
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