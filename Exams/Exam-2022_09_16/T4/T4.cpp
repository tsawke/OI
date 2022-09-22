#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

int N;
//x < y => -1, x > y => 1
vector < tuple < int, int, int > > relations;
int ans(0);
int a[110];
int main(){
    freopen("T4.in", "r", stdin);
    freopen("T4.out", "w", stdout);
    N = read();
    for(int i = 1; i <= N - 1; ++i){
        int x = read(), y = read(), op = read();
        relations.push_back(make_tuple(x, y, op));
    }
    int frac(1);
    for(int i = 1; i <= N; ++i)frac *= i, a[i] = i;
    --frac;
    for(int i = 1; i <= frac; ++i){
        bool flag(true);
        for(auto j : relations){
            int x, y, op; tie(x, y, op) = j;
            if((op && a[x] <= a[y]) || (!op && a[x] >= a[y])){
                flag = false;
                break;
            }
        }
        if(flag)++ans;
        next_permutation(a + 1, a + N + 1);
    }
    printf("%d\n", ans);

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