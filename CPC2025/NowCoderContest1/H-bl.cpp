#pragma GCC optimize("Ofast")
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

bool tmp[1100000], d[1100000], s[1100000];

int main(){
    int N = read(), Q = read();
    for(int i = 1; i <= N; ++i){
        char c = getchar(); while(c != '0' && c != '1')c = getchar();
        tmp[i] = c - '0';
        d[i] = tmp[i] ^ tmp[i - 1];
    }
    while(Q--){
        int opt = read();
        if(opt == 1)
            d[read()] ^= 1, d[read() + 1] ^= 1;
        else{
            for(int i = 1; i <= N; ++i)s[i] = s[i - 1] ^ d[i];//, printf("s[%d] = %d\n", i, s[i]);

            int l = read(), a = read(), b = read();
            ll ans(0), cur(0);
            for(int i = 0; i <= l - 1; ++i)
                if(s[a + i] == s[b + i])ans += ++cur;
                else cur = 0;
            printf("%lld\n", ans);
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