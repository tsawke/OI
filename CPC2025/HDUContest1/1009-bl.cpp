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

int a[2100000];

int main(){
    int T = read();
    while(T--){
        int N = read();
        for(int i = 1; i <= N; ++i)a[i] = read();
        int mx(0);
        for(int l = 1; l < N; ++l)
            for(int r = l + 1; r <= N; ++r){
                int cnt(2);
                for(int i = l + 1; i <= r - 1; ++i)
                    cnt += (a[i] < a[l] && a[i] < a[r]);
                mx = max(mx, cnt);
            }
        printf("%d\n", mx);
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

/*
5
7
6 7 1 5 4 2 3
10
9 10 6 7 1 5 4 2 3 8
8
6 7 1 5 4 2 3 8
10
1 2 3 4 5 6 7 8 9 10
10
10 9 8 7 6 5 4 3 2 1


*/