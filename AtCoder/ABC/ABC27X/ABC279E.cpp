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

int N, M;
int A[210000], B[210000], C[210000];
int L[210000], R[210000];

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)B[i] = i;
    for(int i = 1; i <= M; ++i){
        A[i] = read();
        L[i] = B[A[i]], R[i] = B[A[i] + 1];
        swap(B[A[i]], B[A[i] + 1]);
    }
    for(int i = 1; i <= N; ++i)C[B[i]] = i;
    for(int i = 1; i <= M; ++i)
        printf("%d\n", L[i] == 1 ? C[R[i]] : (R[i] == 1 ? C[L[i]] : C[1]));
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