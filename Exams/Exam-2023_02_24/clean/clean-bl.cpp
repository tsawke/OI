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

int N, P;
int w[110000];
int sum[110000];
int rsum[110000];
int ans[110000];
int mx(-1), rmx(-1);
basic_string < int > vals;

class SegTree{
private:
    int tr[65536 << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Pushup(int p){
        tr[p] = tr[LS] + tr[RS];
    }
    void Modify(int val, int cnt = 1, int p = 1, int gl = 0, int gr = P - 1){
        // printf("In mdf val = %d, gl = %d, gr = %d\n", val, gl, gr);
        // for(int i = 1; i <= 50000000; ++i);
        if(gl == gr)return tr[p] += cnt, void();
        if(val <= MID)Modify(val, cnt, LS, gl, MID);
        else Modify(val, cnt, RS, MID + 1, gr);
        Pushup(p);
    }
    int QueryRight(int p, int gl, int gr){
        if(gl == gr)return tr[p] ? gl = gr : -1;
        if(tr[RS])return QueryRight(RS, MID + 1, gr);
        return QueryRight(LS, gl, MID);
    }
    int QueryLeftMost(int val, int p = 1, int gl = 0, int gr = P - 1){
        if(gl == gr)return gl <= val && tr[p] ? gl : -1;
        int mx(-1);
        if(MID <= val)mx = max(mx, QueryRight(LS, gl, MID));
        else return QueryLeftMost(val, LS, gl, MID);
        return max(mx, QueryLeftMost(val, RS, MID + 1, gr));
    }
}st1, st2;

int main(){
    // freopen("clean.in", "r", stdin);
    // freopen("clean.out", "w", stdout);
    N = read(), P = read();
    for(int i = 1; i <= N; ++i)
        w[i] = read(),
        sum[i] = (sum[i - 1] + w[i]) % P,
        st1.Modify(sum[i]),
        mx = max(mx, sum[i]);
    for(int i = N; i >= 1; --i)
        rsum[i] = (rsum[i + 1] + w[i]) % P,
        st2.Modify(rsum[i]),
        rmx = max(rmx, rsum[i]);

    for(int i = 1; i <= N; ++i){
        int ans(-1);
        int cur(0);
        for(int j = i; j <= N; ++j)ans = max(ans, (cur += w[j]) %= P);
        cur = 0;
        for(int j = i; j >= 1; --j)ans = max(ans, (cur += w[j]) %= P);
        printf("%d%c", ans, i == N ? '\n' : ' ');
    }
    // sort(sum + 1, sum + N + 1);
    // for(int i = 1; i <= N; ++i)vals += sum[i];
    // sort(vals.begin(), vals.end());
    // for(int i = 1, j = N; i <= N; ++i, --j){
        
    //     // auto it = lower_bound(vals.begin(), vals.end(), val);
    //     // int ans(-1);
    //     // if(it != vals.end())ans = max((ll)ans, (*it - sum[i] + P) % P);
    //     // if(it != vals.end() && next(it) != vals.end())ans = max((ll)ans, (*next(it) - sum[i] + P) % P);
    //     // if(it != vals.begin())ans = max((ll)ans, (*prev(it) - sum[i] + P) % P);
    //     int val = (P - 1 + sum[i - 1]) % P;
    //     int ret = st1.QueryLeftMost(val);
    //     // printf("QLM1 val = %d, ret = %d, sum is %lld\n", val, ret, sum[i - 1]);
    //     if(!~ret)ret = mx;
    //     ans[i] = max((ll)ans[i], (ret - sum[i - 1] + P) % P);
    //     st1.Modify(sum[i], -1);
    //     val = (P - 1 + rsum[j + 1]) % P;
    //     ret = st2.QueryLeftMost(val);
    //     // printf("QLM2 val = %d, ret = %d\n", val, ret);
    //     if(!~ret)ret = rmx;
    //     ans[j] = max((ll)ans[j], (ret - rsum[j + 1] + P) % P);
    //     st2.Modify(rsum[j], -1);
    // }
    // for(int i = 1; i <= N; ++i)printf("%d%c", ans[i], i == N ? '\n' : ' ');
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

/*
4 16
2 7 9 11
*/

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