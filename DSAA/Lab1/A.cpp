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

template < typename T = int >
inline T read(void);



int main(){
    basic_string < int > res;
    int N = read() - 1;
    res += read();
    for(int i = 1; i <= N; ++i){
        int val = read();
        for(auto it = res.begin(); it != res.end(); advance(it, 1)){
            if(*it > val){res.insert(it, val); break;}
            if(it == prev(res.end())){res += val; break;}
        }
    }
    for(auto i : res)printf("%d ", i);
    printf("\n");

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template < typename T >
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