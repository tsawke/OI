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

#define MAXN (150000)

template< typename T = int >
inline T read(void);

int N, K;
int val[MAXN];

struct MyPair{
    int first, second;
    friend const bool operator < (const MyPair &a, const MyPair &b){
        return a.first == b.first ? a.second < b.second : a.first < b.first;
    }
};

struct Node{
    basic_string < MyPair/*val, cnt*/ > vals;
    int lz;
    Node operator = (const Node &b){
        this->vals = b.vals;
        this->lz = b.lz;
        return *this;
    }
    friend const Node operator + (const Node &a, const Node &b){
        Node ret{a.vals + b.vals, 0};
        sort(ret.vals.begin(), ret.vals.end());
        for(auto it = ret.vals.begin(); next(it) != ret.vals.end();)
            if(it->first == next(it)->first)next(it)->second += it->second, it = ret.vals.erase(it);
            else advance(it, 1);
        return ret;
    }
    friend Node operator += (Node &a, const int &val){
        for(auto &nod : a.vals)nod.first += val;
        a.lz += val;
        return a;
    }
};
class SegTree{
private:
    Node tr[MAXN << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Pushup(int p){tr[p] = tr[LS] + tr[RS];}
    void Pushdown(int p){
        if(!tr[p].lz)return;
        tr[LS].lz = tr[RS].lz = tr[p].lz;
        tr[LS] += tr[p].lz, tr[RS] += tr[p].lz;
        tr[p].lz = 0;
    }
    void Build(int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return tr[p].vals += {gl = gr, 1}, void();
        Build(LS, gl, MID), Build(RS, MID + 1, gr);
        Pushup(p);
    }
    void Modify(int l, int r, int val, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return tr[p] += val, void();
        Pushdown(p);
        if(l <= MID)Modify(l, r, val, LS, gl, MID);
        if(r >= MID + 1)Modify(l, r, val, RS, MID + 1, gr);
        Pushup(p);
    }
    Node Query(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return tr[p];
        Pushdown(p);
        if(l > MID)return Query(l, r, RS, MID + 1, gr);
        if(r < MID + 1)return Query(l, r, LS, gl, MID);
        return Query(l, r, LS, gl, MID) + Query(l, r, RS, MID + 1, gr);
    }
}st;
ll Cal(int R){
    ll ret(0);
    auto vals = st.Query(1, R).vals;
    //r + k >= l + max - min
    for(auto nod : vals)if(R + K >= nod.first)ret += nod.second;
    return ret;
}

int mx[MAXN]/*Query Min*/, mn[MAXN]/*Query Max*/;
int mxp(0), mnp(0);

int main(){
    N = read(), K = read();
    for(int i = 1; i <= N; ++i)val[i] = read();
    st.Build();
    ll ans(0);
    for(int R = 1; R <= N; ++R){
        while(mxp && val[R] > val[mx[mxp]])st.Modify(mx[mxp - 1] + 1, mx[mxp], val[R] - val[mx[mxp]]), --mxp;
        while(mnp && val[R] < val[mn[mnp]])st.Modify(mn[mnp - 1] + 1, mn[mnp], val[mn[mnp]] - val[R]), --mnp;
        mx[++mxp] = mn[++mnp] = R;
        ans += Cal(R);
        // printf("R = %d, Cal = %lld\n", R, Cal(R));
    }printf("%lld\n", ans);
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