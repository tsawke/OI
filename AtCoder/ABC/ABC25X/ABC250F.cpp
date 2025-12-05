#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

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

struct Coord{
    ll x, y;
    friend const ll operator * (const Coord &a, const Coord &b){
        return abs(a.x * b.y - a.y * b.x);//2S
    }
};
ll CalS(Coord a, Coord b, Coord c){
    Coord vec1{b.x - a.x, b.y - a.y}, vec2{c.x - a.x, c.y - a.y};
    return vec1 * vec2;
}
Coord p[110000];
int N;
ll tot(0);
ll ans(LONG_LONG_MAX);
//abs(2A - 8B)
int main(){
    N = read();
    for(int i = 1; i <= N; ++i)p[i].x = read(), p[i].y = read();
    for(int i = 2; i <= N - 1; ++i)tot += CalS(p[1], p[i], p[i + 1]); //2S
    int r(2);
    ll cur(0);
    for(int l = 1; l <= N; ++l){
        while(cur * 4 < tot){
            ans = min(ans, abs(tot - cur * 4));
            cur += CalS(p[l], p[r], p[r % N + 1]);
            (r %= N) += 1;
            // printf("l = %d, r = %d, B = %lld, A = %lld\n", l, r, cur * 4, tot);
        }ans = min(ans, abs(tot - cur * 4));
        cur -= CalS(p[l], p[l + 1], p[r]);
        // ans = min(ans, abs(tot - cur * 4));
    }printf("%lld\n", ans);
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