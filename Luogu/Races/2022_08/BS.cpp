#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

#define abbr

#define logg(a, b) (log(b) / log(a))

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;


template<typename T = int>
inline T read(void);


int N, Q;
int arr[21];
int main(){
    N = read();
    // printf("%.2lf\n", logg(2, N));
    if(N > 20){
        for(int i = 1; i <= N; ++i)(void)read();
        Q = read();
        for(int i = 1; i <= Q; ++i)printf("%.0lf\n", logg(2, N));
        for(int i = 1; i <= Q; ++i)(void)read();
        return 0;
    }
    if(N <= 20)for(int i = 1; i <= N; ++i)arr[i] = read();
    Q = read();
    for(int i = 1; i <= Q; ++i){
        int q = read();
        int pos = find(arr + 1, arr + N + 1, q) - arr;
        int cnt(0);
        int l = 1, r = N;
        while(l != r){
            if(abs(r - l) == 1){
                ++cnt;
                break;
            }
            printf("l = %d, r = %d\n", l, r);
            ++cnt;
            int mid = (l + r) >> 1;
            if(mid == pos || (mid + 1 == pos && (l + r) & 1))l = mid;
            else{
                if(mid < pos){
                    l = mid + (((l + r) & 1 )? 0 : 1);
                }else{
                    r = mid - (((l + r) & 1 )? 0 : 1);
                }
                
            }
        }
        printf("%d\n", cnt);
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