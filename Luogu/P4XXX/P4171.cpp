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

template < typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[110000];
ROPNEW;
Edge* head[2100];

int N, M;
bitset < 2100 > vis;
basic_string < char > ans;

void dfs(int p){
    vis[p] = true;
    for(auto i = head[p]; i; i = i->nxt)if(!vis[SON])dfs(SON);
}
bool Check(int p){
    vis.reset(), dfs(p);
    for(int i = 1; i <= N; ++i)if(vis[i << 1] && vis[(i << 1) | 1])return false;
    return true;
}

int main(){
    int T = read();
    while(T--){
        memset(head, 0, sizeof head);
        N = read(), M = read();
        for(int i = 1; i <= M; ++i){
            char c = getchar(); while(!isalpha(c))c = getchar();
            bool a = c == 'm'; int x = read();
            c = getchar(); while(!isalpha(c))c = getchar();
            bool b = c == 'm'; int y = read();
            head[((y << 1) + b) ^ 1] = new Edge{head[((y << 1) + b) ^ 1], (x << 1) + a};
            head[((x << 1) + a) ^ 1] = new Edge{head[((x << 1) + a) ^ 1], (y << 1) + b};
        }
        for(int i = 1; i <= N; ++i){
            bool a = Check(i << 1), b = Check((i << 1) | 1);
            // printf("i = %d, a is %d, b is %d\n", i, a ? 1 : 0, b ? 1 : 0);
            if(!a && !b){printf("BAD\n"); break;}
            if(i == N)printf("GOOD\n");
        }
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