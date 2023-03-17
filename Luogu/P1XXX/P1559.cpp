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
ll w[22][22];
int matchx[22], matchy[22];
ll labelx[22], labely[22];
ll slack[22];
int pre[22];
bitset < 22 > visx, visy;

int main(){
    // freopen("in.txt", "r", stdin);
    memset(w, 0xc0, sizeof w);
    memset(labelx, 0xc0, sizeof labelx);
    N = read();
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= N; ++j)w[i][j] = read();
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= N; ++j)w[j][i] *= read();
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
    // for(int i = 1; i <= N; ++i)printf("%d%c", matchy[i], i == N ? '\n' : ' ');
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