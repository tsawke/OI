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

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[210000];
ROPNEW(ed);
Edge* head[11000];

int N, M;
int deg[11000];

namespace New{
    int cnt(0);
    int ddeg[11000];
    int belong[11000];
    // basic_string < int > pts[11000];
    // Edge* head[11000];
    bitset < 11000 > vis;
    basic_string < int > ans;
    // void SetGraph(int p, int idx){
    //     vis[p] = true;
    //     if(deg[p] == 2){belong[p] = ++cnt/*, pts[cnt] += p;*/ return;}
    //     belong[p] = idx;//, pts[idx] += p;
    //     for(auto i = ::head[p]; i; i = i->nxt)
    //         if(!vis[SON])SetGraph(SON, idx);
    // }
    void SetAns(int p = 1, bool flag = false){
        vis[p] = true;
        for(auto i = ::head[p]; i; i = i->nxt){
            if(vis[SON])continue;
            if(flag && belong[SON] == belong[p])SetAns(SON, false);
            else if((!flag && belong[SON] != belong[p]) || deg[p] == 2)SetAns(SON, true);
        }ans += p;
    }
    void Build(void){
        for(int i = 1; i <= N; ++i)
            if(deg[i] > 2 && !vis[i]){//vis[i] = true, SetGraph(i, ++cnt);
                belong[i] = ++cnt, vis[i] = true;
                for(auto j = ::head[i]; j; j = j->nxt){
                    if(deg[j->to] == 2)continue;
                    vis[j->to] = true;
                    belong[j->to] = cnt;
                    // pts[cnt] += j->to;
                }
            }
            else if(deg[i] == 2 && !vis[i])vis[i] = true, belong[i] = ++cnt;//, pts[cnt] += i;
        for(int p = 1; p <= N; ++p)
            for(auto i = ::head[p]; i; i = i->nxt)
                if(belong[p] != belong[SON])
                    // printf("from %d to %d, belong : %d -> %d\n", p, SON, belong[p], belong[SON]),
                    ++ddeg[belong[p]], ++ddeg[belong[SON]];
                    // head[belong[p]] = new Edge{head[belong[p]], belong[SON]},
                    // head[belong[SON]] = new Edge{head[belong[SON]], belong[p]};
    }
    void Make(void){
        // int tot(0);
        // vis.reset();
        // int cur = 1;
        // while(true){
        //     vis[cur] = true, ++tot; //ans += cur;//pts[cur];
        //     bool flag(false);
        //     for(auto i = head[cur]; i; i = i->nxt)
        //         if(!vis[SON]){cur = SON, flag = true; break;}
        //     if(!flag)break;
        // }printf("tot = %d, cnt = %d\n", tot, cnt);
        // if(tot != cnt)printf("-1\n"), exit(0);
        // basic_string < int > rans;
        // for(int i = 1; i <= (int)ans.size(); ++i){
        //     if(i == 1)
        // }
        // vis.reset();
        // for(int i = 1; i <= (int)ans.size(); ++i){
        //     if(vis[i])continue;
        //     vis[i] = true;
        //     if(i == ans.size()){rans += ans.at(i - 1); break;}
        //     bool flag(false);
        //     for(auto j = ::head[ans.at(i - 1)]; j; j = j->nxt)
        //         if(j->to == ans.at(i)){flag = true; break;}
        //     if(flag){rans += ans.at(i - 1); break;}
        //     for(int j = i + 2; j <= (int)ans.size(); ++j){
        //         bool fflag(false);
        //         for(auto k = ::head[ans.at(i - 1)]; k; k = k->nxt)
        //             if(k->to == ans.at(j - 1)){fflag = true; rans += ans.at(j - 1), vis[j] = true; break;}
        //         if(fflag)break;
        //     }
        // }
        // for(auto p : ans)printf("%d ", p);
        // printf("\n");
        for(int i = 1; i <= cnt; ++i)
            if((ddeg[i] >> 1) & 1)printf("-1\n"), exit(0);
        // for(int i = 1; i <= cnt; ++i)printf("ddeg[%d] = %d\n", i, ddeg[i]);
        vis.reset();
        SetAns();
        // if((int)ans.size() != N)printf("-1\n"), exit(0);

        for(auto p : ans)printf("%d ", p);
        printf("\n");
    }
}

int main(){
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
        ++deg[s], ++deg[t];
    }
    New::Build();
    New::Make();
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