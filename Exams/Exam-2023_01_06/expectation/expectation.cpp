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
int a[110000];
int l[5100], r[5100];
ld p[5100];
ld expect(0.0);

class SegTree{
private:
    int tr[110000 << 2];
    int lz[110000 << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Pushup(int p){
        tr[p] = max(tr[LS], tr[RS]);
    }
    void Pushdown(int p){
        if(!lz[p])return;
        lz[LS] += lz[p], lz[RS] += lz[p];
        tr[LS] += lz[p], tr[RS] += lz[p];
        lz[p] = 0;
    }
    void Build(int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return tr[p] = a[gl = gr], void();
        Build(LS, gl, MID), Build(RS, MID + 1, gr);
        Pushup(p);
    }
    void Modify(int l, int r, int v = 1, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return tr[p] += v, lz[p] += v, void();
        Pushdown(p);
        if(l <= MID)Modify(l, r, v, LS, gl, MID);
        if(MID + 1 <= r)Modify(l, r, v, RS, MID + 1, gr);
        Pushup(p);
    }
    int Query(void){
        return tr[1];
    }
}st;

void dfs(int dep = 1, ld cur = 1.0){
    if(dep > Q){
        expect += cur * (ld)st.Query();
        return;
    }
    st.Modify(l[dep], r[dep]);
    dfs(dep + 1, cur * p[dep]);
    st.Modify(l[dep], r[dep], -1);
    dfs(dep + 1, cur * (1.0 - p[dep]));
}

int main(){
    freopen("expectation.in", "r", stdin);
    freopen("expectation.out", "w", stdout);
    N = read(), Q = read();
    for(int i = 1; i <= N; ++i)a[i] = read();
    st.Build();
    for(int i = 1; i <= Q; ++i)l[i] = read(), r[i] = read(), scanf("%Lf", &p[i]);
    dfs();
    printf("%.9Lf\n", expect);
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

/*
5 2
1 7 2 4 3
1 3 0.500
2 2 0.500

5 2
281 280 279 278 282
1 4 1.000
1 4 0.000

3 5
1 2 3
1 3 0.500
2 2 0.250
1 2 0.800
1 1 0.120
2 2 0.900
*/