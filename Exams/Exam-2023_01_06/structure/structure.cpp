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

int N, K;
basic_string < int > ans;
deque < int > values;

int main(){
    freopen("structure.in", "r", stdin);
    freopen("structure.out", "w", stdout);
    N = read(), K = read();
    if(!K){
        for(int i = 1; i <= N * 2; ++i)printf("%d%c", i, i == N * 2 ? '\n' : ' ');
        exit(0);
    }
    ans += {K + 1, 1};
    for(int i = 1; i <= N * 2; ++i)if(i != K + 1 && i != 1)values.emplace_back(i);
    while(!values.empty())ans += {values.front(), values.back()}, values.pop_front(), values.pop_back();
    for(auto it = ans.begin(); it != ans.end(); ++it)printf("%d%c", *it, it == prev(ans.end()) ? '\n' : ' ');
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