#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

int arr[210000];
int N, Q;
int minpos(0), minn(INT_MAX);


int main(){
    int T = read();
    while(T--){
        minpos = 0; minn = INT_MAX;
        N = read(), Q = read();
        for(int i = 1; i <= N; ++i){
            arr[i] = read();
            // if(arr[i] < minn){
            //     minn = arr[i];
            //     minpos = i;
            // }
        }
        for(int q = 1; q <= Q; ++q){
            int opt = read();
            switch(opt){
                case 1:{
                    int l = read(), r = read();
                    sort(arr + l, arr + r + 1, less<int>());
                    break;
                }
                case 2:{
                    int l = read(), r = read();
                    sort(arr + l, arr + r + 1, greater<int>());
                    break;
                }
                case 3:{
                    int l = read(), r = read();
                    reverse(arr + l, arr + r + 1);
                    break;
                }
                case 4:{
                    int l = read(), r = read(), k = read();
                    for(int i = l; i <= r; ++i)swap(arr[i], arr[i + k]);
                }
            }
        }
        for(int i = 1; i <= N; ++i){
            if(arr[i] < minn){
                minn = arr[i];
                minpos = i;
            }
        }
        printf("%d\n", minpos);
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