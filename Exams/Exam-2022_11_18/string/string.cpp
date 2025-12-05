#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
// using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

template< typename T = int >
inline T read(void);

int N, K;
int cntj(0), cntz(0);
int cnt2j(0), cnt2z(0);
int ans(0);
// string S;
basic_string < char > a, b;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    N = read(), K = read();
    if(N == 1)printf("0\n"), exit(0);
    for(int i = 1; i <= N; ++i){
        char c = getchar(); while(c != 'j' && c != 'z')c = getchar();
        a += c;
    }
    for(auto it = a.begin(); it != a.end(); ++it){
        if(it == prev(a.end())){b += *it; continue;}
        // if(*it == 'j' && *next(it) == 'j')++cntj;
        // else if(*it == 'z' && *next(it) == 'z')++cntz;
        // else if(*it == 'z' && *next(it) == 'j')++cntz;
        // else
        if(*it == 'j' && *next(it) == 'z')++ans, advance(it, 1), b += '*';
        else b += *it;
    }a.clear(); a.swap(b);
    for(auto it = a.begin(); it != a.end(); ++it){
        if(it == prev(a.end())){*it == 'j' ? ++cntj : ++cntz; continue;}
        if(*it == 'j' && *next(it) == 'j')++cnt2j, advance(it, 1);
        else if(*it == 'z' && *next(it) == 'z')++cnt2z, advance(it, 1);
        else if(*it == 'z' && *next(it) == 'j')++cntz;
        else if(*it == 'j' && *next(it) == 'z')++ans, advance(it, 1);
    }
    while(K && cnt2j && cnt2z)--cnt2j, --cnt2z, --K, ans += 2;
    cntj += cnt2j * 2, cntz += cnt2z * 2;
    ans += min({cntj, cntz, K});
    // for(auto it = a.begin(); it != a.end(); ++it){
    //     if(it == prev(a.end())){b += *it; continue;}
    //     // if(*it == 'j' && *next(it) == 'j')++cntj;
    //     // else if(*it == 'z' && *next(it) == 'z')++cntz;
    //     // else if(*it == 'z' && *next(it) == 'j')++cntz;
    //     // else
    //     if(*it == 'j' && *next(it) == 'z')++ans, advance(it, 1), --cntj, --cntz;
    //     else b += *it;
    //     a.clear();
    //     a.swap(b);
    // }
    // while(K && cntj >= 1 && cntz >= 1){
    //     for(auto it = a.begin(); it != a.end(); ++it){
    //         if(it == prev(a.end())){b += *it; continue;}
    //         // if(*it == 'j' && *next(it) == 'j')++cntj;
    //         // else if(*it == 'z' && *next(it) == 'z')++cntz;
    //         // else if(*it == 'z' && *next(it) == 'j')++cntz;
    //         // else
    //         if(*it == 'j' && *next(it) == 'z')++ans, advance(it, 1), --cntj, --cntz;
    //         else b += *it;
    //         a.clear();
    //         a.swap(b);
    //     }
    // }
    // cin >> S; 
    // auto lst = S.begin();
    // for(auto cur = next(S.begin()); cur != S.end(); ++cur, ++lst){
    //     if(*lst == 'j' && *cur == 'j')++cntj;
    //     else if(*lst == 'z' && *cur == 'z')++cntz;
    //     else if(*lst == 'z' && *cur == 'j')++cntz;
    //     else if(*lst == 'j' && *cur == 'z'){
    //         ++ans;
    //         advance(lst, 1), advance(cur, 1);
    //         if(cur == S.end() || lst == S.end())break;
    //     }
    // }
    // if(!(*prev(S.end()) == 'z' && *prev(S.end(), 2) == 'j'))
    //     *prev(S.end()) == 'j' ? ++cntj : ++cntz;
    // printf("before : %d\n", ans);
    // ans += min({cntj, cntz, K});
    printf("%d\n", ans);
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