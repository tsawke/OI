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

int N, M, K;
int a[2100000];

namespace Sub1{
    struct Ans{int flag; int a, b;};
    pair < int, bool > mp[610];
    int stk[310][2];
    basic_string < pair < int, bool > > unfix;
    basic_string < Ans > ans[2100000];
    void Make(void){
        memset(mp, 0, sizeof mp);
        memset(stk, 0, sizeof stk);
        for(int i = 1; i <= M; ++i)ans[i].clear(), ans[i].shrink_to_fit();
        unfix.clear();
        for(int i = N - 1; i >= 1; --i)unfix += {{i, 0}, {i, 1}};
        for(int i = 1; i <= M; ++i){
            int col(a[i]), cur(N);
            if(mp[col].first){
                if(mp[col].second){
                    ans[i] += {Ans{1, cur}, Ans{2, mp[col].first, cur}};
                    if(stk[mp[col].first][0])
                        unfix += {mp[col].first, 0},
                        mp[stk[mp[col].first][0]].second = 1;
                    else
                        unfix += {mp[col].first, 1};
                    stk[mp[col].first][1] = stk[mp[col].first][0];
                    stk[mp[col].first][0] = 0;
                    mp[col] = {0, 0};
                }
                else{
                    ans[i] += {Ans{1, mp[col].first}};
                    unfix += mp[col];
                    stk[mp[col].first][mp[col].second] = 0;
                    mp[col] = {0, 0};
                }
            }else{
                if(!unfix.empty()){
                    ans[i] += Ans{1, unfix.back().first};
                    mp[a[i]] = unfix.back();
                    stk[mp[col].first][mp[col].second] = col;
                    unfix.pop_back();
                }else{
                    printf("Error!\n"), exit(1);
                }
            }
            // printf("Finish %d\n", i);
            // printf("unfix: ");
            // for(auto tmpp : unfix)printf("(%d, %d) ", tmpp.first, tmpp.second ? 1 : 0);
            // printf("\n");
            // for(int i = 1; i <= 4; ++i)
            //     printf("mp[%d] = %d, %d\n", i, mp[i].first, mp[i].second ? 1 : 0);
        }
        ll tot(0);
        for(int i = 1; i <= M; ++i)tot += ans[i].size();
        printf("%lld\n", tot);
        for(int i = 1; i <= M; ++i)
            for(auto opt : ans[i])
                if(opt.flag == 1)printf("1 %d\n", opt.a);
                else printf("2 %d %d\n", opt.a, opt.b);
    }
}
namespace Sub2{//1 - down, 0 - up
    struct Ans{int flag; int a, b;};
    basic_string < Ans > ans[2100000];
    pair < int, bool > mp[610];
    int cur(N);
    basic_string < pair < int, bool > > unfix;
    int stk[310][2];
    pair < int, bool > mark[610];
    void Make(void){
        for(int i = 1; i <= M; ++i)ans[i].clear(), ans[i].shrink_to_fit();
        memset(mp, 0, sizeof mp);
        memset(mark, 0, sizeof mark);
        memset(stk, 0, sizeof stk);
        cur = N, unfix.clear();
        for(int i = N - 1; i >= 1; --i)unfix += {{i, 0}, {i, 1}};
        for(int i = 1; i <= M; ++i){
            int col = a[i];
            if(mp[col].first){
                if(mp[col].second){
                    ans[i] += {Ans{1, cur}, Ans{2, mp[col].first, cur}};
                    if(stk[mp[col].first][0])
                        unfix += {mp[col].first, 0},
                        mp[stk[mp[col].first][0]].second = 1;
                    else
                        unfix += {mp[col].first, 1};
                    stk[mp[col].first][1] = stk[mp[col].first][0];
                    stk[mp[col].first][0] = 0;
                    mp[col] = {0, 0};
                }
                else{
                    ans[i] += {Ans{1, mp[col].first}};
                    unfix += mp[col];
                    stk[mp[col].first][mp[col].second] = 0;
                    mp[col] = {0, 0};
                }
            }else{
                if(!unfix.empty()){
                    ans[i] += Ans{1, unfix.back().first};
                    mp[col] = unfix.back();
                    stk[mp[col].first][mp[col].second] = col;
                    unfix.pop_back();
                }else{
                    int nxt;
                    for(nxt = i + 1; nxt <= M; ++nxt){
                        if(a[nxt] == col)break;
                        // if(!ans[nxt].empty())continue;
                        int ccol(a[nxt]);
                        if(!mp[ccol].first){
                            ans[nxt] += Ans{1, mark[ccol].first};
                            unfix.erase(find(unfix.begin(), unfix.end(), mark[ccol]));
                            mp[ccol] = mark[ccol];
                            stk[mp[ccol].first][mp[ccol].second] = ccol;
                            mark[ccol] = {0, 0};
                            // if(!unfix.empty()){
                            //     ans[nxt] += Ans{1, unfix.back().first};
                            //     mp[ccol] = unfix.back();
                            //     stk[mp[ccol].first][mp[ccol].second] = ccol;
                            //     unfix.pop_back();
                            // }else{
                            //     printf("Error\n"), exit(0);
                            // }
                        }else{
                            if(!mp[ccol].second){
                                mark[ccol] = mp[ccol];
                                ans[nxt] += Ans{1, mp[ccol].first};
                                unfix += mp[ccol];
                                stk[mp[ccol].first][mp[ccol].second] = 0;
                                mp[ccol] = {0, 0};
                            }else{
                                if(stk[mp[ccol].first][0]){
                                    ans[i] += Ans{1, mp[ccol].first};
                                    ans[nxt] += {Ans{1, cur}, Ans{2, mp[ccol].first, cur}};
                                    int stkpos = mp[ccol].first;
                                    mp[stk[mp[ccol].first][0]].second = 1;
                                    mp[col] = {mp[ccol].first, 0};
                                    mp[ccol] = {0, 0};
                                    stk[stkpos][1] = stk[stkpos][0];
                                    stk[stkpos][0] = col;
                                    break;
                                }else{
                                    stk[mp[ccol].first][0] = 0;
                                    ans[i] += Ans{1, cur};
                                    ans[nxt] += Ans{1, mp[ccol].first};
                                    mp[col] = {cur, 1};
                                    unfix += {cur, 0};
                                    cur = mp[ccol].first;
                                    for(auto it = unfix.begin(); it != unfix.end();)
                                        if(it->first == cur)it = unfix.erase(it);
                                        else advance(it, 1);
                                    stk[mp[ccol].first][1] = 0;
                                    mp[ccol] = {0, 0};
                                    break;
                                }
                            }
                        }
                    }
                    if(ans[i].empty()){
                        ans[i] += Ans{1, cur};
                        ans[nxt] += Ans{1, cur};
                    }i = nxt;
                }
            }
            // printf("Finish %d\n", i);
            // printf("unfix: ");
            // for(auto tmpp : unfix)printf("(%d, %d) ", tmpp.first, tmpp.second ? 1 : 0);
            // printf("\n");
            // for(int i = 1; i <= 3; ++i)
            //     printf("mp[%d] = %d, %d\n", i, mp[i].first, mp[i].second ? 1 : 0);
        }
        ll tot(0);
        for(int i = 1; i <= M; ++i)tot += ans[i].size();
        printf("%lld\n", tot);
        for(int i = 1; i <= M; ++i)
            for(auto opt : ans[i])
                if(opt.flag == 1)printf("1 %d\n", opt.a);
                else printf("2 %d %d\n", opt.a, opt.b);
    }
}

int main(){
    int T = read();
    while(T--){
        N = read(), M = read(), K = read();
        for(int i = 1; i <= M; ++i)a[i] = read();
        if(K == N * 2 - 2)Sub1::Make();
        else Sub2::Make();
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