#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

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

string S;
#define S(i) (S.at(i - 1) == '1')
bitset < 10 > f;

int main(){
    cin >> S;
    f[1] = S(7);
    f[2] = S(4);
    f[3] = S(2) || S(8);
    f[4] = S(1) || S(5);
    f[5] = S(3) || S(9);
    f[6] = S(6);
    f[7] = S(10);
    if(S(1))printf("No\n"), exit(0);
    for(int i = 1; i <= (int)S.length(); ++i)
        for(int j = i + 2; j <= (int)S.length(); ++j)
            for(int k = i + 1; k <= j - 1; ++k)
                if(f[i] && f[j] && !f[k])printf("Yes\n"), exit(0);
    printf("No\n");

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