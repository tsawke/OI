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

#define NM (N + M)

template< typename T = int >
inline T read(void);

vector < int > data;
struct Node{
    int idx;
    int x, y;
    int rx, ry;
    int t;
    friend const bool operator < (Node a, Node b){return a.x < b.x;}
}nod[210000];

int N, M;
ll lim;
ll ans[110000];

class BIT{
private:
    ll tr[410000];
public:
    void clear(void){memset(tr, 0x3f, sizeof tr);}
    int lowbit(int x){return x & -x;}
    void Modify(int x, ll v){while(x <= lim)tr[x] = min(tr[x], v), x += lowbit(x);}
    ll Query(int x){ll ret((ll)INT_MAX * 114514); while(x)ret = min(ret, tr[x]), x -= lowbit(x); return ret;}
}bit;

void Make(void){
    sort(nod + 1, nod + NM + 1);
    bit.clear();
    for(int i = 1; i <= NM; ++i){
        if(!~nod[i].t)ans[nod[i].idx] = min(ans[nod[i].idx], bit.Query(nod[i].y) + nod[i].rx + nod[i].ry);
        else bit.Modify(nod[i].y, (ll)-nod[i].rx - nod[i].ry + nod[i].t);
    }
}

int main(){
    memset(ans, 0x3f, sizeof ans);
    N = read(), M = read();
    for(int i = 1; i <= N; ++i){
        int x = read(), y = read(), t = read();
        nod[i] = Node{i, x, y, x, y, t};
        data.emplace_back(x), data.emplace_back(y);
    }
    for(int i = 1; i <= M; ++i){
        int x = read(), y = read();
        nod[i + N] = Node{i, x, y, x, y, -1};
        data.emplace_back(x), data.emplace_back(y);
        ans[i] = abs(y - x);
    }sort(data.begin(), data.end());
    data.erase(unique(data.begin(), data.end()), data.end());
    lim = data.size();
    for(int i = 1; i <= NM; ++i)
        nod[i].x = distance(data.begin(), lower_bound(data.begin(), data.end(), nod[i].x) + 1),
        nod[i].y = distance(data.begin(), lower_bound(data.begin(), data.end(), nod[i].y) + 1);
    Make();
    for(int i = 1; i <= NM; ++i)
        nod[i].x = -nod[i].x + lim + 1, nod[i].rx = -nod[i].rx;
    Make();
    for(int i = 1; i <= NM; ++i)
        nod[i].y = -nod[i].y + lim + 1, nod[i].ry = -nod[i].ry;
    Make();
    for(int i = 1; i <= NM; ++i)
        nod[i].x = -nod[i].x + lim + 1, nod[i].rx = -nod[i].rx;
    Make();
    for(int i = 1; i <= M; ++i)printf("%lld\n", ans[i]);
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