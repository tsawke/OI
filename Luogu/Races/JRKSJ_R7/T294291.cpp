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

int Q;
string S;
#define S(x) (x < 1 || x > N ? '#' : S.at(x - 1))

int main(){
    Q = read();
    cin >> S;
    int N = S.size();
    int tot(0);
    for(int i = 1; i <= N; ++i)if(S(i) != S(i - 1))++tot;
    printf("%d\n", (int)ceil((double)tot / 2.0));
    while(Q--){
        int p = read(); char c = getchar(); while(!isalpha(c))c = getchar();
        if(S(p) != c){
            if(S(p - 1) == c && S(p + 1) == c)tot -= 2;
            else if(S(p - 1) == c && S(p + 1) != c){--tot; if(S(p + 1) == S(p))++tot;}
            else if(S(p - 1) != c && S(p + 1) == c){--tot; if(S(p - 1) == S(p))++tot;}
            else if(S(p - 1) != c && S(p + 1) != c){
                if(S(p + 1) == S(p) && S(p - 1) == S(p))tot += 2;
                else if(S(p + 1) == S(p) || S(p - 1) == S(p))++tot;
            }S.at(p - 1) = c;
        }printf("%d\n", (int)ceil((double)tot / 2.0));
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