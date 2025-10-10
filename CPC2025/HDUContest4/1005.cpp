#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define MOD (998244353ll)

template<typename T = int>
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    void* operator new(size_t);
}ed[61000];
void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
Edge* head[310];

int N; string S;
int root;
int deg_son[310];
int fa[310];
ll inv[310];

bitset < 310 > isRoot, isLeaf;

ll dp[310][310];

int main(){
    auto qpow = [](ll a, ll b)->ll{
        ll ret(1), mul(a);
        while(b){
            if(b & 1)ret = (ret * mul) % MOD;
            b >>= 1, mul = (mul * mul) % MOD;
        }return ret;
    };
    inv[0] = 1;
    for(int i = 1; i <= 305; ++i)inv[i] = qpow(i, MOD - 2);

    // for(int i = 1; i <= 10; ++i)printf("inv of %d is %lld\n", i, inv[i]);

    int T = read();
    while(T--){
        N = read();

        isRoot.set();
        isRoot[0] = false;
        isLeaf.reset();
        for(int i = 0; i <= N; ++i)head[i] = nullptr;
        memset(deg_son, 0, sizeof deg_son);
        memset(dp, 0, sizeof dp);
        memset(fa, 0, sizeof fa);

        cin >> S;
        for(int s = 1; s <= N; ++s){
            int k = read();
            deg_son[s] += k;
            if(!k)isLeaf[s] = true;
            for(int i = 1; i <= k; ++i){
                int t = read();
                // ++deg_son[t];
                isRoot[t] = false;
                head[s] = new Edge{head[s], t};
                fa[t] = s;
            }
        }
        root = isRoot._Find_first();

        int M = S.length();

        for(int i = 1; i <= N; ++i)dp[M][i] = i;

        for(int m = M - 1; m >= 0; --m){
            for(int p = 1; p <= N; ++p){
                char opt = S.at(m);
                if(opt == 'L' || opt == 'R'){
                    if(isRoot[p])dp[m][p] = dp[m + 1][p];
                    else{
                        ll sum(0);
                        for(auto i = head[fa[p]]; i; i = i->nxt)
                            sum += dp[m + 1][i->to], sum %= MOD;
                        dp[m][p] = sum * inv[deg_son[fa[p]]] % MOD;
                    }
                }else{ // opt == 'D'
                    if(isLeaf[p])dp[m][p] = dp[m + 1][p];
                    else{
                        ll sum(0);
                        for(auto i = head[p]; i; i = i->nxt)
                            sum += dp[m + 1][i->to], sum %= MOD;
                        dp[m][p] = sum * inv[deg_son[p]] % MOD;
                    }
                }
            }
        }
        // for(int i = 0; i <= M; ++i)for(int j = 1; j <= N; ++j)printf("dp[%d][%d] = %lld\n", i, j, dp[i][j]);
        printf("%lld\n", dp[0][root]);
    }

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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