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

#define MOD (ll)(1e9 + 7)
#define S(name, idx) ((name) & (1 << ((idx) - 1)))

template < typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[210000];
ROPNEW;
Edge* head[210000];

int N, K;
int Smx;
int opt[10][10];
struct Node{int S; int col;};
basic_string < Node > legal[40];
ll dp[110000][40][6];
ll merg[40][6];

void Clear(void){
    for(int i = 0; i <= Smx; ++i)legal[i].clear();
    for(int i = 0; i <= N; ++i)head[i] = npt;
    for(int i = 0; i <= N; ++i)for(int S = 0; S <= Smx; ++S)for(int k = 1; k <= K; ++k)dp[i][S][k] = 0;
}
void TreeDP(int p = 1, int fa = 0){
    for(auto i = head[p]; i; i = i->nxt)if(SON != fa)TreeDP(SON, p);
    if(!head[p]->nxt){for(int i = 0; i < K; ++i)dp[p][1 << i][i + 1] = 1; return;}
    memset(merg, 0, sizeof merg);
    bool isbeg(true);
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
        if(isbeg){
            isbeg = false;
            for(int S = 1; S <= Smx; ++S)for(int j = 1; j <= K; ++j)for(int k = 1; k <= K; ++k)(merg[S][j] += dp[SON][S][k]) %= MOD;
            // printf("p is %d, after merge, merge is : \n", p);
            // for(int S = 1; S <= Smx; ++S)for(int i = 1; i <= K; ++i)
            //     cout << "merg[" << i << "][" << bitset < 5 >(S) << "] = " << merg[S][i] << endl;
            continue;
        }
        ll lst[40][6];
        for(int S = 0; S <= Smx; ++S)for(int j = 1; j <= K; ++j)lst[S][j] = merg[S][j], merg[S][j] = 0;
        ll sum[40]; memset(sum, 0, sizeof sum);
        for(int S = 1; S <= Smx; ++S)for(int j = 1; j <= K; ++j)(sum[S] += dp[SON][S][j]) %= MOD;
        for(int S1 = 1; S1 <= Smx; ++S1)
            for(auto S2 : legal[S1])
                (merg[S1 | S2.S][S2.col] += lst[S1][S2.col] * sum[S2.S] % MOD) %= MOD;
        // printf("p is %d, after merge, merge is : \n", p);
        // for(int S = 1; S <= Smx; ++S)for(int i = 1; i <= K; ++i)
        //     cout << "merg[" << i << "][" << bitset < 5 >(S) << "] = " << merg[S][i] << endl;
    }
    for(int S = 1; S <= Smx; ++S)
        for(int i = 1; i <= K; ++i)
            (dp[p][S | (1 << (i - 1))][i] += merg[S][i]) %= MOD;
}

int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T = read();
    while(T--){
        Clear();
        N = read(), K = read();
        Smx = (1 << K) - 1;
        for(int i = 1; i <= K; ++i)for(int j = 1; j <= K; ++j)opt[i][j] = read();
        for(int i = 2; i <= N; ++i){
            int s = i, t = read();
            head[s] = new Edge{head[s], t};
            head[t] = new Edge{head[t], s};
        }
        for(int S1 = Smx; S1; S1 = (S1 - 1) & Smx)
            for(int S2 = Smx; S2; S2 = (S2 - 1) & Smx){
                int cur(-1);
                bool flag(true);
                for(int i = 1; i <= K; ++i){
                    if(!flag)break;
                    for(int j = 1; j <= K; ++j){
                        if(!flag)break;
                        if(S(S1, i) && S(S2, j)){
                            if(opt[i][j] != opt[j][i]){flag = false; break;}
                            if(!~cur)cur = opt[i][j];
                            else if(opt[i][j] != cur)flag = false;
                        }
                    }
                }if(flag)legal[S1] += Node{S2, cur};
            }
        // for(int S = 1; S <= Smx; ++S)for(auto S2 : legal[S]){
        //     cout << bitset < 5 >(S) << "with" << bitset < 5 >(S2.S) << "  col is" << S2.col << endl;
        // }
        TreeDP();
        // for(int i = 1; i <= N; ++i)for(int S = 1; S <= Smx; ++S)for(int j = 1; j <= K; ++j)
        //     cout << "dp[" << i << "][" << j << "][" << bitset < 5 >(S) << "] = " << dp[i][S][j] << endl;
        ll ans(0);
        for(int S = 1; S <= Smx; ++S)for(int i = 1; i <= K; ++i)(ans += dp[1][S][i]) %= MOD;
        printf("%lld\n", ans);
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

/*

2
5 2
1 2
2 1
1 2 1 4
5 2
1 2
1 1
1 2 1 4

*/