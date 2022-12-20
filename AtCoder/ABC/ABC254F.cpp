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

template < typename T = int >
inline T read(void);

int N, Q;
int A[MAXN], B[MAXN], dA[MAXN], dB[MAXN];

class SegTree{
private:
    int tr[MAXN << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Pushup(int p){tr[p] = __gcd(tr[LS], tr[RS]);}
    void Build(bool flag, int p = 1, int gl = 1, int gr = N){//true - line(y), false - row(x)
        if(gl == gr)return tr[p] = flag ? dB[gl] : dA[gl], void();
        Build(flag, LS, gl, MID), Build(flag, RS, MID + 1, gr);
        Pushup(p);
    }
    int Query(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return tr[p];
        if(r <= MID)return Query(l, r, LS, gl, MID);
        if(l >= MID + 1)return Query(l, r, RS, MID + 1, gr);
        return __gcd(Query(l, r, LS, gl, MID), Query(l, r, RS, MID + 1, gr));
    }
}stLine, stRow;

int main(){
    N = read(), Q = read();
    for(int i = 1; i <= N; ++i)A[i] = read(), dA[i] = A[i] - A[i - 1];
    for(int i = 1; i <= N; ++i)B[i] = read(), dB[i] = B[i] - B[i - 1];
    stLine.Build(true), stRow.Build(false);
    while(Q--){
        int h1 = read(), h2 = read(), w1 = read(), w2 = read();
        int ans = A[h1] + B[w1];
        if(w1 != w2)ans = __gcd(ans, stLine.Query(w1 + 1, w2));
        if(h1 != h2)ans = __gcd(ans, stRow.Query(h1 + 1, h2));
        printf("%d\n", abs(ans));
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