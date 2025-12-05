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

#define LIM (51000)

template < typename T = int >
inline T read(void);

ll F[LIM + 100];
ll mu[LIM + 100], smu[LIM + 100];
bitset < LIM + 100 > notPrime;
basic_string < int > Prime;

int main(){mu[1] = 1;
    for(int i = 2; i <= LIM; ++i){
        if(!notPrime[i])Prime += i, mu[i] = -1;
        for(auto p : Prime){
            if((ll)i * p > LIM)break;
            mu[i * p] = i % p == 0 ? 0 : mu[i] * mu[p];
            notPrime[i * p] = true;
            if(i % p == 0)break;
        }
    }
    for(int i = 1; i <= LIM; ++i)smu[i] = smu[i - 1] + mu[i];
    for(int i = 1; i <= LIM; ++i){
        int l = 1;
        while(l <= i){
            int r = i / (i / l);
            F[i] += i / l * (r - l + 1);
            l = r + 1;
        }
    }
    int T = read();
    while(T--){
        ll ans(0);
        int N = read(), M = read();
        int lim = min(N, M);
        int l = 1;
        while(l <= lim){
            int r = min(N / (N / l), M / (M / l));
            ans += (smu[r] - smu[l - 1]) * F[N / l] * F[M / l];
            l = r + 1;
        }printf("%lld\n", ans);
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