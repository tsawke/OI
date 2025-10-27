#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

template < typename T = int >
inline T read(void);

// class BIT{
// private:
//     int tr[110000];
// public:
//     void Clear(int){memset(tr, 0, sizeof tr);}
//     int lowbit(int x){return x & -x;}
//     void Modify(int x, int v){
//         while(x <= N)tr[x] = max(tr[x], v), x += lowbit(x);
//     }
//     int Query(int x){int ret(0); while(x)ret = max(ret, tr[x]), x -= lowbit(x); return ret;}
// }bit;

int N; ll M;

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
    void Build(const vector < int > &A, int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return tr[p] = A[gl = gr], void();
        Build(A, LS, gl, MID), Build(A, RS, MID + 1, gr);
        Pushup(p);
    }
    int Query(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return tr[p];
        if(gr < l || r < gl)return -1;
        return max(Query(l, r, LS, gl, MID), Query(l, r, RS, MID + 1, gr));
    }
}st;

int main(){
    N = read(); M = read < ll >();
    vector < int > F(N + 10, 0), S(N + 10, 0);
    for(int i = 1; i <= N; ++i)F[i] = read(), S[i] = read();
    st.Build(S);
    vector < ll > sumF(N + 10, 0);
    for(int i = 1; i <= N; ++i)sumF[i] = sumF[i - 1] + F[i];
    auto Check = [](ll sum)->bool{return sum >= M;};
    int res(INT_MAX);
    for(int beg = 1; beg <= N; ++beg){
        int l = beg, r = N, ans = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(Check(sumF[mid] - sumF[beg - 1]))ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        if(ans != -1)res = min(res, st.Query(beg, ans));
    }
    printf("%d\n", res);
    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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