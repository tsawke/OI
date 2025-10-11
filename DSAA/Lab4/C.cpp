#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

template < typename T = int >
inline T read(void);



int main(){
    int N = read();
    vector < int > A(N + 10, 0);
   
    for(int i = 1; i <= N; ++i)A[i] = read();
    #define LS (p << 1)
    #define RS (LS | 1)
    auto Heapify = [&](auto &&self, int p, int len)->void{
        int mx(p);
        if(LS <= len && A[LS] > A[mx])mx = LS;
        if(RS <= len && A[RS] > A[mx])mx = RS;
        if(mx != p)swap(A[mx], A[p]), self(self, mx, len);
    };
    auto HeapSort = [&](auto &&self, int len)->void{
        for(int i = (len >> 1); i >= 1; --i)Heapify(Heapify, i, len);
        for(int i = len; i > 1; --i)swap(A[1], A[i]), Heapify(Heapify, 1, i - 1);
    }; HeapSort(HeapSort, N);
    for(int i = 1; i <= N; ++i)printf("%d%c", A[i], i == N ? '\n' : ' ');

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template < typename T >
inline T read(void){
    T ret(0);
    short flag(1);
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