#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define BLK(x) (x / QueryLen + 1)
#define MAXN 110000

template<typename T = int>
inline T read(void);

int N, M;
int QueryLen;
int splitM;
int a[MAXN];
int cnt[MAXN], len[MAXN];
bitset < MAXN > cur;
bitset < MAXN > sum[MAXN];

struct Query{
    int l, r;
    int idx;
    friend const bool operator < (const Query &x, const Query &y){
        int xb = BLK(x.l), yb = BLK(y.l);
        if(xb != yb)return xb < yb;
        return xb & 1 ? x.r < y.r : x.r > y.r;
    }
};
void add(int v){cur.set(v + cnt[v]++);}
void del(int v){cur.reset(v + --cnt[v]);}
void Solve(void){
    memset(cnt, 0, sizeof(cnt));
    cur.reset();
    int tot(0);
    vector < Query > qs;
    while(++tot <= splitM && M--){
        len[tot] = 0;
        sum[tot].set();
        int T = 3;
        while(T--){
            int l = read(), r = read();
            qs.push_back(Query{l, r, tot});
            len[tot] += r - l + 1;
        }
    }sort(qs.begin(), qs.end());
    int gl(1), gr(0);
    for(auto q : qs){
        while(gl > q.l)add(a[--gl]);
        while(gr < q.r)add(a[++gr]);
        while(gl < q.l)del(a[gl++]);
        while(gr > q.r)del(a[gr--]);
        sum[q.idx] &= cur;
    }--tot;
    for(int i = 1; i <= tot; ++i)
        printf("%d\n", len[i] - 3 * (int)sum[i].count());
}
int main(){
    freopen("d0te__sturct.in", "r", stdin);
    freopen("d0te__sturct.out", "w", stdout);
    N = read(), M = read();
    vector < int > arr;
    for(int i = 1; i <= N; ++i)a[i] = read(), arr.push_back(a[i]);
    QueryLen = sqrt(N), splitM = M / 3 + 1;
    sort(arr.begin(), arr.end());
    for(int i = 1; i <= N; ++i)a[i] = distance(arr.begin(), lower_bound(arr.begin(), arr.end(), a[i])) + 1;
    Solve(), Solve(), Solve();
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