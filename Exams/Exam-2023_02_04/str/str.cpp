#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define BASE (31)

template < typename T = int >
inline T read(void);

int N;
string S;

namespace Sub_1_2{
    int ans(0);
    unll pow_base[210];
    unll hash[210], rhash[210];
    void Cal(void){
        hash[0] = rhash[N + 1] = 0;
        for(int i = 1; i <= N; ++i)hash[i] = hash[i - 1] * BASE + S.at(i - 1);
        for(int i = N; i >= 1; --i)rhash[i] = rhash[i + 1] * BASE + S.at(i - 1);
        for(int l = 1; l <= N; ++l){
            for(int r = l; r <= N; ++r){
                unll hash1 = hash[r] - hash[l - 1] * pow_base[r - l + 1];
                unll hash2 = rhash[l] - rhash[r + 1] * pow_base[r - l + 1];
                if(hash1 == hash2)ans = max(ans, r - l + 1);
            }
        }
    }
    void Make(void){
        pow_base[0] = 1;
        for(int i = 1; i <= 205; ++i)pow_base[i] = pow_base[i - 1] * BASE;
        Cal();
        for(int i = 1; i <= N - 2; ++i){
            char c = getchar(); while(!isalpha(c))c = getchar();
            S.at(i) = c;
            Cal();
        }printf("%d\n", ans);
    }
}


int main(){
    freopen("str.in", "r", stdin);
    freopen("str.out", "w", stdout);
    N = read(); cin >> S;
    if(N <= 600)Sub_1_2::Make();
    else puts("qwq");
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

/*
6
ABAECB
B
C
D
E
*/

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