#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
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

int N;
ll ans(0);

struct Earn{
    ll t;
    ll x, y;
    ll v;
    ll ftmp1, ftmp2;
};
basic_string < Earn > E;
basic_string < ll > data1, data2;

class BIT_D1{
private:
    unordered_map < int, ll > tr;
public:
    int lowbit(int x){return x & -x;}
    void Modify(int x, ll v/*ftmp2, dp(j)*/){while(x <= N)tr[x] = max(tr[x], v), x += lowbit(x);}
    ll Query(int x){ll ret(0); while(x)ret = max(ret, tr[x]), x-= lowbit(x); return ret;}
};
class BIT_D2{
private:
    unordered_map < int, BIT_D1 > tr;
public:
    int lowbit(int x){return x & -x;}
    void Modify(int x1, int x2, ll v/*ftmp1, ftmp2, dp(j)*/){while(x1 <= N)tr[x1].Modify(x2, v), x1 += lowbit(x1);}
    ll Query(int x1, int x2){ll ret(0); while(x1)ret = max(ret, tr[x1].Query(x2)), x1 -= lowbit(x1); return ret;}
}bit;

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    N = read();
    for(int i = 1; i <= N; ++i){
        int t = read(), x = read(), y = read(), v = read();
        if(t - x - y < 0)continue;
        E += {t, x, y, v, t - x - y, t + x - y};
        data1 += t - x - y, data2 += t + x - y;
    }
    sort(E.begin(), E.end(), [](const Earn &a, const Earn &b)->bool{
        if(a.y != b.y)return a.y < b.y;
        if(a.ftmp1 != b.ftmp1)return a.ftmp1 < b.ftmp1;
        return a.ftmp2 < b.ftmp2;
    });
    sort(data1.begin(), data1.end()), sort(data2.begin(), data2.end());
    for(auto &e : E)
        e.ftmp1 = distance(data1.begin(), lower_bound(data1.begin(), data1.end(), e.t - e.x - e.y)) + 1,
        e.ftmp2 = distance(data2.begin(), lower_bound(data2.begin(), data2.end(), e.t + e.x - e.y)) + 1;
    for(auto e : E){
        ll ret = bit.Query(e.ftmp1, e.ftmp2) + e.v;
        ans = max(ans, ret);
        bit.Modify(e.ftmp1, e.ftmp2, ret);
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