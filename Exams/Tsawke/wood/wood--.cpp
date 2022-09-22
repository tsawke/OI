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
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

int N, M;
int stk[210000];

vector < pair < int, int > > l;

int main(){
    N = read(), M = read();
    stk[1] = -1, stk[N] = 1;
    l.push_back({1, N});
    while(M--){
        int opt = read();
        if(opt == 1){
            int x = read();
            char c = getchar(); while(c != 'X' && c != '(' && c != ')')c = getchar();
            stk[x] = c == 'X' ? 0 : (c == '(' ? -1 : 1);
        }else{
            int l = read(), r = read();
            stack < int > s;
            int cnt(0);
            for(int i = l; i <= r; ++i){
                if(stk[i] == -1 && s.empty())s.push(-1);
                if(stk[i] == 1 && !s.empty())++cnt, s.pop();
            }
            printf("%d\n", cnt);
        }
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