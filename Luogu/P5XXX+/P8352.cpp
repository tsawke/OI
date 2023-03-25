#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MOD (ll)(1e9 + 7)

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
    ll ans[5100];
    // ll dp[110][160][160];
    // ll tmp[160][160];
    int siz[1100];
    struct HashPair{
        ll operator ()(const pair < int, int > &P)const{
            // return hash < int >{}(P.first) ^ hash < int >{}(P.second);
            return P.first * (ll)(1e9) + P.second;
        }
    };
    cc_hash_table < pair < int, int >, ll, HashPair > dp[1100], tmp;
    void Make(void){
        auto dfs_siz = [](auto&& self, int p = 1, int fa = 0)->void{
            siz[p] = 1;
            for(auto i = head[p]; i; i = i->nxt)
                if(SON != fa)self(self, SON, p), siz[p] += siz[SON];
        }; dfs_siz(dfs_siz);
        auto dfs_dp = [](auto&& self, int p = 1, int fa = 0)->void{
            for(int i = 1; i <= K; ++i)dp[p][{0, i}]++;
            for(auto i = head[p]; i; i = i->nxt){
                if(SON == fa)continue;
                self(self, SON, p);
                for(auto A : dp[p])
                    for(auto B : dp[SON])
                        (tmp[{A.first.first + max(B.first.first, B.first.second), A.first.second + B.first.first}] += A.second * B.second % MOD) %= MOD;
                // for(int a = 0; a <= siz[p] * K; ++a){
                //     for(int b = 0; b <= siz[p] * K; ++b){
                //         for(int x = 0; x <= siz[SON] * K && x + b <= siz[p] * K; ++x){
                //             for(int y = 0; y <= siz[SON] * K && y + b <= siz[p] * K && y + a <= siz[p] * K; ++y){
                //                 (tmp[a + max(x, y)][b + x] += dp[p][a][b] * dp[SON][x][y] % MOD) %= MOD;
                //             }
                //         }
                //     }
                // }
                dp[p].clear();
                for(auto it = tmp.begin(); it != tmp.end(); advance(it, 1))
                    dp[p][{it->first.first, it->first.second}] = it->second;
                tmp.clear();
                // for(int a = 0; a <= siz[p] * K; ++a)for(int b = 0; b <= siz[p] * K; ++b)
                //     dp[p][a][b] = tmp[a][b], tmp[a][b] = 0;
            }
        }; dfs_dp(dfs_dp);
        for(int i = 0; i <= N * K; ++i)for(int j = 0; j <= N * K; ++j)(ans[max(i, j)] += dp[1][{i, j}]) %= MOD;
        for(int i = 1; i <= N * K; ++i)printf("%lld\n", ans[i]);
    }
}
namespace Sub4{
    ll ans[5100];
    // ll dp[110][160][160];
    // ll tmp[160][160];
    int siz[1100];
    // struct HashPair{
    //     auto operator ()(const pair < int, int > &P)const{
    //         // return hash < int >{}(P.first) ^ hash < int >{}(P.second);
    //         return P.first * (ll)(1e9) + P.second;
    //         // return P.first ^ P.second ^ 114514123;
    //     }
    // };
    ll dp[1100][5100][7];
    ll tmp[5100][7];
    // unordered_map < pair < int, int >, ll, HashPair > dp[1100][1100], tmp[1100000];
    // int cnt_tmp;
    // int cidx[1100];
    void Make(void){
        auto dfs_siz = [](auto&& self, int p = 1, int fa = 0)->void{
            siz[p] = 1;
            for(auto i = head[p]; i; i = i->nxt)
                if(SON != fa)self(self, SON, p), siz[p] += siz[SON];
        }; dfs_siz(dfs_siz);
        auto dfs_dp = [](auto&& self, int p = 1, int fa = 0)->void{
            // for(int i = 1; i <= K; ++i)dp[p][cidx[p]][{0, i}]++;
            for(int i = 1; i <= K; ++i)dp[p][0][i]++;
            for(auto i = head[p]; i; i = i->nxt){
                if(SON == fa)continue;
                self(self, SON, p);
                // for(auto A : dp[p][cidx[p]])
                //     for(auto B : dp[SON][cidx[SON]])
                
                //         (tmp[])
                //         (tmp[cnt_tmp][{A.first.first + B.first.first + B.first.second, max(A.first.first + B.first.first + B.first.second, A.first.first + A.first.second + B.first.first) - (A.first.first + B.first.first + B.first.second)}] += A.second * B.second % MOD) %= MOD;
                //         // (tmp[{A.first.first + max(B.first.first, B.first.second), A.first.second + B.first.first}] += A.second * B.second % MOD) %= MOD;
                for(int a = 0; a <= siz[p] * K; ++a){
                    for(int b = 0; b <= K; ++b){
                        if(!dp[p][a][b])continue;
                        for(int x = 0; x <= siz[SON] * K; ++x){
                            for(int y = 0; y <= K; ++y){
                                if(!dp[SON][x][y])continue;
                                if(a + x + y <= siz[p] * K && max(a + x + y, a + b + x) - (a + x + y) <= 5)
                                (tmp[a + x + y][max(a + x + y, a + b + x) - (a + x + y)] += dp[p][a][b] * dp[SON][x][y] % MOD) %= MOD;

                            }
                        }
                    }
                }
                for(int a = 0; a <= siz[p] * K; ++a){
                    for(int b = 0; b <= 5; ++b){
                        dp[p][a][b] = tmp[a][b], tmp[a][b] = 0;
                    }
                }
                // // dp[p].clear();
                // ++cidx[p];
                // // for(auto it = tmp[cnt_tmp].begin(); it != tmp[cnt_tmp].end(); advance(it, 1)/*it = tmp.erase(it)*/)
                // for(auto mp : tmp[cnt_tmp])
                //     // dp[p][cidx[p]][{it->first.first, it->first.second}] = it->second;
                //     dp[p][cidx[p]][mp.first] = mp.second;
                // ++cnt_tmp;
                // // tmp.clear();
                // // for(int a = 0; a <= siz[p] * K; ++a)for(int b = 0; b <= siz[p] * K; ++b)
                // //     dp[p][a][b] = tmp[a][b], tmp[a][b] = 0;
            }
        }; dfs_dp(dfs_dp);
        // for(int i = 0; i <= N * K; ++i)for(int j = 0; j <= 5; ++j)(ans[i + j] += dp[1][cidx[1]][{i, j}]) %= MOD;
        // for(int i = 1; i <= N * K; ++i)printf("%lld\n", ans[i]);
        for(int i = 0; i <= N * K; ++i)for(int j = 0; j <= 5; ++j)(ans[i + j] += dp[1][i][j]) %= MOD;
        for(int i = 1; i <= N * K; ++i)printf("%lld\n", ans[i]);
    }
}

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    N = read(), K = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }
    // if(N <= 8)Sub1::Make();
    // else if(K == 1)Sub2::Make();
    // else 
    Sub4::Make();
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