#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
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

#define MXV (100010)

template < typename T = int >
inline T read(void);

int N, K;
ll ans(0);
ll A[510000];
unordered_map < int, ll > cnt;
ll dp[510000];

class SegTree{
private:
    ll tr[110000 << 2];
    int mn[110000 << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    SegTree(void){memset(mn, 0x3f, sizeof mn);}
    void Pushup(int p){
        tr[p] = tr[LS] + tr[RS];
        mn[p] = min(mn[LS], mn[RS]);
    }
    void Modify(int val, int id, int p = 1, int gl = 1, int gr = MXV){
        // undel.insert(p);
        if(gl == gr)return tr[p]++, mn[p] = min(mn[p], id), void();
        if(val <= MID)Modify(val, id, LS, gl, MID);
        else Modify(val, id, RS, MID + 1, gr);
        Pushup(p);
    }
    void Assign(int val, int p = 1, int gl = 1, int gr = MXV){
        tr[p] = 0, mn[p] = 0x3f3f3f3f;
        if(gl == gr)return;
        if(val <= MID)Assign(val, LS, gl, MID);
        else Assign(val, RS, MID + 1, gr);
    }
    int QueryMin(int l, int r, int p = 1, int gl = 1, int gr = MXV){
        if(l <= gl && gr <= r)return mn[p];
        if(r < gl || gr < l)return 0x3f3f3f3f;
        return min(QueryMin(l, r, LS, gl, MID), QueryMin(l, r, RS, MID + 1, gr));
    }
    ll QueryCnt(int l, int r, int p = 1, int gl = 1, int gr = MXV){
        if(l <= gl && gr <= r)return tr[p];
        if(r < gl || gr < l)return 0;
        return QueryCnt(l, r, LS, gl, MID) + QueryCnt(l, r, RS, MID + 1, gr);
    }
}st;

ll Make(void){
    for(int i = 0; i <= N; ++i)dp[i] = 0;
    ll ret(0);
    for(int i = N; i >= 1; --i){
        int p = st.QueryMin(A[i] + 1, A[i] + K);
        dp[i] = p == 0x3f3f3f3f ? 0 : dp[p] + st.QueryCnt(A[i] + 1, A[p]);
        st.Modify(A[i], i);
        ret += dp[i];
    }
    for(int i = 1; i <= N; ++i)st.Assign(A[i]);
    return ret;
}

int main(){
    int T = read();
    while(T--){
        ans = 0;
        N = read(), K = read();
        for(int i = 1; i <= N; ++i)cnt[A[i] = read()]++;
        for(auto v : cnt)ans += ((v.second) * (v.second + 1)) >> 1;
        cnt.clear();
        ans += Make(), reverse(A + 1, A + N + 1), ans += Make();
        printf("%lld\n", ans);
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