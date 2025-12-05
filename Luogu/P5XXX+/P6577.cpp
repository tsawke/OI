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

#define INF (0x3f3f3f3f3f3f3f3fll)

template < typename T = int >
inline T read(void);

int N, M;
ll w[510][510];
int matchx[510], matchy[510];
ll labelx[510], labely[510];
ll slack[510];
int pre[510];
bitset < 510 > visx, visy;

int main(){
    // freopen("in.txt", "r", stdin);
    memset(w, 0xc0, sizeof w);
    memset(labelx, 0xc0, sizeof labelx);
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), v = read();
        w[s][t] = v;
    }
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= N; ++j)labelx[i] = max(labelx[i], w[i][j]);
    auto KM = [](int S)->void{
        auto Rematch = [](int p)->void{
            while(p){
                int tmp = matchx[pre[p]];
                matchx[pre[p]] = p, matchy[p] = pre[p];
                p = tmp;
            }
        };
        visx.reset(), visy.reset();
        memset(slack, 0x3f, sizeof slack);
        queue < int > cur; cur.push(S);
        while(true){
            while(!cur.empty()){
                int p = cur.front(); cur.pop();
                visx[p] = true;
                for(int i = 1; i <= N; ++i){
                    if(visy[i])continue;
                    if(labelx[p] + labely[i] - w[p][i] < slack[i]){
                        slack[i] = labelx[p] + labely[i] - w[p][i];
                        pre[i] = p;
                        if(!slack[i]){
                            visy[i] = true;
                            if(matchy[i])cur.push(matchy[i]);
                            else return Rematch(i);
                        }
                    }
                }
            }ll d = INF;
            for(int i = 1; i <= N; ++i)if(!visy[i])d = min(d, slack[i]);
            for(int i = 1; i <= N; ++i){
                if(visx[i])labelx[i] -= d;
                if(visy[i])labely[i] += d; else slack[i] -= d;
            }
            for(int i = 1; i <= N; ++i)if(!visy[i] && !slack[i]){
                visy[i] = true;
                if(matchy[i])cur.push(matchy[i]);
                else return Rematch(i);
            }
        }
    };
    for(int i = 1; i <= N; ++i)KM(i);
    ll ans(0);
    for(int i = 1; i <= N; ++i)ans += w[i][matchx[i]];
    printf("%lld\n", ans);
    for(int i = 1; i <= N; ++i)printf("%d%c", matchy[i], i == N ? '\n' : ' ');
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
以此纪念我调了一下午的nt错误，km的过程写在bfs里了。。。

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

// #define INF (0x3f3f3f3f3f3f3f3fll)
#define INF 9990365505
// #define INF (1e8)

template < typename T = int >
inline T read(void);

int N, M;
// ll w[510][510];
int matchx[510], matchy[510];
ll labelx[510], labely[510];
ll slack[510];
int pre[510];
bitset < 510 > visx, visy;
struct Edge{
    Edge* nxt;
    int to;
    ll val;
    OPNEW;
}ed[610000];
ROPNEW;
Edge* head[510];

int main(){
    freopen("in.txt", "r", stdin);
    // memset(w, 0xc0, sizeof w);
    // for(int i = 0; i <= 505; ++i)for(int j = 0; j <= 505; ++j)w[i][j] = -INF;
    // memset(labelx, 0xc0, sizeof labelx);
    // fill(labelx, labelx + 505, -INF);
    for(int i = 0; i <= 505; ++i)labelx[i] = -INF, labely[i] = 0;
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), v = read();
        // w[s][t] = v;
        head[s] = new Edge{head[s], t, v};
        labelx[s] = max(labelx[s], (ll)v);
    }
    // for(int i = 1; i <= N; ++i)for(int j = 1; j <= N; ++j)labelx[i] = max(labelx[i], w[i][j]);
    // for(int i = 1; i <= N; ++i)printf("mx : %d : %lld\n", i, labelx[i]);
    auto KM = [](int S)->void{
        auto Rematch = [](int p)->void{
            while(p){
                int tmp = matchx[pre[p]];
                matchx[pre[p]] = p, matchy[p] = pre[p];
                p = tmp;
            }
        };
        visx.reset(), 
        visy.reset();
        // memset(slack, 0x3f, sizeof slack);
        fill(slack, slack + 505, INF);
        // for(int i = 1; i <= N; ++i)slack[i] = INF, pre[i] = 0;
        memset(pre, 0, sizeof pre);
        queue < int > cur; cur.push(S);
        while(true){
            while(!cur.empty()){
                int p = cur.front(); cur.pop();
                // printf("BFS %d \n", p);
                visx[p] = true;
                // for(int i = 1; i <= N; ++i){
                for(auto i = head[p]; i; i = i->nxt){
                    if(visy[SON])continue;
                    if(labelx[p] + labely[SON] - i->val < slack[SON]){
                        slack[SON] = labelx[p] + labely[SON] - i->val;
                        pre[SON] = p;
                        if(!slack[SON]){
                            visy[SON] = true;
                            if(matchy[SON])cur.push(matchy[SON]);
                            else return Rematch(SON);
                        }
                    }
                }
                ll d = INF;
                for(int i = 1; i <= N; ++i)if(!visy[i])d = min(d, slack[i]);
                while(!cur.empty())cur.pop();
                for(int i = 1; i <= N; ++i){
                    if(visx[i])labelx[i] -= d;
                    if(visy[i])labely[i] += d; else slack[i] -= d;
                }
                for(int i = 1; i <= N; ++i)if(!visy[i] && !slack[i]){
                    visy[i] = true;
                    if(matchy[i])cur.push(matchy[i]);
                    else return Rematch(i);
                }
            }
        }
    };
    for(int i = 1; i <= N; ++i){
        KM(i), printf("In km %d\n", i);
        // for(int j = 1; j <= N; ++j)printf("no. %d match [%d] is %lld, %lld\n", i, j, labelx[j], labely[j]);
    }

    ll ans(0);
    for(int i = 1; i <= N; ++i)ans += labelx[i] + labely[i];//w[i][matchx[i]];
    printf("%lld\n", ans);
    for(int i = 1; i <= N; ++i)printf("%d%c", matchy[i], i == N ? '\n' : ' ');
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

*/