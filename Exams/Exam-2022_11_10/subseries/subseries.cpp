#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
// using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MOD (ll)(1e9 + 7)

template< typename T = int >
inline T read(void);

int lim;
int N;
int a[110000];
int ra[110000];
bool exist[110000];
ll ans(0);
vector < int > data;
vector < int > tmp;

class BIT{
private:
    ll tr[210000];
public:
    int lowbit(int x){return x & -x;}
    void Modify(int x, ll v){while(x <= lim)tr[x] = (tr[x] + v) % MOD, x += lowbit(x);}
    ll Query(int x){ll ret(0); while(x)ret = (ret + tr[x]) % MOD, x -= lowbit(x); return ret;}
    ll QueryPoint(int x){return (Query(x) - Query(x - 1) + MOD) % MOD;}
    ll QueryReal(int x){ll tmp = QueryPoint(x); return (Query(x - 1) - (tmp ? tmp - 1 : 0) + MOD) % MOD;}
}bit;

int main(){
    freopen("subseries.in", "r", stdin);
    freopen("subseries.out", "w", stdout);
    lim = N = read();
    for(int i = 1; i <= N; ++i)a[i] = read(), data.emplace_back(a[i]);
    sort(data.begin(), data.end());
    for(int i = 1; i <= N; ++i)a[i] = distance(data.begin(), lower_bound(data.begin(), data.end(), a[i]) + 1);
    // for(int i = N; i <= 1; ++i)if(!exist[a[i]])exist[a[i]] = true, tmp.emplace_back(a[i]);
    // for(auto it = tmp.rbegin(); it != tmp.rend(); ++it)ra[++lim] = *it;
    for(int i = 1; i <= N; ++i){
        ll ret = bit.QueryReal(a[i]);
        // for(int j = 1; j <= N; ++j)
        //     printf("Query range : %d = %lld, point : %d = %lld\n", j, bit.Query(j), j, bit.QueryPoint(j));
        // printf("point: %lld, ret = %lld\n", bit.QueryPoint(a[i]), ret);
        bit.Modify(a[i], ret + (bit.QueryPoint(a[i]) ? 0 : 1));
        ans = (ans + ret) % MOD;
    }printf("%lld\n", ans);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    short flag(1);
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