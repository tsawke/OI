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

#define MOD (ll)(1e9 + 7)
#define LIM (110000)

template < typename T = int >
inline T read(void);

int N;
ll A[LIM];
ll phi[LIM + 100];
ll sum[LIM + 100];
bitset < LIM + 100 > notPrime;
basic_string < int > Prime;

int main(){
    freopen("gcd.in", "r", stdin);
    freopen("gcd.out", "w", stdout);
    N = read();
    for(int i = 1; i <= N; ++i)A[i] = read();
    if(N <= 10000){
        ll ans(0);
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= N; ++j)
                (ans += (ll)(__gcd(i, j) * __gcd(A[i], A[j])) % MOD) %= MOD;
        printf("%lld\n", ans);
    }else{
        ll ans(0);
        phi[1] = 1;
        for(int i = 2; i <= LIM; ++i){
            if(!notPrime[i])Prime += i, phi[i] = i - 1;
            for(auto p : Prime){
                if((ll)i * p > LIM)break;
                notPrime[i * p] = true;
                if(i % p)phi[i * p] = phi[i] * phi[p];
                else phi[i * p] = phi[i] * p;
                if(i % p == 0)break;
            }
        }
        for(int i = 1; i <= N; ++i)sum[i] = (sum[i - 1] + (phi[i] << 1)) % MOD;
        for(int i = 1; i <= N; ++i){
            (ans += (ll)(sum[N / i] - 1) * i % MOD * i % MOD) %= MOD;
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