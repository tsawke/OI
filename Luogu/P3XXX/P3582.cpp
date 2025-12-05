#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

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

int N, M;
int A[1100000];
int llst[1100000];
int lst[1100000];
ll w[1100000];
ll ans(0);

class SegTree{
private:
    ll mx[1100000 << 2], lz[1100000 << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Pushup(int p){
        mx[p] = max(mx[LS], mx[RS]);
    }
    void Pushdown(int p){
        if(!lz[p])return;
        lz[LS] += lz[p], lz[RS] += lz[p];
        mx[LS] += lz[p], mx[RS] += lz[p];
        lz[p] = 0;
    }
    void Modify(int l, int r, int val, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return mx[p] += val, lz[p] += val, void();
        Pushdown(p);
        if(l <= MID)Modify(l, r, val, LS, gl, MID);
        if(r >= MID + 1)Modify(l, r, val, RS, MID + 1, gr);
        Pushup(p);
    }
    ll QueryMax(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return mx[p];
        if(l > gr || gl > r)return 0;
        Pushdown(p);
        return max(QueryMax(l, r, LS, gl, MID), QueryMax(l, r, RS, MID + 1, gr));
    }
}st;

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)A[i] = read();
    for(int i = 1; i <= M; ++i)w[i] = read();
    for(int i = 1; i <= N; ++i){
        if(llst[A[i]])st.Modify(1, llst[A[i]], w[A[i]]);
        if(lst[A[i]])st.Modify(1, lst[A[i]], -2 * w[A[i]]);
        st.Modify(1, i, w[A[i]]);
        llst[A[i]] = lst[A[i]], lst[A[i]] = i;
        ans = max(ans, st.QueryMax(1, i));
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