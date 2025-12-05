#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <bits/extc++.h>

#define PI M_PI
#define E M_E


// #define ll ll



using namespace std;

// mt19937 rnd(random_device{}());
// ll rndd(ll l, ll r){return rnd() % (r - l + 1) + l;}

// typedef unsigned ll ull;
typedef unsigned long long unll;
typedef long long ll;

#define LIM (1100000)
#define sumX(p) (p < 0 ? 0 : sumX[p])
#define IN_REGULAR(x) (1 <= x && x <= N)

template<typename T = ll>
inline T read(void);

ll N, K, M, Q;
ll costC[LIM], costX[LIM];
ll dis1[LIM], disK[LIM];
ll sumC[LIM], sumX[LIM];
ll switchCost(0);

// basic_string < ll > blockC, blockX;
__gnu_pbds::tree <
    ll,
    __gnu_pbds::null_type,
    less < ll >,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
> blockC, blockX;

auto CheckRegularRoute = [](ll s, ll t) -> bool{
    if(s > t)swap(s, t);
    auto pos = blockC.lower_bound(s);//(blockC.begin(), blockC.end(), s);
    return pos == blockC.end() || *pos >= t;
};
auto CheckReversedRegularRoute = [](ll s, ll t) -> bool{
    if(s > t)swap(s, t);
    auto pos = blockC.lower_bound(t);//lower_bound(blockC.begin(), blockC.end(), t);
    return pos == blockC.end() && (blockC.empty() || *blockC.begin() >= s);
};
auto CheckExtraRoute = [](ll s, ll t) -> bool{
    if(s > t)swap(s, t);
    auto pos = blockX.lower_bound(s);//lower_bound(blockX.begin(), blockX.end(), s);
    return pos == blockX.end() || *pos >= t;
};
auto CheckReversedExtraRoute = [](ll s, ll t) -> bool{
    if(s > t)swap(s, t);
    auto pos = blockX.lower_bound(t);//lower_bound(blockX.begin(), blockX.end(), t);
    return pos == blockX.end() && (blockX.empty() || *blockX.begin() >= s);
};

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    N = read(), K = read(), M = read(), Q = read();
    for(ll i = 1; i <= N; ++i)costC[i] = read(), sumC[i] = sumC[i - 1] + costC[i];
    for(ll i = 0; i <= M; ++i)costX[i] = read(), sumX[i] = (i == 0 ? 0 : sumX[i - 1]) + costX[i];
    switchCost = sumX[M];
    // for(ll i = 1; i <= N; ++i){
    //     ll s = min(i, 1), t = max(i, 1);
    //     dis1[i] = min(sumC[t - 1] - sumC[s - 1], sumC[N] - sumC[t - 1] + sumC[s - 1] - 0);
    //     s = min(i, K), t = max(i, K);
    //     disK[i] = min(sumC[t - 1] - sumC[s - 1], sumC[N] - sumC[t - 1] + sumC[s - 1] - 0);
    // }


    auto CalRoute = [](ll s, ll t) -> ll{
        if(s > t)swap(s, t);
        if(s < 0 || t < 0){while(true);}
        return min(
            CheckRegularRoute(s, t) ? sumC[t - 1] - sumC[s - 1] : (ll)(1e16),
            CheckReversedRegularRoute(s, t) ? sumC[N] - sumC[t - 1] + sumC[s - 1] - 0 : (ll)(1e16)
        );
    };

    while(Q--){
        char c = getchar();
        while(c != 'q' && c != 'x' && c != 'c')c = getchar();
        switch(c){
            case 'q':{
                ll s = read(), t = read();
                if(s > t)swap(s, t);
                if(IN_REGULAR(s) && IN_REGULAR(t)){
                    ll ans((ll)(1e16));
                    // auto pos = lower_bound(blockC.begin(), blockC.end(), s);
                    // if(pos == blockC.end() || *pos >= t)
                    if(CheckRegularRoute(s, t))
                        ans = min(ans, sumC[t - 1] - sumC[s - 1]);
                    // else puts("Regular is blocked.");
                    // auto pos = lower_bound(blockC.begin(), blockC.end(), t);
                    // if(pos == blockC.end() && (blockC.empty() || *blockC.begin() >= s))
                    if(CheckReversedRegularRoute(s, t))
                        ans = min(ans, sumC[N] - sumC[t - 1] + sumC[s - 1] - 0);
                    // else puts("Reverse is blocked.");
                    if(blockX.empty()){ //X is available
                        if((CheckRegularRoute(1, s) || CheckReversedRegularRoute(1, s)) && (CheckRegularRoute(K, t) || CheckReversedRegularRoute(K, t)))
                            ans = min(ans, CalRoute(1, s) + switchCost + CalRoute(K, t));
                        if((CheckRegularRoute(K, s) || CheckReversedRegularRoute(K, s)) && (CheckRegularRoute(1, t) || CheckReversedRegularRoute(1, t)))
                            ans = min(ans, CalRoute(K, s) + switchCost + CalRoute(1, t));
                        // ans = min()
                    }
                    if(ans == (ll)(1e16))puts("impossible");
                    else printf("%lld\n", ans);
                }else if(!IN_REGULAR(s) && !IN_REGULAR(t)){
                    s -= N, t -= N;
                    ll ans((ll)(1e16));
                    if(CheckExtraRoute(s, t))
                        ans = min(ans, sumX(t - 1) - sumX(s - 1));
                    if(CheckReversedExtraRoute(s, t))
                        ans = min(ans, sumX(s - 1) + sumX[M] - sumX(t - 1) + CalRoute(1, K));
                    if(ans == (ll)(1e16))puts("impossible");
                    else printf("%lld\n", ans);
                }else{
                    t -= N;
                    ll ans((ll)(1e16));
                    if((CheckRegularRoute(s, 1) || CheckReversedRegularRoute(s, 1)) && CheckExtraRoute(0, t))
                        ans = min(ans, CalRoute(s, 1) + sumX(t - 1));
                    // else puts("Case 1 fail.");
                    if((CheckRegularRoute(s, K) || CheckReversedRegularRoute(s, K)) && CheckExtraRoute(t, M + 1))
                        ans = min(ans, CalRoute(s, K) + sumX[M] - sumX(t - 1));
                    // else puts("Case 2 fail.");
                    if(ans == (ll)(1e16))puts("impossible");
                    else printf("%lld\n", ans);
                }
                break;
            }
            case 'x':{
                ll p = read() - N;
                auto pos = blockX.lower_bound(p);//lower_bound(blockX.begin(), blockX.end(), p);
                if(pos != blockX.end() && *pos == p)blockX.erase(pos);
                else blockX.insert(p);
                break;
            }
            case 'c':{
                ll p = read();
                auto pos = blockC.lower_bound(p);//lower_bound(blockC.begin(), blockC.end(), p);
                if(pos != blockC.end() && *pos == p)blockC.erase(pos);
                else blockC.insert(p);
                break;
            }
        }
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
        ret += ll(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}