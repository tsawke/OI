#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long unll;
typedef long double ld;
typedef unsigned int uint;

#define npt nullptr
#define PI M_PI
#define E M_E

template < typename T = int >
inline T read(void);

// struct Tree{
//     int arr[61000];
//     int lim;
//     int lowbit(int x){return x & (-x);}
//     void push(int v){while(x <= lim){arr[x] += x}}
// }
int N;
int a[610000];
int main(){
    freopen("swaq.in", "r", stdin);
    freopen("swaq.out", "w", stdout);








    
    N = read();
    for(int i = 1; i <= N; ++i)a[i] = read();
    if(N <= 500){
        // int times(0);
        // for(int i = 1; i <= N; ++i){
        //     for(int j = i + 1; j <= N; ++j){
        //         if(i > j)++times;
        //     }
        // }
        // int maxx(0);
        // for(int i = 1; i <= N; ++i){
        //     for(int j = 1; j <= N; ++j){

        //     }
        // }
        int minn = INT_MAX;
        for(int i = 1; i <= N; ++i){
            for(int j = i + 1; j <= N; ++j){
                swap(a[i], a[j]);
                int sum(0);
                for(int k = 1; k <= N; ++k){
                    for(int l = k + 1; l <= N; ++l){
                        if(a[l] < a[k])++sum;
                    }
                }
                // for(int i_ = 1; i_ <= N; ++i_)printf("%d ", a[i_]);
                // printf(" ans is %d\n", sum);
                swap(a[i], a[j]);
                minn = min(minn, sum);
            }
        }
        printf("%d\n", minn + 1);
    }

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    T flag(1);
    char c = getchar();
    while(!isdigit(c) && c != '-')c = getchar();
    if(c == '-'){flag = -1; c = getchar();}
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}