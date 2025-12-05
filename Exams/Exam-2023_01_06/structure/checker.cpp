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

int a[111000];

int main(){
    while(true){
        FILE* input = fopen("in.txt", "w");
        int N = rndd(1, 50000), K = rndd(0, N >> 1);
        fprintf(input, "%d %d\n", N, K);
        fcloseall();
        system("./std < in.txt > my.out");
        FILE* output = fopen("my.out", "r");
        for(int i = 1; i <= N * 2; ++i)fscanf(output, "%d", &a[i]);
        fcloseall();
        ll sum1(0), sum2(0);
        for(int i = 1; i <= N * 2; i += 2)sum1 += abs(a[i + 1] - a[i]), sum2 += a[i + 1] - a[i];
        sum2 = abs(sum2);
        if(sum1 - sum2 == K << 1)printf("Accept!\n");
        else printf("Wrong!\n"), exit(0);
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