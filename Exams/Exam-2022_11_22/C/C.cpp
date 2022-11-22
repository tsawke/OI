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

ll N, M, K, MOD;
bool blk[1100][1100];
bool inq[1100][1100];
int cnt[1100][1100];

ll ans(0);

void bfs(void){
    cnt[0][0] = 1;
    queue < pair < int, int > > unex;
    unex.push({0, 0});
    inq[0][0] = true;
    for(int i = 1; i <= N + M; ++i){
        queue < pair < int, int > > tmp;
        while(!unex.empty()){
            auto tp = unex.front(); inq[tp.first][tp.second] = false; unex.pop();
            int tx = tp.first + 0, ty = tp.second + 1;
            if(tx <= N && ty <= M && !blk[tx][ty]){
                (cnt[tx][ty] += cnt[tp.first][tp.second]) %= MOD;
                if(!inq[tx][ty])inq[tx][ty] = true, tmp.push({tx, ty});
            }
            tx = tp.first + 1, ty = tp.second + 0;
            if(tx <= N && ty <= M && !blk[tx][ty]){
                (cnt[tx][ty] += cnt[tp.first][tp.second]) %= MOD;
                if(!inq[tx][ty])inq[tx][ty] = true, tmp.push({tx, ty});
            }
        }while(!tmp.empty())unex.push(tmp.front()), tmp.pop();
    }printf("%lld\n", cnt[N][M] % MOD);
}

ll fact[1100000], inv[1100000];
ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}
void Init(void){
    fact[0] = 1;
    for(int i = 1; i < MOD; ++i)fact[i] = (fact[i - 1] * i) % MOD;
    inv[MOD - 1] = qpow(fact[MOD - 1], MOD - 2);
    for(int i = MOD - 2; i >= 0; --i)inv[i] = inv[i + 1] * (i + 1) % MOD;
}

ll GetMinC(int n, int m){
    if(n < m)return 0;
    return fact[n] * inv[m] % MOD * inv[n - m] % MOD;
}

ll Lucas(__int128_t n, __int128_t m){
    if(n < m)return 0;
    if(n <= MOD && m <= MOD)return GetMinC(n, m);
    return Lucas(n / MOD, m / MOD) * Lucas(n % MOD, m % MOD) % MOD;
}

int main(){
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    N = read < ll >(), M = read < ll >(), K = read(), MOD = read();
    Init();
    if(!K){
        printf("%lld\n", Lucas((__int128_t)N + M, (__int128_t)N));
        // bfs();
    }else{
        // if(N <= 1000 && M <= 1000){
            for(int i = 1; i <= K; ++i){int x = read(), y = read(); blk[x][y] = true;}
            bfs();
        // }else{
            // (ans += Lucas((__int128_t)N + M, (__int128_t)N)) %= MOD;
            // for(int len = 1; len <= K; ++len){
            //     ans += Lucas((__int128_t))
            // }
        // }
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