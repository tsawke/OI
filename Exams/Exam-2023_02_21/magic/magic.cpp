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

/*
5 4
1 5 3 3 1
3 3 4
4 4 5
2 1 4
5 3 5
*/

template < typename T = int >
inline T read(void);

int N, Q;
int A[210000];
basic_string < int > pos[1100];

// class SegTree{
// private:
//     int tr[210000 << 2];
//     #define LS (p << 1)
//     #define RS (LS | 1)
//     #define MID ((gl + gr) >> 1)
// public:
//     void Pushup()
// }

int main(){
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
    N = read(), Q = read();
    for(int i = 1; i <= N; ++i)pos[A[i] = read()] += i;
    if(N > 5000){
        while(Q--){
            ll ans(0);
            int p = read(), l = read(), r = read();
            r = min(r, N);
            if(p < l)ans = (ll)(l - p + r - p) * (r - p - (l - p) + 1) / 2;
            else if(p > r)ans = (ll)(p - l + p - r) * (p - l - (p - r) + 1) / 2;
            else ans = (ll)(p - l + 1) * (p - l) / 2 + (ll)(r - p + 1) * (r - p) / 2;
            printf("%lld\n", ans);
        }
    }
    while(Q--){
        ll ans(0);
        int p = read(), l = read(), r = read();
        for(int i = l; i <= r; ++i){
            if(pos[i].empty())continue;
            int mn(INT_MAX);
            auto it = lower_bound(pos[i].begin(), pos[i].end(), p);
            if(it != pos[i].end())mn = min(mn, abs(p - *it));
            if(it != pos[i].begin())mn = min(mn, abs(p - *prev(it)));
            if(it != pos[i].end() && next(it) != pos[i].end())mn = min(mn, abs(p - *next(it)));
            ans += mn;
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