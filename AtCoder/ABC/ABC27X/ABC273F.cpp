#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define __data(p) (__data.at(p - 1))
#define INFLL (0x3f3f3f3f3f3f3f3fll)

template < typename T = int >
inline T read(void);

int N, X;
int pos0;
int wall[1600];
set < int > walls;
basic_string < int > __data;
map < int, int > hammer;
ll dp[3200][3200][2]; //0=>left, 1=>right

int main(){
    memset(dp, 0x3f, sizeof dp);
    N = read(), __data += {(X = read()), 0};
    for(int i = 1; i <= N; ++i)__data += (wall[i] = read()), walls.insert(wall[i]);
    for(int i = 1; i <= N; ++i)__data += (hammer[wall[i]] = read());
    sort(__data.begin(), __data.end());
    X = distance(__data.begin(), next(lower_bound(__data.begin(), __data.end(), X)));
    pos0 = distance(__data.begin(), next(lower_bound(__data.begin(), __data.end(), 0)));
    N = (N << 1) + 2;
    dp[pos0][pos0][0] = dp[pos0][pos0][1] = 0;
    for(int len = 2; len <= N; ++len){
        for(int l = 1; l <= N - len + 1; ++l){
            int r = l + len - 1;
            dp[l][r][1] = min(dp[l][r][1], walls.find(__data(r)) == walls.end() || (__data(l) <= hammer[__data(r)] && hammer[__data(r)] <= __data(r - 1)) ? min(dp[l][r - 1][1] + __data(r) - __data(r - 1), dp[l][r - 1][0] + __data(r) - __data(l)) : INFLL);
            dp[l][r][0] = min(dp[l][r][0], walls.find(__data(l)) == walls.end() || (__data(l + 1) <= hammer[__data(l)] && hammer[__data(l)] <= __data(r)) ? min(dp[l + 1][r][0] + __data(l + 1) - __data(l), dp[l + 1][r][1] + __data(r) - __data(l)) : INFLL);
        }
    }ll ans(INFLL);
    for(int i = 1; i <= N; ++i)ans = min({ans, dp[i][X][1], dp[X][i][0]});
    printf("%lld\n", ans >= INFLL ? -1 : ans);
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