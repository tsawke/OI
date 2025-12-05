#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
// using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template<typename T = int>
inline T read(void);

char buf_ans[114];
ll next_n(double last_ans=0,ll get_n=0){//last_ans<n<=1e18
sprintf(buf_ans,"%.6f",last_ans);
for(ll i=0,x=0;;i++){if(buf_ans[i]=='.')return get_n^x;if(i&1)x*=10;
else x=x*10+(buf_ans[i]^48);}}

const int mx = 34900;
ll blk[40000];
ll sum[40000];
double lans(0.0);

int main(){
    freopen("function.in", "r", stdin);
    freopen("function.out", "w", stdout);
    int T = read();
    blk[1] = 1; sum[1] = 5.0;
    for(int i = 1; i <= 35000; ++i)
        blk[i + 1] = (ll)ceil(powl((ld)i + 0.5, 4));
    for(int i = 1; i <= 34990; ++i)
        sum[i + 1] = sum[i] + (ld)1.0 / (ld)(i + 1) * (ld)(blk[i + 2] - blk[i + 1]);
    // for(int i = 1; i <= 100; ++i){
    //     printf("%lld : %lld\n", blk[i], sum[i]);
    // }
    while(T--){
        ll n = read<ll>();
        n = next_n(lans, n);
        // printf("%lld\n", n);
        int dist = lower_bound(blk + 1, blk + mx + 1, n) - blk;
        // printf("dis:%d\n", dist);
        // dist -= blk[dist] == n ? 1 : 2;
        --dist;
        // printf("new dis:%d\n", dist);
        // if(n == 89)printf("val: %lld + %.6Lf / %.6Lf\n", sum[dist - 1], (ld)(n - blk[dist] + 1), (ld)dist);
        ld ans = n == blk[dist + 1]
            ? (sum[dist] + (ld)(n - blk[dist + 1] + 1) / (ld)(dist + 1))
            : (sum[dist - 1] + (ld)(n - blk[dist] + 1) / (ld)dist);
        printf("%.6Lf\n", ans);
        lans = (double)ans;
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