#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

using ll = long long;
using unll = unsigned long long;
using uint = unsigned int;
using ld = long double;

template < typename T = int >
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

int main(){
    int N = read();
    vector < ll > A((N << 1) + 10, 0);
    for(int i = 1; i <= N; ++i)A[i] = A[i + N] = read();

    vector < ll > pre((N << 1) + 10, 0);
    for(int i = 1; i <= N << 1; ++i)pre[i] = pre[i - 1] + A[i];

    const ll INF = LONG_LONG_MAX >> 2;

    vector < vector < ll > > dpMn(410, vector < ll >(410)), dpMx(410, vector < ll >(410));

    for(int len = 2; len <= N; ++len){
        for(int i = 1; i + len - 1 <= N << 1; ++i){
            int j = i + len - 1;
            dpMn[i][j] = INF;
            dpMx[i][j] = 0;
            ll w(pre[j] - pre[i - 1]);
            for(int k = i; k < j; ++k)
                dpMn[i][j] = min(dpMn[i][k] + dpMn[k + 1][j] + w, dpMn[i][j]),
                dpMx[i][j] = max(dpMx[i][k] + dpMx[k + 1][j] + w, dpMx[i][j]);
        }
    }

    ll ansMn(INF), ansMx(0);
    for(int i = 1; i <= N; ++i)
        ansMn = min(ansMn, dpMn[i][i + N - 1]),
        ansMx = max(ansMx, dpMx[i][i + N - 1]);

    printf("%lld\n%lld\n", ansMn, ansMx);

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
