#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

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

int N; ll K;
ll A[210000];
priority_queue < ll, vector < ll >, greater < ll > > buc;

int main(){
    N = read(), K = read < ll >();
    ll cur(0);
    for(int i = 1; i <= N; ++i)if((A[i] = read < ll >()))buc.push(A[i]), ++cur;
    ll minus(0);
    while(!buc.empty()){
        ll v = buc.top() - minus; buc.pop();
        if((__int128_t)cur * v <= K)K -= cur * v, minus += v, --cur;
        else{minus += K / cur, K -= K / cur * cur; break;}
    }
    for(int i = 1; i <= N; ++i)A[i] = max(0ll, A[i] - minus);
    for(int i = 1; i <= N && K; ++i)if(A[i])--A[i], --K;
    for(int i = 1; i <= N; ++i)printf("%lld%c", A[i], i == N ? '\n' : ' ');
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