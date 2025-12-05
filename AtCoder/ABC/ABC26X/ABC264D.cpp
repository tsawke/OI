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

int a[10];
unordered_map < char, int > mp;

int main(){
    mp.insert({'a', 1}),
    mp.insert({'t', 2}),
    mp.insert({'c', 3}),
    mp.insert({'o', 4}),
    mp.insert({'d', 5}),
    mp.insert({'e', 6}),
    mp.insert({'r', 7});
    for(int i = 1; i <= 7; ++i){
        char c = getchar();
        while(!isalpha(c))c = getchar();
        a[i] = mp[c];
    }int ans(0);
    for(int i = 1; i <= 7; ++i)for(int j = 1; j < i; ++j)
        if(a[j] > a[i])++ans;
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