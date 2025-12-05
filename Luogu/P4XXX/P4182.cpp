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

template< typename T = int >
inline T read(void);

struct Line{
    int l, r;
    friend const bool operator < (const Line &a, const Line &b){if(a.l == b.l)return a.r < b.r; return a.l < b.l;}
}line[110000];
list < Line > _line;
int N, K;
int cnt(0);
struct Status{int idx; int val;};
deque < Status > bst[110000];
int mx[110000];
int dp[110000][110];

int main(){
    N = read(), K = read();
    for(int i = 1; i <= N; ++i){
        int l = read(), r = read();
        _line.emplace_back(Line{l, r});
    }_line.sort();
    for(auto it = next(_line.begin()); it != _line.end();)
        if(it->r <= prev(it)->r)it = _line.erase(it), --K; else ++it;
    for(auto ln : _line)line[++cnt] = ln;
    N = cnt; K = max(0, K);
    for(int i = 1; i <= N; ++i){
        for(int k = 0; k <= min(i - 1, K); ++k){
            int xi = i - k - 1;
            while(!bst[xi].empty() && line[bst[xi].front().idx].r < line[i].l){
                auto tp = bst[xi].front(); bst[xi].pop_front();
                mx[xi] = max(mx[xi], tp.val + line[tp.idx].r);
            }
            dp[i][k] = max({
                dp[i][k],
                mx[xi] + line[i].r - line[i].l,
                bst[xi].empty() ? -1 : bst[xi].front().val + line[i].r
            });
            int val = dp[i][k] - line[i].r;
            int pos = i - k;
            while(!bst[pos].empty() && bst[pos].back().val < val)bst[pos].pop_back();
            bst[pos].push_back(Status{i, val});
        }
    }int ans(-1);
    for(int i = N - K; i <= N; ++i)ans = max(ans, dp[i][K - (N - i)]);
    printf("%d\n", ans);
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