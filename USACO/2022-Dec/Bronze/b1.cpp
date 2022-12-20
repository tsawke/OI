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

int N, M;
bitset < 110 > str[110];
bitset < 110 > res;
basic_string < int > cur;

bool Check(int end, int p = 1){
    if((int)cur.size() <= 1)return true;
    bool ex[2][2]; memset(ex, false, sizeof ex);
    for(auto i : cur)ex[str[i][p]][res[i]] = true;
    // printf("ex: 0: %d, %d, 1: %d, %d\n", ex[0][0] ? 1 : 0, ex[0][1] ? 1 : 0, ex[1][0] ? 1 : 0, ex[1][1] ? 1 : 0);
    if(p == N)
        return ((ex[0][0] ^ ex[0][1]) || (!ex[0][0] && !ex[0][1])) && ((ex[1][0] ^ ex[1][1]) || (!ex[1][0] && !ex[1][1]));
    if(ex[0][0] && ex[0][1] && ex[1][0] && ex[1][1])return false;
    if((ex[0][0] ^ ex[0][1]) && ex[1][0] && ex[1][1]){
        for(auto it = cur.begin(); it != cur.end();)
            if(!str[*it][p])it = cur.erase(it);
            else advance(it, 1);
        return Check(p + 1);
    }
    if(ex[0][0] && ex[0][1] && (ex[1][0] ^ ex[1][1])){
        for(auto it = cur.begin(); it != cur.end();)
            if(str[*it][p])it = cur.erase(it);
            else advance(it, 1);
        return Check(p + 1);
    }
    if((ex[0][0] ^ ex[0][1]) && (ex[1][0] ^ ex[1][1])){
        auto tmp(cur);
        for(auto it = cur.begin(); it != cur.end();)
            if(str[*it][p])it = cur.erase(it);
            else advance(it, 1);
        bool ret(Check(p + 1));
        cur = tmp;
        for(auto it = cur.begin(); it != cur.end();)
            if(!str[*it][p])it = cur.erase(it);
            else advance(it, 1);
        return ret | Check(p + 1);
    }
    return true;
}

int main(){
    int T = read();
    while(T--){
        N = read(), M = read();
        for(int i = 1; i <= M; ++i){
            for(int j = 1; j <= N; ++j){
                char c = getchar(); while(!isdigit(c))c = getchar();
                str[i][N - j + 1] = c == '1' ? true : false;
            }char c = getchar(); while(!isdigit(c))c = getchar();
            res[i] = c == '1' ? true : false;
        }
        bool ans(false);
        for(int i = 1; i <= N; ++i){
            cur.clear();
            for(int j = 1; j <= M; ++j)cur += i;
            ans |= Check(i);
        }
        printf("%s\n", ans ? "OK" : "LIE");
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