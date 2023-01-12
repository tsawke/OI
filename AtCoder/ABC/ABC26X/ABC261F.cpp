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

int N;
int C[310000], X[310000];
ll ans(0);
basic_string < int > ball[310000];
class BIT{
private:
    ll tr[310000];
    queue < int > undel;
public:
    int lowbit(int x){return x & -x;}
    void Modify(int x, int v = 1){while(x <= N)undel.push(x), tr[x] += v, x += lowbit(x);}
    ll Query(int x){ll ret(0); while(x)ret += tr[x], x -= lowbit(x); return ret;}
    void clear(void){while(!undel.empty())tr[undel.front()] = 0, undel.pop();}
}bit;

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)ball[C[i] = read()] += i;
    for(int i = 1; i <= N; ++i){
        X[i] = N - read() + 1;
        ans += bit.Query(X[i] - 1);
        bit.Modify(X[i]);
    }
    for(int i = 1; i <= N; ++i){
        if(ball[i].empty())continue;
        bit.clear();
        ll cnt(0);
        for(auto idx : ball[i]){
            cnt += bit.Query(X[idx] - 1);
            bit.Modify(X[idx]);
        }ans -= cnt;
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