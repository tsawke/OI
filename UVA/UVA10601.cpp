#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

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


int cnt[7];
ll fact[13];

void Init(void){
    fact[0] = 1;
    for(int i = 1; i <= 12; ++i)fact[i] = fact[i - 1] * i;
}
ll Cal(int len, int siz = 12){
    if(siz % len)return 0;
    ll ret = fact[siz / len];
    for(int i = 1; i <= 6; ++i){
        if(cnt[i] % len)return 0;
        else ret /= fact[cnt[i] / len];
    }return ret;
}

int main(){
    Init();
    int T = read();
    while(T--){
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= 12; ++i)cnt[read()]++;
        ll ans(0);
        ans += Cal(1) + 6 * Cal(4) + 3 * Cal(2) + 8 * Cal(3);
        for(int i = 1; i <= 6; ++i){
            if(!cnt[i])continue;
            --cnt[i];
            for(int j = 1; j <= 6; ++j){
                if(!cnt[j])continue;
                --cnt[j];
                ans += Cal(2, 10) * 6;
                ++cnt[j];
            }++cnt[i];
        }printf("%lld\n", ans / 24);
    }

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

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