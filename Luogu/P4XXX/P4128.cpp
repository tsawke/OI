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

int N, M;
ll MOD;
ll fact[110], inv[110], inv_d[110];
int cnt[110];
ll ans(0);
basic_string < int > cur;
unordered_set < int > exist;

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

void Init(void){
    for(int i = 1; i <= N; ++i)inv_d[i] = qpow(i, MOD - 2);
    fact[0] = 1;
    for(int i = 1; i <= N; ++i)fact[i] = fact[i - 1] * i % MOD;
    inv[N] = qpow(fact[N], MOD - 2);
    for(int i = N - 1; i >= 0; --i)inv[i] = inv[i + 1] * (i + 1) % MOD;
}

void dfs(int lft = N){
    if(!lft){
        ll C(0);
        for(auto i : cur)C += i >> 1;
        for(int i = 1; i <= (int)cur.size(); ++i)
            for(int j = 1; j <= i - 1; ++j)
                C += __gcd(cur.at(i - 1), cur.at(j - 1));
        ll ret = qpow(M, C);
        for(auto i : cur)(ret *= inv_d[i]) %= MOD;
        for(auto i : exist)(ret *= inv[cnt[i]]) %= MOD;
        (ans += ret) %= MOD;
        return;
    }
    for(int i = cur.empty() ? 1 : cur.back(); i <= lft; ++i){
        cur += i, ++cnt[i], exist.insert(i);
        dfs(lft - i);
        cur.pop_back();
        if(!--cnt[i])exist.erase(i);
    }
}

int main(){
    N = read(), M = read(), MOD = read();
    Init();
    dfs();
    printf("%lld\n", ans);
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