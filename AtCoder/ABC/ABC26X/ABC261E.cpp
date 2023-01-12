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

int X, N;
int T[210000];
bitset < 32 > A[210000];
bitset < 32 > sum0[210000], sum1[210000];

int main(){
    sum0[0].reset(), sum1[0].set();
    N = read(), X = read();
    for(int i = 1; i <= N; ++i){
        T[i] = read(), A[i] = bitset < 32 >(read());
        switch(T[i]){
            case 1:{
                sum0[i] = sum0[i - 1] & A[i];
                sum1[i] = sum1[i - 1] & A[i];
                break;
            }
            case 2:{
                sum0[i] = sum0[i - 1] | A[i];
                sum1[i] = sum1[i - 1] | A[i];
                break;
            }
            case 3:{
                sum0[i] = sum0[i - 1] ^ A[i];
                sum1[i] = sum1[i - 1] ^ A[i];
                break;
            }
            default:break;
        }
    }
    bitset < 32 > ans(X);
    for(int i = 1; i <= N; ++i){
        for(int j = 0; j < 32; ++j)
            ans[j] = ans[j] ? sum1[i][j] : sum0[i][j];
        printf("%lu\n", ans.to_ulong());
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