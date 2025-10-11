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
    int T = read();
    while(T--){
        int N = read();
        vector < int > val(N + 10, 0), cur(N + 10, 0);
        for(int i = 1; i <= N; ++i)val[i] = read();
        for(int i = 1; i <= N; ++i)cur[i] = read();
        basic_string < int > ans;
        bool poss(true);
        for(int i = N; i >= 1; --i){
            int mx(INT_MIN), mn(INT_MAX);
            int mxHeap(-1), mnHeap(-1);
            for(int p = i; p >= 1; p >>= 1){
                if(cur[p] == val[i]){
                    if((p == 1 || cur[p >> 1] >= val[i]) && cur[p] > mx)mxHeap = p;
                    if((p == 1 || cur[p >> 1] <= val[i]) && cur[p] < mn)mnHeap = p;
                }mx = max(mx, cur[p]), mn = min(mn, cur[p]);
            }
            int res(-1);
            if(!~mnHeap)ans += 0, res = mnHeap;
            else if(!~mxHeap)ans += 1, res = mxHeap;
            else{poss = false; break;}

            for(int p = res; p > 1; p >>= 1)cur[p] = cur[p >> 1];
        }
        if(!poss)printf("Impossible\n");
        else{
            for(auto i : ans)printf("%d", i);
            printf("\n");
        }
    }

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