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

int N, Q, X;
int W[410000];
ll sum[410000];
int nxt[210000];
ll siz[210000];
ll lftans(0);
bitset < 210000 > vis;
int pos[210000];
int mark[210000];
int pre[210000];

int main(){
    // freopen("in.txt", "r", stdin);
    N = read(), Q = read(), X = read();
    for(int i = 1; i <= N; ++i)sum[i] = sum[i - 1] + (W[i] = read());
    copy(W + 1, W + N + 1, W + N + 1);
    for(int i = N + 1; i <= N << 1; ++i)sum[i] = sum[i - 1] + W[i];
    ll tot = sum[N];
    lftans += ll(X / tot) * N;
    X %= tot;
    if(!X)lftans -= N, X += tot;
    for(int i = 1; i <= N; ++i){
        int l = i, r = N << 1, ans(i - 1);
        while(l <= r){
            int mid = (l + r) >> 1;
            if(sum[mid] - sum[i - 1] < X)ans = mid, l = mid + 1;
            else r = mid - 1;
        }nxt[i] = ans += 2;
        siz[i] = lftans + (nxt[i] - i);
        if(nxt[i] > N)nxt[i] -= N;
    }
    queue < int > path;
    int cur = 1, len = 0;
    while(!vis[cur]){
        path.push(cur);
        vis[cur] = true;
        mark[++len] = cur;
        cur = nxt[cur];
    }int cnt(0);
    while(path.front() != cur)pre[++cnt] = path.front(), path.pop();
    len = 0;
    while(!path.empty())pos[++len] = path.front(), path.pop();
    pos[0] = pos[len];
    while(Q--){
        ll K = read < ll >();
        if(K <= cnt)printf("%lld\n", siz[pre[K]]);
        else printf("%lld\n", siz[pos[(K - cnt) % len]]);
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