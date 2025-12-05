#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

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

int N, Q;
void Build(void){
    FILE* input = fopen("in.txt", "w");
    N = rndd(800, 1000), Q = rndd(000, 1000);
    fprintf(input, "%d %d\n", N, Q);
    for(int i = 1; i <= N; ++i)fprintf(input, "%d ", rndd(1, N));
    fprintf(input, "\n");
    while(Q--){
        int l = rndd(1, N - 1), r = rndd(l, N);
        fprintf(input, "%d %d\n", l, r);
    }
    fclose(input);
}

int main(){
    while(true){
        Build();
        system("./bl < in.txt > bl.out");
        system("./my < in.txt > my.out");
        if(system("diff my.out bl.out"))printf("WA!\n"), exit(0);
        else printf("Accept!\n");
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