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

int N;
int A[110000];
int pos[110000];
// bitset < 110000 > vis;
int dp[110000];
int mx(0), mxv(-1);

int main(){
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    N = read();
    for(int i = 1; i <= N; ++i)pos[A[i] = read()] = i;
    for(int i = 1; i <= N; ++i){
        dp[A[i]] = dp[A[i] - 1] + 1;
        if(dp[A[i]] > mx)mx = dp[A[i]], mxv = A[i];
    }
    int lim1 = mxv - mx + 1, lim2 = mxv;
    printf("%d\n", N - mx);
    for(int i = lim1 - 1; i; --i)printf("%d 0\n", i);
    for(int i = lim2 + 1; i <= N; ++i)printf("%d 1\n", i);
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