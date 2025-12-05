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

int N, Q;
int A[110000];
struct RetNode{
    ll cnt;
    ll siz0, siz1, siz2;
};

class SegTree{
private:
    ll cnt[110000 << 2][3][3], siz[110000 << 2][3];
    ll lz[110000 << 2][3];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    SegTree(void){for(int i = 0; i <= 101000 << 2; ++i)for(int j = 0; j <= 2; ++j)lz[i][j] = j;}
    void Pushup(int p){
        for(int i = 0; i <= 2; ++i)siz[p][i] = siz[LS][i] + siz[RS][i];
        for(int i = 0; i <= 2; ++i)for(int j = 0; j <= 2; ++j)
            cnt[p][i][j] = cnt[LS][i][j] + cnt[RS][i][j] + siz[LS][i] * siz[RS][j];
    }
    void Pushdown(int p){
        if(lz[p][0] == 0 && lz[p][1] == 1 && lz[p][2] == 2)return;
        for(int i = 0; i <= 2; ++i)lz[LS][i] = lz[p][lz[LS][i]];
        for(int i = 0; i <= 2; ++i)lz[RS][i] = lz[p][lz[RS][i]];
        ll tsiz[3]; memset(tsiz, 0, sizeof tsiz);
        ll tcnt[3][3]; memset(tcnt, 0, sizeof tcnt);
        for(int i = 0; i <= 2; ++i)tsiz[lz[p][i]] += siz[LS][i];
        for(int i = 0; i <= 2; ++i)for(int j = 0; j <= 2; ++j)
            tcnt[lz[p][i]][lz[p][j]] += cnt[LS][i][j];
        for(int i = 0; i <= 2; ++i)siz[LS][i] = tsiz[i];
        for(int i = 0; i <= 2; ++i)for(int j = 0; j <= 2; ++j)cnt[LS][i][j] = tcnt[i][j];
        memset(tsiz, 0, sizeof tsiz), memset(tcnt, 0, sizeof tcnt);
        for(int i = 0; i <= 2; ++i)tsiz[lz[p][i]] += siz[RS][i];
        for(int i = 0; i <= 2; ++i)for(int j = 0; j <= 2; ++j)
            tcnt[lz[p][i]][lz[p][j]] += cnt[RS][i][j];
        for(int i = 0; i <= 2; ++i)siz[RS][i] = tsiz[i];
        for(int i = 0; i <= 2; ++i)for(int j = 0; j <= 2; ++j)cnt[RS][i][j] = tcnt[i][j];
        for(int i = 0; i <= 2; ++i)lz[p][i] = i;
    }
    void Build(int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return siz[p][A[gl = gr]] = 1, void();
        Build(LS, gl, MID), Build(RS, MID + 1, gr);
        Pushup(p);
    }
    RetNode Query(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)
            return RetNode{cnt[p][2][0] + cnt[p][2][1] + cnt[p][1][0], siz[p][0], siz[p][1], siz[p][2]};
        if(gr < l || r < gl)return RetNode{0, 0, 0, 0};
        Pushdown(p);
        auto Lret = Query(l, r, LS, gl, MID), Rret = Query(l, r, RS, MID + 1, gr);
        return RetNode{
            Lret.cnt + Rret.cnt + Lret.siz2 * Rret.siz0 + Lret.siz2 * Rret.siz1 + Lret.siz1 * Rret.siz0,
            Lret.siz0 + Rret.siz0,
            Lret.siz1 + Rret.siz1,
            Lret.siz2 + Rret.siz2
        };
    }
    void Modify(int l, int r, int S, int T, int U, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r){
            ll tsiz[3]; memset(tsiz, 0, sizeof tsiz);
            ll tcnt[3][3]; memset(tcnt, 0, sizeof tcnt);
            int ctlz[3] = {S, T, U};
            for(int i = 0; i <= 2; ++i)lz[p][i] = ctlz[lz[p][i]];
            for(int i = 0; i <= 2; ++i)tsiz[ctlz[i]] += siz[p][i];
            for(int i = 0; i <= 2; ++i)for(int j = 0; j <= 2; ++j)
                tcnt[ctlz[i]][ctlz[j]] += cnt[p][i][j];
            for(int i = 0; i <= 2; ++i)siz[p][i] = tsiz[i];
            for(int i = 0; i <= 2; ++i)for(int j = 0; j <= 2; ++j)cnt[p][i][j] = tcnt[i][j];
            return;
        }Pushdown(p);
        if(l <= MID)Modify(l, r, S, T, U, LS, gl, MID);
        if(MID + 1 <= r)Modify(l, r, S, T, U, RS, MID + 1, gr);
        Pushup(p);
    }
}st;

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    N = read(), Q = read();
    for(int i = 1; i <= N; ++i)A[i] = read();
    st.Build();
    while(Q--){
        int opt = read();
        if(opt == 1){
            int l = read(), r = read();
            printf("%lld\n", st.Query(l, r).cnt);
        }else{
            int l = read(), r = read(), S = read(), T = read(), U = read();
            st.Modify(l, r, S, T, U);
        }
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