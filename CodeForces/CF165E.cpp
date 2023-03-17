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

const int Smx = (1 << 23) - 1;

int N;
int A[4100000];
int dp[Smx + 114514];

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)A[i] = read(), dp[A[i]] = A[i];
    for(int i = 0; i <= 22; ++i)
        for(int S = Smx; S; S = (S - 1) & Smx)
            if(S & (1 << i))dp[S] = dp[S] ? dp[S] : dp[S ^ (1 << i)];
    for(int i = 1; i <= N; ++i){
        int val = A[i] ^ Smx;
        printf("%d%c", dp[val] ? dp[val] : -1, i == N ? '\n' : ' ');
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