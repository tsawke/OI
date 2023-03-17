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

int p[10] = {0, 2, 3, 5, 7, 11, 13, 19};

int main(){
    while(true){
        FILE* input = fopen("in.txt", "w");
        int N = 5;
        fprintf(input, "%d\n", N);
        for(int i = 2; i <= N; ++i)fprintf(input, "%d%c", rndd(1, i - 1), i == N ? '\n' : ' ');
        for(int i = 1; i <= N; ++i)fprintf(input, "%d %d %d\n", p[rndd(1, 2)], rndd(1, 2), rndd(1, 2));
        fcloseall();
        system("./my < in.txt > my.out");
        system("./bl < in.txt > bl.out");
        if(system("diff ./my.out ./bl.out"))fprintf(stderr, "Error!\n"), exit(1);
        fprintf(stderr, "Accept!\n");
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