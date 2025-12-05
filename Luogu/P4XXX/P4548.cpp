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

int N, M;
int vals[110000];
int nxt[110000];
ll powN[110000];
ll ans(0);

int main(){powN[0] = 1;
    N = read();
    for(int i = 1; i <= 101000; ++i)powN[i] = powN[i - 1] * N % 10000;
    int T = read();
    while(T--){
        M = read();
        ans = powN[M];
        for(int i = 1; i <= M; ++i)vals[i] = read();
        int lst(0);
        nxt[0] = nxt[1] = 0;
        for(int i = 2; i <= M; ++i){
            while(lst && vals[lst + 1] != vals[i])lst = nxt[lst];
            if(vals[lst + 1] == vals[i])++lst;
            nxt[i] = lst;
        }int cur(nxt[M]);
        while(cur)
            (ans += powN[cur]) %= 10000,
            cur = nxt[cur];
        printf("%04lld\n", ans);
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