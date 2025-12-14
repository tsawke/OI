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
    int T = read();

    while(T--){
        int N = read();
        ll K = read < ll >();

        vector < int > C(N + 1), W(N + 1), F(N + 1);
        int mxFloor(0);
        for(int i = 1; i <= N; ++i){
            C[i] = read(), W[i] = read(), F[i] = read();
            mxFloor = max(mxFloor, F[i]);
        }

        vector < ll > cnt1(mxFloor + 1, 0), cnt2(mxFloor + 1, 0);
        for(int i = 1; i <= N; ++i){
            if(W[i] == 1)cnt1[F[i]] += (ll)C[i];
            else cnt2[F[i]] += (ll)C[i];
        }

        auto CalcRides = [&](ll X, ll Y)->ll{
            if(X == 0 && Y == 0)return 0;
            ll halfK = K >> 1, pairs = X >> 1;
            ll A = Y + pairs;
            if(A == 0)return (X & 1) ? 1 : 0;
            ll bins = (A + halfK - 1) / halfK;
            if((X & 1) && A % halfK == 0)++bins;
            return bins;
        };

        ll tot1(0), tot2(0);
        ll ans(0);

        for(int f = mxFloor; f >= 1; --f){
            tot1 += cnt1[f], tot2 += cnt2[f];
            ll rides = CalcRides(tot1, tot2);
            ans += rides;
        }

        printf("%lld\n", ans);
    }

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
