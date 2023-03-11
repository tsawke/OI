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

int N, X, Y;
int cntx(0), cnty(0);
int Ax[1100], Ay[1100];
bitset < 41000 > dpX[1100], dpY[1100];

int main(){
    N = read(), X = read() + 20001, Y = read() + 20001;
    for(int i = 1; i <= N; ++i)i & 1 ? Ax[++cntx] = read() : Ay[++cnty] = read();
    dpX[1][20001 + Ax[1]] = dpY[0][20001] = true;
    for(int i = 2; i <= cntx; ++i){
        for(int j = 1; j <= 40001; ++j){
            if(!dpX[i - 1][j])continue;
            if(1 <= j + Ax[i] && j + Ax[i] <= 40001)dpX[i][j + Ax[i]] = true;
            if(1 <= j - Ax[i] && j - Ax[i] <= 40001)dpX[i][j - Ax[i]] = true;
        }
    }
    for(int i = 1; i <= cnty; ++i){
        for(int j = 1; j <= 40001; ++j){
            if(!dpY[i - 1][j])continue;
            if(1 <= j + Ay[i] && j + Ay[i] <= 40001)dpY[i][j + Ay[i]] = true;
            if(1 <= j - Ay[i] && j - Ay[i] <= 40001)dpY[i][j - Ay[i]] = true;
        }
    }
    printf("%s\n", dpX[cntx][X] && dpY[cnty][Y] ? "Yes" : "No");

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