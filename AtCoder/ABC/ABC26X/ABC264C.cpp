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

int N1, M1, N2, M2;
int A[11][11], B[11][11];

int main(){
    N1 = read(), M1 = read();
    for(int i = 1; i <= N1; ++i)for(int j = 1; j <= M1; ++j)A[i][j] = read();
    N2 = read(), M2 = read();
    for(int i = 1; i <= N2; ++i)for(int j = 1; j <= M2; ++j)B[i][j] = read();
    int SmxN = (1 << N1) - 1, SmxM = (1 << M1) - 1;
    for(int SN = SmxN; SN; SN = (SN - 1) & SmxN){
        if(__builtin_popcount(SN) != N2)continue;
        for(int SM = SmxM; SM; SM = (SM - 1) & SmxM){
            if(__builtin_popcount(SM) != M2)continue;
            // cout << "N : " << bitset < 8 >(SN) << endl;
            // cout << "M : " << bitset < 8 >(SM) << endl;
            bool flag(true);
            int cntN(0), cntM(0);
            for(int i = 0; i < N1; ++i)
                if(SN & (1 << i)){
                    ++cntN;
                    cntM = 0;
                    for(int j = 0; j < M1; ++j)
                        if(SM & (1 << j))
                            if(A[i + 1][j + 1] != B[cntN][++cntM])flag = false;
                }
            if(flag)printf("Yes\n"), exit(0);
        }
    }printf("No\n");
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