#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr

******************************/

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MOD (ll)(1e9 + 7)
#define MAXN 310000

template<typename T = int>
inline T read(void);

int N;
int a[MAXN];
int lft[MAXN], rht[MAXN];
ll dp[MAXN];
ll ans(0);
stack < int > cur;

class TreeArray{
    private:
        int lim;
        ll tr[MAXN];
    public:
        void set(int lim){this->lim = lim;}
        int lowbit(int x){return x & -x;}
        void add(int x, ll v){while(x <= lim)tr[x] = (tr[x] + v) % MOD, x += lowbit(x);}
        ll query(int x){ll ret(0); while(x)ret = (ret + tr[x]) % MOD, x -= lowbit(x); return ret;}
}tr;

int main(){
    N = read();tr.set(N);
    for(int i = 1; i <= N; ++i)a[i] = read();
    for(int i = 1; i <= N; ++i){
        while(!cur.empty() && a[cur.top()] > a[i])rht[cur.top()] = i - 1, cur.pop();
        cur.push(i);
    }while(!cur.empty())rht[cur.top()] = N, cur.pop();
    for(int i = N; i >= 1; --i){
        while(!cur.empty() && a[cur.top()] > a[i])lft[cur.top()] = i + 1, cur.pop();
        cur.push(i);
    }while(!cur.empty())lft[cur.top()] = 1, cur.pop();
    tr.add(1, 1);
    for(int i = 1; i <= N; ++i){
        dp[i] = (tr.query(N) - tr.query(lft[i] - 1) + MOD) % MOD;
        tr.add(rht[i], dp[i]);
    }
    int cmn(INT_MAX);
    for(int i = N; i >= 1; --i){cmn = min(cmn, a[i]); if(cmn == a[i])ans = (ans + dp[i]) % MOD;}
    printf("%lld\n", ans);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template<typename T>
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