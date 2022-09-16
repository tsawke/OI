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
int N, Q;
void BuildVal(void){
    freopen("/home/jdoi/cpp/OI/in.txt", "w", stdout);
    int T = rndd(1, 10);
    printf("%d\n", T);
    while(T--){
        N = rndd(3, 10000), Q = rndd(1, 10000);
        printf("%d %d\n", N, Q);
        for(int i = 1; i <= N; ++i)printf("%d%c", rndd(1, 100000000), i == N ? '\n' : ' ');
        for(int q = 1; q <= Q; ++q){
            int opt = rndd(1, 4);
            int l = rndd(1, N - 2);
            int r = rndd(l + 1, N - 1);
            printf("%d %d %d", opt, l, r);
            if(opt == 4){
                int k = rndd(1, N - r);
                printf(" %d\n", k);
            }else{
                printf("\n");
            }
            fflush(stdout);
        }
    }
    fflush(stdout);
}

int main(){
    // BuildVal();
    while(true){
        BuildVal();
        freopen("/home/jdoi/cpp/OI/log.txt", "a", stdout);
        // fprintf(stderr, "Caling std...\n");
        system("/home/jdoi/cpp/OI/std < /home/jdoi/cpp/OI/in.txt > /home/jdoi/cpp/OI/out-std.txt");
        // fprintf(stderr, "Caling bl...\n");
        system("/home/jdoi/cpp/OI/bl < /home/jdoi/cpp/OI/in.txt > /home/jdoi/cpp/OI/out-bl.txt");
        fflush(stdout);
        if(!system("diff /home/jdoi/cpp/OI/out-bl.txt /home/jdoi/cpp/OI/out-std.txt")){
            fflush(stdout);
            fprintf(stderr, "Compare Successful! Which N = %d, Q = %d\n", N, Q);
        }else{
            fprintf(stderr, "Wrong! Which N = %d, Q = %d\n", N, Q);
            break;
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