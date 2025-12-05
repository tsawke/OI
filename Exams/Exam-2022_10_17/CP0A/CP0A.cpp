#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template<typename T = int>
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[310000];
ROPNEW(ed);

Edge* head[150000];
int N, Q;
int val[150000];
int dep[150000];
int pre[150000];
void dfs(int p = 1, int fa = 0){
    dep[p] = dep[fa] + 1;
    pre[p] = fa;
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa)dfs(SON, p);
}
int Make(int S, int T){
    int ret(-1);
    if(dep[S] >= dep[T]){
        int SS = S;
        while(T != SS){
            ret = max(ret, val[SS] ^ abs(dep[SS] - dep[S]));
            // printf("val: %d xor %d = %d\n", val[S], abs(dep[T] - dep[S]), val[S] ^ abs(dep[T] - dep[S]));
            SS = pre[SS];
        }ret = max(ret, val[SS] ^ abs(dep[SS] - dep[S]));
    }else{
        while(S != T){
            ret = max(ret, val[S] ^ abs(dep[T] - dep[S]));
            // printf("val: %d xor %d = %d\n", val[S], abs(dep[T] - dep[S]), val[S] ^ abs(dep[T] - dep[S]));
            T = pre[T];
        }ret = max(ret, val[S] ^ abs(dep[T] - dep[S]));
    }
    // int len = abs(dep[S] - dep[T]);
    // printf("len s = %d, t = %d, is %d\n", S, T, len);
    // if(dep[s] < dep[t])swap(s, t);
    // while(S != T){
    //     ret = max(ret, val[S] ^ abs(dep[T] - dep[S]));
    //     printf("val: %d xor %d = %d\n", val[S], abs(dep[T] - dep[S]), val[S] ^ abs(dep[T] - dep[S]));
    //     S = pre[S];
    // }ret = max(ret, val[S] ^ 0);
    return ret;
}

int main(){
    freopen("CP0A.in", "r", stdin);
    freopen("CP0A.out", "w", stdout);
    N = read(), Q = read();
    for(int i = 1; i <= N; ++i)val[i] = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }dfs();
    while(Q--){
        int s = read(), t = read();
        printf("%d\n", Make(t, s));
    }

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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