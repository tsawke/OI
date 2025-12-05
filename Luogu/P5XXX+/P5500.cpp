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

#define MAXN (210000)

template< typename T = int >
inline T read(void);

int N, M;
int a[MAXN];

struct Node{
    int mx;
    int mxl, mxr;
    int corl, corr;
    int siz;
    friend const Node operator + (const Node &l, const Node &r){
        Node ret;
        ret.mx = max({l.mx, r.mx, l.corr == r.corl ? l.mxr + r.mxl : 0});
        ret.mxl = max({l.mxl, l.mxl == l.siz && l.corr == r.corl ? l.mxl + r.mxl : 0});
        ret.mxr = max({r.mxr, r.mxr == r.siz && r.corl == l.corr ? r.mxr + l.mxr : 0});
        ret.corl = l.corl, ret.corr = r.corr;
        ret.siz = l.siz + r.siz;
        return ret;
    }
};

class SegTree{
private:
    Node tr[MAXN << 2];
    int lz[MAXN << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
    #define SIZ(l, r) (r - l + 1)
public:
    void Pushup(int p, int gl, int gr){tr[p] = tr[LS] + tr[RS];}
    void Pushdown(int p){
        tr[LS].mx = tr[LS].mxl = tr[LS].mxr = tr[LS].siz;
        tr[RS].mx = tr[RS].mxl = tr[RS].mxr = tr[RS].siz;
        tr[LS].corl = tr[LS].corr = lz[p];
        tr[RS].corl = tr[RS].corr = lz[p];
        lz[LS] = lz[RS] = lz[p];
        lz[p] = false;
    }
    void Build(int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return tr[p].mx = tr[p].mxl = tr[p].mxr = tr[p].siz = 1, tr[p].corl = tr[p].corr = a[gl = gr], void();
        Build(LS, gl, MID), Build(RS, MID + 1, gr);
        Pushup(p, gl, gr);
    }
    void Assign(int l, int r, int v, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r){
            tr[p].mx = tr[p].mxl = tr[p].mxr = tr[p].siz;
            tr[p].corl = tr[p].corr = v;
            lz[p] = v;
            return;
        }
        if(lz[p])Pushdown(p);
        if(l <= MID)Assign(l, r, v, LS, gl, MID);
        if(MID + 1 <= r)Assign(l, r, v, RS, MID + 1, gr);
        Pushup(p, gl, gr);
    }
    Node Query(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return tr[p];
        if(lz[p])Pushdown(p);
        return
            l <= MID && r >= MID + 1
                ? Query(l, r, LS, gl, MID) + Query(l, r, RS, MID + 1, gr)
                :(
                    l <= MID
                        ? Query(l, r, LS, gl, MID)
                        : Query(l, r, RS, MID + 1, gr)
                );
    }
}st;

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)a[i] = read();
    st.Build();
    while(M--){
        char c = getchar(); while(c != 'Q' && c != 'R')c = getchar();
        if(c == 'R'){
            int l = read(), r = read(), v = read();
            st.Assign(l, r, v);
        }else{
            int l = read(), r = read(), k = read();
            auto ans = st.Query(l, r);
            printf("%d\n", k && ans.corl == ans.corr ? max(min(ans.siz, ans.mxl + ans.mxr), ans.mx) : ans.mx);
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