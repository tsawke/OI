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



template<typename T = int>
inline T read(void);



int main(){
    int T = read();
    while(T--){
        ll N = read(), K = read(), s = read(), t = read();
        // K = min(K, N - K);
        ll k = min(K, N - K);
        if(s == t){printf("0\n"); continue;}
        if(K == N){
            printf("%d\n", s == N - t ? 1 : -1);
            continue;
        }
        // printf("New K = %lld\n", K);

        auto NxtRange = [=](ll curS)->pair < ll, ll >{
            return {curS + K - 2 * min(K, curS), curS + K - 2 * max(0ll, K - (N - curS))};
        };
        
        // if(!(K & 1) && (s & 1) != (t & 1)){
        //     printf("-1\n"); continue;
        // }
        auto [L, R] = NxtRange(s);
        // printf("One step, range [%lld, %lld]\n", L, R);
        // if(L <= t && t <= R && (K & 1) == ((t - s + (N << 1)) & 1)){
        //     printf("1\n"); continue;
        // }

        ll dis = std::abs(t - s);
        ll ans1 = (ll)ceil((double)dis / k / 2.0);
        ans1 <<= 1;

        if(((t - s + (N << 1)) & 1))ans1 = 0x3f3f3f3f;

        // ll L2 = max(0ll, s - K), R2 = min(N, s + K);
        // printf("One step, range [%lld, %lld]\n", L, R);


        ll v1 = (ll)ceil((double)(L - t) / k / 2.0);
        ll v2 = (ll)ceil((double)(t - R) / k / 2.0);
        ll ans2 = max({v1, v2, 0ll});
        ans2 = (ans2 << 1) | 1;

        if((K & 1) != ((t - s + (N << 1)) & 1))ans2 = 0x3f3f3f3f;

        // printf("ans1 = %lld, ans2 = %lld\n", ans1, ans2);

        ll ans = min(ans1, ans2);
        printf("%lld\n", ans == 0x3f3f3f3f ? -1ll : ans);



        // auto [L2, _] = NxtRange(L);
        // auto [__, R2] = NxtRange(R);
        // printf("Two steps, range [%lld, %lld]\n", L2, R2);
        // if(L2 <= t && t <= R2 && !((t - s + (N << 1)) & 1)){
        //     printf("2\n"); continue;
        // }
        // ll dis = std::abs(t - s);
        // ll ans = 
        // printf("%lld\n", ans);
    }

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template<typename T>
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