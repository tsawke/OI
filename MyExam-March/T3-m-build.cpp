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

char c[114514], c2[114514];

ll nv[50] = {
    0,
    114514,
    rndd(300 - 100, 300),
    rndd(300 - 100, 300),
    rndd(300 - 100, 300),
    rndd(300 - 100, 300),
    rndd(300 - 100, 300),
    rndd(100000 - 1000, 100000),
    rndd(100000 - 1000, 100000),
    rndd(100000 - 1000, 100000),
    rndd(100000 - 1000, 100000),
    rndd(100000 - 1000, 100000),
    rndd(100000 - 1000, 100000),
    rndd(2000000 - 1000, 2000000),
    rndd(2000000 - 1000, 2000000),
    rndd(2000000 - 1000, 2000000),
    rndd(2000000 - 1000, 2000000),
    rndd(10000000 - 1000, 10000000),
    rndd(10000000 - 1000, 10000000),
    rndd(10000000 - 1000, 10000000),
    rndd(10000000 - 1000, 10000000)
};
ll pv[50] = {
    0,
    998244353,
    998244353,
    998244353,
    998244353,
    998244353,
    998244353,
    998244353,
    998244353,
    998244353,
    998244353,
    998244353,
    998244353,
    998244353,
    998244353,
    998244353,
    998244353,
    1000000087,
    2000000011,
    2000000137,
    2000001001
};

int main(){
    for(int i = 1; i <= 20; ++i){
        // sprintf(c, "OI/MyExam-March/T3/slack_off%d.in", i);
        // FILE* input = fopen(c, "w");
        // int N = nv[i], K = i == 1 ? 1145141 : rndd(5, 100), P = pv[i];
        // fprintf(input, "%d %d %d\n", N, K, P);
        // fclose(input);
        sprintf(c2, "./std < OI/MyExam-March/T3/slack_off%d.in > OI/MyExam-March/T3/slack_off%d.ans", i, i);
        system(c2);
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