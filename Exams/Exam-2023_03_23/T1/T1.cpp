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

#define MOD (998244353ll)

template < typename T = int >
inline T read(void);

int N, K;
struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[2100];
ROPNEW;
Edge* head[1100];

namespace Sub1{
    int mx(0);
    bitset < 10 > G[10];
    int tot(0);
    int val[300];
    int ans[300];
    basic_string < int > belong[10];
    void Make(void){
        for(int p = 1; p <= N; ++p)for(auto i = head[p]; i; i = i->nxt)G[p][SON] = true;
        const int Smx = (1 << N) - 1;
        for(auto S = Smx; S; S = (S - 1) & Smx){
            basic_string < int > nods;
            for(int i = 1; i <= N; ++i)if(S & (1 << (i - 1)))nods += i;
            bool flag(true);
            for(int i = 1; i <= (int)nods.size(); ++i)for(int j = i + 1; j <= (int)nods.size(); ++j)
                if(G[nods.at(i - 1)][nods.at(j - 1)]){flag = false; break;}
            if(!flag)continue;
            ++tot;
            for(auto p : nods)belong[p] += tot;
        }
        auto dfs_val = [](auto&& self, int dep = 1)->void{
            if(dep > N)return ++ans[mx], void();
            for(int i = 1; i <= K; ++i){
                int lstMx = mx;
                for(auto idx : belong[dep])val[idx] += i, mx = max(mx, val[idx]);
                self(self, dep + 1);
                for(auto idx : belong[dep])val[idx] -= i;
                mx = lstMx;
            }
        }; dfs_val(dfs_val);
        for(int i = 1; i <= N * K; ++i)printf("%d\n", ans[i]);
    }
}
namespace Sub2{
    int ans[1100];
    int dp[1100][2]; //Subtree of i, i is chosen or not, max ans
    void Make(void){
        auto dfs_dp = [](auto&& self, int p = 1, int fa = 0)->void{
            dp[p][1] = 1;
            for(auto i = head[p]; i; i = i->nxt){
                if(SON == fa)continue;
                self(self, SON, p);
                dp[p][0] += max(dp[SON][0], dp[SON][1]);
                dp[p][1] += dp[SON][0];
            }
        }; dfs_dp(dfs_dp);
        ans[max(dp[1][0], dp[1][1])]++;
        for(int i = 1; i <= N * K; ++i)printf("%d\n", ans[i]);
    }
}
namespace Sub3{
    ll ans[1100];
    ll dp[110][160][160];
    ll tmp[160][160];
    int siz[110];
    void Make(void){
        auto dfs_siz = [](auto&& self, int p = 1, int fa = 0)->void{
            siz[p] = 1;
            for(auto i = head[p]; i; i = i->nxt)
                if(SON != fa)self(self, SON, p), siz[p] += siz[SON];
        }; dfs_siz(dfs_siz);
        auto dfs_dp = [](auto&& self, int p = 1, int fa = 0)->void{
            // if(!head[p]->nxt){for(int i = 1; i <= K; ++i)dp[p][0][i]++; return;}
            for(int i = 1; i <= K; ++i)dp[p][0][i]++;
            // auto fst = head[p]; if(fst->to == fa)fst = head[p]->nxt;
            // for(int a = 0; a <= siz[p] * K; ++a){
            //     for(int b = 0; b <= siz[p] * K; ++b){
            //         dp[p][a][b] = dp[fst->to][a][b];
            //     }
            // }
            // for(auto i = fst->nxt; i; i = i->nxt){
            for(auto i = head[p]; i; i = i->nxt){
                if(SON == fa)continue;
                self(self, SON, p);
                // for(int i = 0; i <= siz[p] * K; ++i)for(int j = 0; j <= siz[p] * K; ++j)tmp[i][j] = 0;
                for(int a = 0; a <= siz[p] * K; ++a){
                    for(int b = 0; b <= siz[p] * K; ++b){
                        for(int x = 0; x <= siz[SON] * K && x + b <= siz[p] * K; ++x){
                            for(int y = 0; y <= siz[SON] * K && y + b <= siz[p] * K && y + a <= siz[p] * K; ++y){
                                (tmp[a + max(x, y)][b + x] += dp[p][a][b] * dp[SON][x][y] % MOD) %= MOD;
                            }
                        }
                    }
                }
                for(int a = 0; a <= siz[p] * K; ++a)for(int b = 0; b <= siz[p] * K; ++b){
                    // if(i->nxt)(dp[p][a][b] += tmp[a][b]) %= MOD, tmp[a][b] = 0;
                    // else dp[p][a][b] = tmp[a][b], tmp[a][b] = 0;
dp[p][a][b] = tmp[a][b], tmp[a][b] = 0;
                    // (dp[p][a][b] += tmp[a][b]) %= MOD, tmp[a][b] = 0;
                }
                    
            }

        }; dfs_dp(dfs_dp);
        for(int i = 0; i <= N * K; ++i)for(int j = 0; j <= N * K; ++j)//printf("dp[%d][%d] = %lld\n", i, j, dp[1][i][j]);
            // (ans[i] += dp[1][i][j]) %= MOD, (ans[j] += dp[1][i][j]) %= MOD;
            ans[max(i, j)] += dp[1][i][j];
        // for(int i = 0; i <= N * K; ++i)for(int j = N * K; j > i; --j)ans[max(i, j)] += dp[1][i][j];
        for(int i = 1; i <= N * K; ++i)printf("%lld\n", ans[i]);
    }
}

int main(){
    freopen("T1.in", "r", stdin);
    freopen("T1.out", "w", stdout);
    N = read(), K = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }
    if(N <= 8)Sub1::Make();
    else if(K == 1)Sub2::Make();
    else Sub3::Make();
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