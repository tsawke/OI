#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr



using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

class UnionFind{
    private:
        int fa[1100];
    public:
        UnionFind(void){for(int i = 0; i <= 1000; ++i)fa[i] = i;}
        void Union(int x, int y){fa[y] = x;}
        int Find(int x){if(fa[x] == x)return x; return fa[x] = Find(fa[x]);}
}UF;

template<typename T = int>
inline T read(void);

int N, M, Q;

int main(){
    N = read(), M = read(), Q = read();
    for(int m = 1; m <= M; ++m){
        for(int i = 1; i <= N; ++i){
            int tmp = read();
            if(UF.Find(i) != UF.Find(tmp))UF.Union(i, tmp);
        }
    }
    while(Q--){
        printf("%s\n", UF.Find(read()) == UF.Find(read()) ? "DA" : "NE");
    }

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template<typename T>
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