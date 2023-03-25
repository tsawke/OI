#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <unordered_map>
#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to

#define MOD (1000000007ll)

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = ll>
inline T read(void);

map < pair < int, int >, ll > add;

int N, M;
ll a[210000];
ll sum[210000];
int main(){
    freopen("T3.in", "r", stdin);
    freopen("T3.out", "w", stdout);
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)a[i] = read() % MOD, sum[i] = (sum[i - 1] + a[i]) % MOD;

    while(M--){
        int opt = read();
        if(opt == 1){
            int x = read(), y = read(), val = read() % MOD;
            auto tmp = add.find(make_pair(x, y));
            if(tmp == add.end())add.insert(make_pair(make_pair(x, y), val));
            else tmp->second = (tmp->second + val) % MOD;
        }else{
            int l = read(), r = read();
            ll ans = (sum[r] - sum[l - 1] + MOD) % MOD;
            for(auto i : add){
                int tl = l - i.first.second, tr = r - i.first.second;
                if(tr < 0)continue;
                int by = max(tl / i.first.first, 0);
                tl -= by * i.first.first;
                tr -= by * i.first.first;
                if(tl <= 0)ans = (ans + i.second) % MOD;
                ans = (ans + int(tr / i.first.first) * i.second % MOD) % MOD;
            }
            printf("%lld\n", ans % MOD);
        }
    }

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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