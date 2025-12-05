#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

template < typename T = int >
inline T read(void);

int main(){
    while(true){
        FILE* input = fopen("in.txt", "w");
        int valMx(10000);
        int N = 100000, M = 100000, C = 100;
        fprintf(input, "%d %d %d\n", N, M, C);
        for(int i = 1; i <= N; ++i)fprintf(input, "%d%c", rndd(1, valMx), i == N ? '\n' : ' ');
        for(int i = 1; i <= N; ++i)fprintf(input, "%d%c", rndd(1, C), i == N ? '\n' : ' ');
        for(int i = 1; i <= M; ++i){
            int opt = rndd(1, 4);
            switch(opt){
                case 1:{
                    fprintf(input, "1 %d %d\n", rndd(1, N), rndd(1, valMx));
                    break;
                }
                case 2:{
                    int l = rndd(1, N), r = rndd(1, N);
                    fprintf(input, "2 %d %d %d\n", min(l, r), max(l, r), rndd(1, C));
                    break;
                }
                default:{
                    int l = rndd(1, N), r = rndd(1, N);
                    fprintf(input, "%d %d %d\n", rndd(3, 4), min(l, r), max(l, r));
                }
            }
        }
        fclose(input);
        system("./my < in.txt > my.out");
        system("./std < in.txt > std.out");
        if(system("diff ./my.out ./std.out"))fprintf(stderr, "Error!\n"), exit(1);
        static int cnt = 0;
        fprintf(stderr, "Test No.%d - Accept!\n", ++cnt);
    }
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    int flag(1);
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