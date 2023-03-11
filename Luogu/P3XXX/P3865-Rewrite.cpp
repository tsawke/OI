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

int N, Q;
int lg[110000];
int st[110000][20];

int main(){
    lg[1] = 0;
    for(int i = 2; i <= 101000; ++i)lg[i] = lg[i >> 1] + 1;
    N = read(), Q = read();
    for(int i = 1; i <= N; ++i)st[i][0] = read();
    for(int j = 1; j <= lg[N]; ++j)
        for(int i = 1; i <= N - (1 << j) + 1; ++i)
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    while(Q--){
        int l = read(), r = read();
        int len = r - l + 1;
        printf("%d\n", max(st[l][lg[len]], st[r - (1 << lg[len]) + 1][lg[len]]));
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