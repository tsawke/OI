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

int N, M1, M2;
std::priority_queue < pair < int, int >/*leave_time, number*/, vector < pair < int, int > >, greater < pair < int, int > > > times;
std::priority_queue < int, vector < int >, greater < int > > num;
std::priority_queue < pair < int, int >/*arrive_time, leave_time*/, vector < pair < int, int > >, greater < pair < int, int > > > inv, abv;
int inport[110000], abport[110000];

int main(){
    N = read(), M1 = read(), M2 = read();
    for(int i = 1; i <= M1; ++i){int arr = read(), lev = read(); inv.push({arr, lev});}
    for(int i = 1; i <= M2; ++i){int arr = read(), lev = read(); abv.push({arr, lev});}
    for(int i = 1; i <= N; ++i)num.push(i);
    for(int i = 1; i <= M1; ++i){
        int arr = inv.top().first, lev = inv.top().second; inv.pop();
        while(!times.empty() && times.top().first <= arr)num.push(times.top().second), times.pop();
        if(!num.empty())++inport[num.top()], times.push({lev, num.top()}), num.pop();
    }
    while(!num.empty())num.pop();
    while(!times.empty())times.pop();
    for(int i = 1; i <= N; ++i)num.push(i);
    for(int i = 1; i <= M2; ++i){
        int arr = abv.top().first, lev = abv.top().second; abv.pop();
        while(!times.empty() && times.top().first <= arr)num.push(times.top().second), times.pop();
        if(!num.empty())++abport[num.top()], times.push({lev, num.top()}), num.pop();
    }
    for(int i = 1; i <= N; ++i)inport[i] += inport[i - 1], abport[i] += abport[i - 1];
    int mx(-1);
    for(int i = 0; i <= N; ++i)
        mx = max(mx, inport[i] + abport[N - i]);
    printf("%d\n", mx);
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