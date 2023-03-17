#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
// #define E M_E
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



template < typename T = int >
inline T read(void);

int N, M, E;
struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[110000];
ROPNEW;
Edge* head[51000];

int ans(0);
int pre[51000];
int match[51000];

int main(){
    N = read(), M = read(), E = read();
    for(int i = 1; i <= E; ++i){
        int s = read(), t = read() + N;
        head[s] = new Edge{head[s], t};
    }
    auto bfs = [](int S)->bool{
        queue < int > cur;
        bitset < 51000 > vis; vis.reset();
        cur.push(S); pre[S] = -1;
        // bool flag(false);
        while(!cur.empty()){
            int p = cur.front(); cur.pop();
            for(auto i = head[p]; i; i = i->nxt){
                if(vis[SON])continue;
                vis[SON] = true, cur.push(match[SON]);
                if(match[SON])pre[match[SON]] = p;
                else{
                    int s = p, t = SON;
                    while(~s){
                        // printf("New path s = %d, t = %d\n", s, t);
                        int tmp = match[s];
                        match[s] = t, match[t] = s;
                        s = pre[s], t = tmp;
                    }return true;
                }
            }
        }return false;
    };
    for(int i = 1; i <= N; ++i){
        if(!match[i])ans += bfs(i);
        // for(int i = 1; i <= N + M; ++i)printf("match[%d] = %d\n", i, match[i]);
    }
    
    printf("%d\n", ans);
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