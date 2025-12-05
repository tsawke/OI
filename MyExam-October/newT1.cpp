#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr

******************************/

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template<typename T = int>
inline T read(void);

string N, M;
#define EXIT(f) printf("%s\n", f ? "NO" : "YES"), exit(0)
// #define EXIT(f) printf("%s\n", f ? "YES" : "NO"), exit(0)

int main(){
    // freopen("intriguing_t1.in", "r", stdin);
    // freopen("intriguing_t1.out", "w", stdout);
    cin >> N >> M;
    if(N.length() > M.length())EXIT(true);
    if(N.length() < M.length())EXIT(false);
    for(int i = 1; i <= (int)N.length(); ++i){
        if(N.at(i - 1) > M.at(i - 1))EXIT(true);
        if(N.at(i - 1) < M.at(i - 1))EXIT(false);
    }EXIT(true);
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