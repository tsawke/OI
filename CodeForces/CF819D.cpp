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
ll S, T;
int A[210000];
int ans[210000];
int gcdv(-1);
struct Node{
    ll v; ll origin; int idx;
    friend const bool operator < (const Node &a, const Node &b){
        return a.v < b.v;
    }
};
unordered_map < int, set < Node > > loops;

void exgcd(ll a, ll b, ll &x, ll &y){
    if(!b)return x = 1, y = 0, void();
    exgcd(b, a % b, x, y);
    int tmp(x);
    x = y, y = tmp - a / b * y;
}
ll CalMnX(ll ti, ll tj){
    ll x, y; ll d = (tj - ti) / gcdv;
    exgcd(S, T, x, y);
    x *= d, y *= d;
    ll P = T / gcdv;
    x = (x % P + P) % P;
    y = (tj - ti - S * x) / T;
    return x;
}

int main(){
    T = read(), N = read();
    for(int i = 1; i <= N; ++i)(S += (A[i] = read())) %= T;
    gcdv = __gcd(S, T);
    loops[0].insert({Node{0, 0, 1}});
    ll cur(0);
    for(int i = 2; i <= N; ++i)
        (cur += A[i]) %= T,
        loops[cur % gcdv].insert(Node{CalMnX(cur % gcdv, cur), cur, i});
    for(auto loop : loops){
        if((int)loop.second.size() == 1){ans[loop.second.begin()->idx] = T / gcdv; continue;}
        for(auto it = loop.second.begin(); it != loop.second.end(); advance(it, 1)){
            auto nxit = it == prev(loop.second.end()) ? loop.second.begin() : next(it);
            ans[it->idx] = CalMnX(it->origin, nxit->origin);
        }
    }
    for(int i = 1; i <= N; ++i)printf("%d%c", ans[i], i == N ? '\n' : ' ');
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