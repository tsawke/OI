#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

using namespace std;
using namespace __gnu_pbds;

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
multiset < int > s;
ll ans(0);

int main(){
    // freopen("abs3.in", "r", stdin);
    // freopen("out.txt", "w", stdout);
    N = read(), Q = read();
    for(int i = 1; i <= N; ++i)s.insert(read());
    for(auto it = s.begin(); next(it) != s.end(); advance(it, 1))
        ans += abs(*next(it) - *it);
    ans += abs(*prev(s.end()) - *s.begin());
    while(Q--){
        int opt = read(), v = read();
        if(opt == 1){
            auto it = s.find(v);
            if(it == s.end()){printf("-1\n"); continue;}
            auto pre = it == s.begin() ? prev(s.end()) : prev(it), nxt = it == prev(s.end()) ? s.begin() : next(it);
            ans -= abs(*it - *pre) + abs(*nxt - *it);
            ans += abs(*nxt - *pre);
            s.erase(it);
        }else{
            auto it = s.insert(v);
            auto pre = it == s.begin() ? prev(s.end()) : prev(it), nxt = it == prev(s.end()) ? s.begin() : next(it);
            ans += abs(*it - *pre) + abs(*nxt - *it);
            ans -= abs(*nxt - *pre);
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