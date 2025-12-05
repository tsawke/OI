#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <windows.h>

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
    // while(true){
        

    // }
    // FILE* f = fopen("./in.txt", "w");
    while(true){
        auto f = fopen("in.txt", "w");
        int N = 10, M = 10, K = rndd(2, N), Q = 10;
        fprintf(f, "%d %d %d %d\n", N, K, M, Q);
        for(int i = 1; i <= N; ++i)fprintf(f, "%d%c", rndd(1, 200), i == N ? '\n' : ' ');
        for(int i = 0; i <= M; ++i)fprintf(f, "%d%c", rndd(1, 200), i == M ? '\n' : ' ');
        // fprintf(f, "   ");
        while(Q--){
            if(rndd(1, 100) >= 33)
            fprintf(f, "q %d %d\n", rndd(1, N + M), rndd(1, N + M));
            else if(rndd(1, 100) >= 50)fprintf(f, "c %d\n", rndd(1, N));
            else fprintf(f, "x %d\n", rndd(N, N + M));
        }
        fclose(f);
        system("J.exe");
        system("J-ac.exe");

        if(system("cmd /c fc \"E:\\OI\\CPC\\Contest1\\out1.txt\" \"E:\\OI\\CPC\\Contest1\\out2.txt\"")){printf("%d err!\n", system("cmd /c fc \"E:\\OI\\CPC\\Contest1\\out1.txt\" \"E:\\OI\\CPC\\Contest1\\out2.txt\"")); break;}
        else printf("accept!\n");
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