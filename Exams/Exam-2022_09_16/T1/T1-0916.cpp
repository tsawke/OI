#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

namespace input{
    int seed,lst=1;
    const int prime1=163337,prime2=998244353;
    void init(){
        scanf("%d",&seed);
    }
    int read(){
        //return lst=((lst*prime1+seed)%prime2+prime2)%prime2;
    }
}

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) < x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

int a[6100000];
int N, D;
ll P;
namespace BL{
    int ans(0);
    int len(0);
    ll sum(0);
    deque < int > deq;
    int Make(void){
        for(int i = 1; i <= N - D + 1; ++i){
            len = 0;
            sum = 0;
            deq.clear();
            for(int j = 1; j <= N; ++j){
                ll val = (j >= i && j <= i + D - 1) ? 0 : a[j];
                while(!deq.empty() && sum + val > P)--len, sum -= deq.front(), deq.pop_front();
                if(sum + val <= P)deq.push_back(val), sum += val, ++len, ans = max(ans, len);
                // printf("%d ", len);
            }
            // printf("%d\n", ans);
        }
        return ans;
    }
}


int main(){
    // freopen("T1.in", "r", stdin);
    // freopen("T1.out", "w", stdout);
    N = read(); P = read<ll>(); D = read(); //input::init();
    for(int i = 1; i <= N; ++i)a[i] = read();
    if(N <= 1000){printf("%d\n", BL::Make()); return 0;}
    // printf("%d\n", BL::Make());
    int ans(0);
    ll cur(0);
    for(int i = 1; i <= D - 1; ++i)cur += a[i];
    ll maxx(-1), maxp;
    for(int i = 1; i <= N - D + 1; ++i){
        cur -= a[i - 1], cur += a[i + D - 1];
        if(cur > maxx){
            maxx = cur;
            maxp = i;
        }
    }
    // printf("%d\n", maxp);
    // for(int i = maxp; i <= maxp + D - 1; ++i)
    deque < int > deq;
    int len = 0;
    int sum = 0;
    deq.clear();
    for(int j = 1; j <= N; ++j){
        // printf("Caling p = %d\n", maxp);
        ll val = (j >= maxp && j <= maxp + D - 1) ? 0 : a[j];
        while(!deq.empty() && sum + val > P)--len, sum -= deq.front(), deq.pop_front();
        if(sum + val <= P)deq.push_back(val), sum += val, ++len, ans = max(ans, len);
        // printf("%d ", len);
    }
        int pos(0);
    while((double)clock() / CLOCKS_PER_SEC < 0.3){
        pos = 0;
        while(pos < 1 || pos > N - D + 1)pos = maxp - rndd(1, D - 1);
        // printf("Caling p = %d\n", pos);
        len = 0;
        sum = 0;
        deq.clear();
        for(int j = 1; j <= N; ++j){
            ll val = (j >= pos && j <= pos + D - 1) ? 0 : a[j];
            while(!deq.empty() && sum + val > P)--len, sum -= deq.front(), deq.pop_front();
            if(sum + val <= P)deq.push_back(val), sum += val, ++len, ans = max(ans, len);
            // printf("%d ", len);
        }
    }
    while((double)clock() / CLOCKS_PER_SEC < 0.5){
        pos = 0;
        while(pos < 1 || pos > N - D + 1)pos = int((double)maxp * ((double)rndd(1, 100) / 100) * (rnddd(50) ? 1 : -1));
        // printf("Caling p = %d\n", pos);
        len = 0;
        sum = 0;
        deq.clear();
        for(int j = 1; j <= N; ++j){
            ll val = (j >= pos && j <= pos + D - 1) ? 0 : a[j];
            while(!deq.empty() && sum + val > P)--len, sum -= deq.front(), deq.pop_front();
            if(sum + val <= P)deq.push_back(val), sum += val, ++len, ans = max(ans, len);
        }
    }
    while((double)clock() / CLOCKS_PER_SEC < 0.7){
        pos = rndd(1, N - D + 1);
        // printf("Caling p = %d\n", pos);
        len = 0;
        sum = 0;
        deq.clear();
        for(int j = 1; j <= N; ++j){
            ll val = (j >= pos && j <= pos + D - 1) ? 0 : a[j];
            while(!deq.empty() && sum + val > P)--len, sum -= deq.front(), deq.pop_front();
            if(sum + val <= P)deq.push_back(val), sum += val, ++len, ans = max(ans, len);
            // printf("%d ", len);
        }
    }
    printf("%d\n", ans);

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