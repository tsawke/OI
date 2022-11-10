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

struct Line{
    int l, r;
    friend const bool operator < (const Line &a, const Line &b){return a.l < b.l;}
}a[110000];
vector < int > pos;
int N;
int d[210000];
int sum[210000];

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)a[i].l = read(), a[i].r = read(), pos.emplace_back(a[i].l), pos.emplace_back(a[i].r);
    sort(pos.begin(), pos.end());
    auto endpos = unique(pos.begin(), pos.end());
    int siz = distance(pos.begin(), endpos);
    for(int i = 1; i <= N; ++i)
        a[i].l = distance(pos.begin(), upper_bound(pos.begin(), endpos, a[i].l)),
        a[i].r = distance(pos.begin(), upper_bound(pos.begin(), endpos, a[i].r));
    for(int i = 1; i <= N; ++i)d[a[i].l]++, d[a[i].r]--;
    int tot(0);
    for(int i = 1; i < siz; ++i){
        d[i] += d[i - 1];
        if(d[i])tot += pos.at(i + 1 - 1) - pos.at(i - 1);
        if(d[i] == 1)sum[i] += pos.at(i + 1 - 1) - pos.at(i - 1);
        sum[i] += sum[i - 1];
    }int mx(-1);
    for(int i = 1; i <= N; ++i)mx = max(mx, tot - (sum[a[i].r - 1] - sum[a[i].l - 1]));
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