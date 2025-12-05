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

#define EPS (1e-5)

template < typename T = int >
inline T read(void);

int N;
double G[110][110];

void Gauss(void){
    for(int i = 1; i <= N; ++i){//i-row
        int mxp(i);
        for(int j = i + 1; j <= N; ++j)
            if(fabs(G[j][i]) > fabs(G[mxp][i]))mxp = j;
        for(int j = 1; j <= N + 1; ++j)
            swap(G[i][j], G[mxp][j]);
        if(fabs(G[i][i]) < EPS)printf("No Solution\n"), exit(0);
        for(int j = 1; j <= N; ++j){
            if(i == j)continue;
            double tmp = G[j][i] / G[i][i];
            for(int k = i + 1; k <= N + 1; ++k)
                G[j][k] -= G[i][k] * tmp;
        }
    }
    for(int i = 1; i <= N; ++i)G[i][N + 1] /= G[i][i];
}

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N + 1; ++j)
            G[i][j] = read();
    Gauss();
    for(int i = 1; i <= N; ++i)printf("%.2lf\n", G[i][N + 1]);
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