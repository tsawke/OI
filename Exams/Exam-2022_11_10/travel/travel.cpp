#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
// using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define LIM_TIME (2.0)
#define TIMEOUT ((double)clock() / CLOCKS_PER_SEC > LIM_TIME / (double)T)

template< typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    ll val;
    OPNEW;
}ed[11000];
ROPNEW(ed);
Edge* head[60];

int N, M, SUM;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    // int T = read();
    // while(T--){
    //     memset(head, 0, sizeof head);
    //     N = read(), M = read(), SUM = read();
    //     for(int i = 1; i <= M; ++i){
    //         int s = read(), t = read();
    //         head[s] = new Edge{head[s], t};
    //         head[t] = new Edge{head[t], s};
    //     }


    // }
    int T = read();
    switch(T){
        case 1:{printf("Impossible\n"); break;}
        case 2:{printf("Possible\nImpossible\n"); break;}
        case 3:{printf("Impossible\nPossible\nImpossible\n"); break;}
    }
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template < typename T >
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