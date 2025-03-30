#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <bits/extc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define LIM (1100000)
#define sumX(p) (p < 0 ? 0 : sumX[p])
#define IN_REGULAR(x) (1 <= x && x <= N)

template<typename T = int>
inline T read(void);

int N, K, M, Q;
int costC[LIM], costX[LIM];
int dis1[LIM], disK[LIM];
int sumC[LIM], sumX[LIM];
int switchCost(0);

// basic_string < int > blockC, blockX;
__gnu_pbds::tree <
    int,
    __gnu_pbds::null_type,
    less < int >,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
> blockC, blockX;

auto CheckRegularRoute = [](int s, int t) -> bool{
    if(s > t)swap(s, t);
    auto pos = blockC.lower_bound(s);//(blockC.begin(), blockC.end(), s);
    return pos == blockC.end() || *pos >= t;
};
auto CheckReversedRegularRoute = [](int s, int t) -> bool{
    if(s > t)swap(s, t);
    auto pos = blockC.lower_bound(t);//lower_bound(blockC.begin(), blockC.end(), t);
    return pos == blockC.end() && (blockC.empty() || *blockC.begin() >= s);
};
auto CheckExtraRoute = [](int s, int t) -> bool{
    if(s > t)swap(s, t);
    auto pos = blockX.lower_bound(s);//lower_bound(blockX.begin(), blockX.end(), s);
    return pos == blockX.end() || *pos >= t;
};
auto CheckReversedExtraRoute = [](int s, int t) -> bool{
    if(s > t)swap(s, t);
    auto pos = blockX.lower_bound(t);//lower_bound(blockX.begin(), blockX.end(), t);
    return pos == blockX.end() && (blockX.empty() || *blockX.begin() >= s);
};

int main(){
    N = read(), K = read(), M = read(), Q = read();
    for(int i = 1; i <= N; ++i)costC[i] = read(), sumC[i] = sumC[i - 1] + costC[i];
    for(int i = 0; i <= M; ++i)costX[i] = read(), sumX[i] = (i == 0 ? 0 : sumX[i - 1]) + costX[i];
    switchCost = sumX[M];
    for(int i = 1; i <= N; ++i){
        int s = min(i, 1), t = max(i, 1);
        dis1[i] = min(sumC[t - 1] - sumC[s - 1], sumC[N] - sumC[t - 1] + sumC[s - 1] - 0);
        s = min(i, K), t = max(i, K);
        disK[i] = min(sumC[t - 1] - sumC[s - 1], sumC[N] - sumC[t - 1] + sumC[s - 1] - 0);
    }


    auto CalRoute = [](int s, int t) -> int{
        if(s > t)swap(s, t);
        return min(
            CheckRegularRoute(s, t) ? sumC[t - 1] - sumC[s - 1] : 0x3f3f3f3f,
            CheckReversedRegularRoute(s, t) ? sumC[N] - sumC[t - 1] + sumC[s - 1] - 0 : 0x3f3f3f3f
        );
    };

    while(Q--){
        char c = getchar();
        while(c != 'q' && c != 'x' && c != 'c')c = getchar();
        switch(c){
            case 'q':{
                int s = read(), t = read();
                auto dfs = [](auto&& self, int p, int sum) {
                    
                }
                if(s > t)swap(s, t);
                if(IN_REGULAR(s) && IN_REGULAR(t)){
                    int ans(0x3f3f3f3f);
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
                    if(ans == 0x3f3f3f3f)puts("impossible");
                    else printf("%d\n", ans);
                }else if(!IN_REGULAR(s) && !IN_REGULAR(t)){
                    s -= N, t -= N;
                    int ans(0x3f3f3f3f);
                    if(CheckExtraRoute(s, t))
                        ans = min(ans, sumX(t - 1) - sumX(s - 1));
                    if(CheckReversedExtraRoute(s, t))
                        ans = min(ans, sumX(s - 1) + sumX[M] - sumX(t - 1) + CalRoute(1, K));
                    if(ans == 0x3f3f3f3f)puts("impossible");
                    else printf("%d\n", ans);
                }else{
                    t -= N;
                    int ans(0x3f3f3f3f);
                    if((CheckRegularRoute(s, 1) || CheckReversedRegularRoute(s, 1)) && CheckExtraRoute(0, t))
                        ans = min(ans, CalRoute(s, 1) + sumX(t - 1));
                    if((CheckRegularRoute(s, K) || CheckReversedExtraRoute(s, K)) && CheckExtraRoute(t, K))
                        ans = min(ans, CalRoute(s, K) + sumX[M] - sumX(t - 1));
                    if(ans == 0x3f3f3f3f)puts("impossible");
                    else printf("%d\n", ans);
                }
                break;
            }
            case 'x':{
                int p = read();
                auto pos = blockX.lower_bound(p);//lower_bound(blockX.begin(), blockX.end(), p);
                if(pos != blockX.end() && *pos == p)blockX.erase(pos);
                else blockX.insert(p);
                break;
            }
            case 'c':{
                int p = read();
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
        ret += int(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}