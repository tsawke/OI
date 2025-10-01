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

    vector < pair < int, int > > res;

    auto Solve = [&](auto &&self, int l, int r)->void{
        if(l == r)return;
        int mid = (l + r) >> 1;
        for(int i = 1; i <= N; ++i)
            if(mid + 1 <= A[i] && A[i] <= r)res.push_back({2, i});
        int cur(l + 1);
        while(cur < mid + 1)res.push_back({1, cur++});
        self(self, l, mid), self(self, mid + 1, r);
    }; Solve(Solve, 0, N);

    printf("%d\n", res.size());
    for(auto [a, b] : res)printf("%d %d\n", a, b);
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