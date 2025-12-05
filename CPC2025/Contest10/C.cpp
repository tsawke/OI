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
        __int128_t P = read < __int128_t >(), M = read < __int128_t >();
        __int128_t mul = M / P;
        __int128_t ans(mul);
        int cnt(0);
        // while((((mul + cnt) * P + 1) ^ (P - 1)) <= M)printf("cnt = %d, v = %lld\n", cnt, ((mul + cnt) * P + 1) ^ (P - 1)), ++cnt;
        for(int cnt = 0; cnt <= 100; ++cnt)
            if((((mul + cnt) * P + 1) ^ (P - 1)) <= M)++ans;
        printf("%lld\n", (ll)ans);
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

/*

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


ll P = 7;
basic_string < ll > nums;


int main(){
    freopen("./out.txt", "w", stdout);
    ll ans(0);
    for(ll i = 1; i <= 114514; ++i){
        if((i ^ (P - 1)) % P == 1)++ans, nums += i;
        printf("[%lld] = %lld%c", i, ans, (i + 1) % P == 0 ? '\n' : ' ');
    }
    printf("\n\n");
    for(auto v : nums)printf("%d ", v);
    printf("\n");

    char S[114514];
    itoa(P - 1, S, 2);
    printf("P - 1 is %s\n\n", S);

    for(auto v : nums){
        char S[114514], S2[114514];
        itoa(v, S, 2);
        itoa(v ^ (P - 1), S2, 2);
        printf("(v = %lld) %s -> %s  (d = %lld, mul = %lld) reg = %lld\n", v, S, S2, v ^ (P - 1), (v ^ (P - 1)) / P, v / P);
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

*/