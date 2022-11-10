#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

template< typename T = int >
inline T read(void);

int N;
int c[110000];

bool Check(int pos){
    std::priority_queue < int, vector < int >, greater < int > > q;
    for(int i = 1; i < pos; ++i)q.push(c[i]);
    int cur(N - pos);
    while(!q.empty()){
        int tp = q.top(); q.pop();
        if(tp > cur)return false;
        else ++cur;
    }return true;
}

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)c[i] = read();
    int l = 1, r = N, ans = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(!Check(mid))ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    printf("%d\n", N - ans + 1);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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