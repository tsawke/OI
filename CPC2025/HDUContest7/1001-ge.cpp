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
    while(true){
        int T = rndd(1, 1);
        FILE* out = fopen("./1001.in", "w");
        fprintf(out, "%d\n", T);
        int sumN(0);
        for(int t = 1; t <= T; ++t){
            int N = rndd(2, 10 / T), K = rndd(1, min(N, 4));
            sumN += N;
            fprintf(out, "%d %d\n", N, K);
            for(int i = 1; i <= N; ++i){
                fprintf(out, "%d %d %d\n", rndd(1, N), rndd(1, N), rndd(1, 10));
            }
        }
        fclose(out);

        system("./bl < ./1001.in > bl.out");
        system("./lwc < ./1001.in > lwc.out");

        if(system("diff ./bl.out ./lwc.out")){
            printf("Found Diff\n"); exit(1);
        }
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