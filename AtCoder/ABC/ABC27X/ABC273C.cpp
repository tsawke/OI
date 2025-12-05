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

int N;
pair < int, int > A[210000];
int tmp[210000];
int sum[210000];
int ans[210000];


int main(){
    N = read();
    for(int i = 1; i <= N; ++i)tmp[i] = read();
    sort(tmp + 1, tmp + N + 1, greater < int >());
    int cnt(0);
    for(int i = 1; i <= N; ++i){
        if(tmp[i] != tmp[i - 1])A[++cnt] = {tmp[i], 1};
        else A[cnt].second++;
    }
    for(int i = 1; i <= cnt; ++i)ans[i - 1] += A[i].second;
    for(int i = 0; i < N; ++i)printf("%d\n", ans[i]);

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