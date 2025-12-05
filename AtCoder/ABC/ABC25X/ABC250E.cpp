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

int N;
int a[210000], b[210000];
unll suma[210000], sumb[210000];
unordered_set < int > exta, extb;

int main(){
    N = read();
    for(int i = 1; i <= N; ++i){
        a[i] = read();
        suma[i] = suma[i - 1] ^ (
            exta.find(a[i]) == exta.end()
                ? exta.insert(a[i]), (unll)a[i] * (114514123ll)
                : 0ll
        );
    }
    for(int i = 1; i <= N; ++i){
        b[i] = read();
        sumb[i] = sumb[i - 1] ^ (
            extb.find(b[i]) == extb.end()
                ? extb.insert(b[i]), (unll)b[i] * (114514123ll)
                : 0ll
        );
    }
    int Q = read();
    while(Q--){
        int x = read(), y = read();
        printf("%s\n", suma[x] == sumb[y] ? "Yes" : "No");
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