#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr

******************************/

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template<typename T = int>
inline T read(void);

int B, Q;
int cnt[1100000];
ll sum[1100000];
ll tot(0);

int main(){
    B = read(), Q = read();
    for(int i = 0; i <= B - 1; ++i)cnt[i] = read(), tot += (ll)cnt[i] * i;
    if(tot % (B - 1))--cnt[tot % (B - 1)];
    sum[0] = cnt[0];
    for(int i = 1; i <= B - 1; ++i)sum[i] = sum[i - 1] + cnt[i];
    while(Q--){
        ll ask = read<ll>() + 1;
        if(ask > sum[B - 1])printf("-1\n");
        else printf("%d\n", (int)(lower_bound(sum, sum + B + 1 - 1, ask) - sum));
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