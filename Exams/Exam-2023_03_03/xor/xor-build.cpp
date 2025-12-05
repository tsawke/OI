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

#define INF (0x3f3f3f3f)
#define MOD (1ll << 32)

int main(){
    freopen("in.txt", "w", stdout);
    int N = 300000, Q = 300000;
    printf("%d\n", N);
    for(int i = 1; i <= N; ++i)printf("%lld%c", (ll)rndd(1, INF) * rndd(1, INF) % MOD, i == N ? '\n' : ' ');
    printf("%d\n", Q);
    for(int i = 1; i <= Q; ++i){
        int l = rndd(1, 300000), r = rndd(l, 300000);
        printf("%d %d\n", l, r);
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