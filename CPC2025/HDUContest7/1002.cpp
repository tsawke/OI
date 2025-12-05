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
        int N = read();
        basic_string < int > X, Y, Z;
        ll ans(0);
        for(int i = 1; i <= N; ++i)
            X += read(), Y += read(), Z += read();
        sort(X.begin(), X.end()), sort(Y.begin(), Y.end()), sort(Z.begin(), Z.end());
        for(int i = 1; i <= N; ++i)
            ans += std::abs((ll)X.at(i - 1) + Y.at(i - 1) + Z.at(i - 1));
        printf("%lld\n", ans >> 1);
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