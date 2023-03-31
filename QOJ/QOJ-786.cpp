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

#define S(i) (S.at(i - 1))
#define BASE (31)

template < typename T = int >
inline T read(void);

int N;
string S;
unll h[110000];
unll powB[110000];

int main(){
    cin >> S;
    N = S.length();
    for(int i = 1; i <= N; ++i)h[i] = h[i - 1] * BASE + S(i);
    powB[0] = 1;
    for(int i = 1; i <= N; ++i)powB[i] = powB[i - 1] * BASE;
    printf("0 ");
    for(int s = 2; s <= N; ++s){
        int l = s, r = N, ans(0);
        while(l <= r){
            int mid = (l + r) >> 1;
            int siz = mid - s + 1;
            if(h[siz] == h[mid] - h[s - 1] * powB[siz])ans = siz, l = mid + 1;
            else r = mid - 1;
        }printf("%d%c", ans, s == N ? '\n' : ' ');
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
    }ret *= flag;
    return ret;
}