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
int A[20], B[20];
ll mul(1);
ll ans(0);

void exgcd(ll a, ll b, ll &x, ll &y){
    if(!b)return x = 1, y = 0, void();
    exgcd(b, a % b, x, y);
    ll tmp(x);
    x = y, y = tmp - a / b * y;
}
ll CalInv(ll a, ll b){
    ll x, y; exgcd(a, b, x, y);
    ll mod = b / __gcd(a, b);
    return (x % mod + mod) % mod;
}

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)A[i] = read(), B[i] = read();
    for(int i = 1; i <= N; ++i)mul *= A[i];
    for(int i = 1; i <= N; ++i)(ans += B[i] * (mul / A[i]) * CalInv(mul / A[i], A[i]) % mul) %= mul;
    printf("%lld\n", ans);
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