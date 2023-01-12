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

int N, X, Y;
int a[210000];
int cnt0(0), cnt1(0), cnt_1(0), l(1), r(-1);
ll ans(0);

ll GetC(int n, int m){
    if(n == 1)return 1;
    if(!n || m > n)return 0;
    ll ret(1);
    for(int i = n; i >= n - m + 1; --i)ret *= i;
    for(int i = m; i >= 1; --i)ret /= i;
    return ret + n;
}

int main(){
    N = read(), X = read(), Y = read();
    for(int i = 1; i <= N + 1; ++i){
        a[i] = i <= N ? read() : INT_MAX;
        a[i] = a[i] == X && a[i] == Y ? -114514 : (a[i] == X ? 1 : (a[i] == Y ? -1 : (Y <= a[i] && a[i] <= X ? 0 : 114514)));
        if(a[i] != 114514){r = i; continue;}
        if(!~r){l = i + 1; continue;}
        ll cur(0);
        cur += GetC(r - l + 1, 2);
        int ll(l), rr(-1);
        for(int j = l; j <= r; ++j){
            if(a[j] != -1 && a[j] != -114514){rr = j; continue;}
            if(!~rr){ll = j + 1; continue;}
            cur -= GetC(rr - ll + 1, 2);
            ll = j + 1;
        }if(ll <= rr)cur -= GetC(rr - ll + 1, 2);
        ll = l, rr = -1;
        for(int j = l; j <= r; ++j){
            if(a[j] != 1 && a[j] != -114514){rr = j; continue;}
            if(!~rr){ll = j + 1; continue;}
            cur -= GetC(rr - ll + 1, 2);
            ll = j + 1;
        }if(ll <= rr)cur -= GetC(rr - ll + 1, 2);
        ll = l, rr = -1;
        for(int j = l; j <= r; ++j){
            if(!a[j]){rr = j; continue;}
            if(!~rr){ll = j + 1; continue;}
            cur += GetC(rr - ll + 1, 2);
            ll = j + 1;
        }if(ll <= rr)cur += GetC(rr - ll + 1, 2);
        ans += cur;
        l = i + 1;
    }
    printf("%lld\n", ans);

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