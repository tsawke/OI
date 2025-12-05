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

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[11000];
ROPNEW(ed);
Edge* head[5100];

int N, Q;
int A[110000];
struct Mdf{
    int L, R;
    double P;
    int mx;
}mdf[5100];
double dp[5100][5100];
double ans(0.0);

class SegTree{
private:
    int tr[110000 << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Pushup(int p){
        tr[p] = max(tr[LS], tr[RS]);
    }
    void Build(int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return tr[p] = A[gl = gr], void();
        Build(LS, gl, MID), Build(RS, MID + 1, gr);
        Pushup(p);
    }
    int Query(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return tr[p];
        if(gr < l || r < gl)return -1;
        return max(Query(l, r, LS, gl, MID), Query(l, r, RS, MID + 1, gr));
    }
}st;

void TreeDP(int p = 1, int fa = 0){
    for(auto i = head[p]; i; i = i->nxt)if(SON != fa)TreeDP(SON, p);
    for(int j = 0; j <= Q; ++j){
        double D1 = mdf[p].P, D2 = (1.0 - mdf[p].P);
        for(auto i = head[p]; i; i = i->nxt){
            if(SON == fa)continue;
                if(j + mdf[p].mx - mdf[SON].mx - 1 >= 0)D1 *= dp[SON][min(Q, j + mdf[p].mx - mdf[SON].mx - 1)];
                if(j + mdf[p].mx - mdf[SON].mx >= 0)D2 *= dp[SON][min(Q, j + mdf[p].mx - mdf[SON].mx)];
        }dp[p][j] = j ? D1 + D2 : D2;
    }
}

int main(){
    N = read(), Q = read();
    for(int i = 1; i <= N; ++i)A[i] = read();
    st.Build();
    for(int i = 1; i <= Q; ++i)mdf[i].L = read(), mdf[i].R = read(), scanf("%lf", &mdf[i].P), mdf[i].mx = st.Query(mdf[i].L, mdf[i].R);
    mdf[++Q] = {1, N, 0.0, st.Query(1, N)};
    sort(mdf + 1, mdf + Q + 1, [](const Mdf &a, const Mdf &b)->bool{return a.L == b.L ? a.R > b.R : a.L < b.L;});
    for(int i = 1; i <= Q; ++i)
        for(int j = i - 1; j; --j)
            if(mdf[j].L <= mdf[i].L && mdf[i].R <= mdf[j].R){
                head[i] = new Edge{head[i], j}, head[j] = new Edge{head[j], i};
                break;
            }
    TreeDP();
    for(int i = 0; i <= Q; ++i)ans += (dp[1][i] - (i ? dp[1][i - 1] : 0.0)) * (double)(mdf[1].mx + i);
    printf("%.6lf\n", ans);
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