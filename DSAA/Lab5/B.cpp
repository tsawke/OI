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
    auto Partition = [](vector < int > &A, int l, int r)->pair < int, int >{
        int pivot(A[r]);
        int spl1(l - 1), spl2(r - 1);
        int cur(l);
        while(cur <= spl2){
            if(A[cur] < pivot)swap(A[++spl1], A[cur++]);
            else if(A[cur] > pivot)swap(A[cur], A[spl2--]);
            else ++cur;
        }
        swap(A[++spl2], A[r]);
        return {spl1 + 1, spl2};
    };
    auto QuickSort = [&](auto&& self, vector < int > &A, int l, int r)->void{
        if(l >= r)return;
        auto [spl1, spl2] = Partition(A, l, r);
        self(self, A, l, spl1 - 1);
        self(self, A, spl2 + 1, r);
    }; QuickSort(QuickSort, A, 1, N);

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