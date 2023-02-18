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
int A[1100];
int pre[1100], nxt[1100];

ll ans(0);
basic_string < int > P;

void Make(void){
    for(int i = 1; i <= N; ++i)pre[i] = i - 1, nxt[i] = i + 1;
    pre[0] = 0, nxt[N + 1] = N + 1;
    ll cur(0);
    for(auto pos : P){
        cur += min(A[pre[pos]], A[nxt[pos]]);
        pre[nxt[pos]] = pre[pos];
        nxt[pre[pos]] = nxt[pos];
    }ans = max(ans, cur);
}

int main(){
    int T = read();
    while(T--){
        P.clear();
        for(int i = 0; i <= N + 2; ++i)A[i] = 0;
        N = read();
        ans = 0;
        for(int i = 1; i <= N; ++i)A[i] = read();
        ll mul(1);
        for(int i = 1; i <= N; ++i)P += i, mul *= i;
        for(int i = 1; i <= mul; ++i){
            Make();
            next_permutation(P.begin(), P.end());
        }
        printf("%lld\n", ans);
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