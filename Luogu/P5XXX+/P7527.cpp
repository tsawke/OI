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
int a[210000];
int lstL[210000], lstR[210000];
int l[210000], r[210000];
basic_string < int > lft[210000];

class BIT{
private:
    int tr[210000];
public:
    int lowbit(int x){return x & -x;}
    void Modify(int x, int v = 1){while(x <= N)tr[x] += v, x += lowbit(x);}
    int Query(int x){int ret(0); while(x)ret += tr[x], x -= lowbit(x); return ret;}
    int QueryRange(int l, int r){return Query(r) - (l == 1 ? 0 : Query(l - 1));}
}bit;

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)a[i] = read(), lstR[i] = N + 1;
    for(int i = 1; i <= N; ++i)l[i] = lstL[a[i]] + 1, lstL[a[i]] = i;
    for(int i = N; i >= 1; --i)r[i] = lstR[a[i]] - 1, lstR[a[i]] = i;
    for(int i = 1; i <= N; ++i)lft[l[i]] += i;
    for(int i = 1; i <= N; ++i)bit.Modify(i);
    ll ans(0);
    for(int L = N; L >= 1; --L){
        for(auto p : lft[L + 1])bit.Modify(p, -1);
        ans += bit.QueryRange(L, r[L]);
    }printf("%lld\n", ans - N);
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