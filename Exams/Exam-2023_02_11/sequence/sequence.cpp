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

template < typename T = int >
inline T read(void);

int N, Q;
basic_string < int > A;

int main(){
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    int T = read();
    while(T--){
        A.clear(); A += -1;
        N = read(), Q = read();
        for(int i = 1; i <= N; ++i)A += read();
        while(Q--){
            int a = read(), b = read(), c = read(), d = read();
            basic_string < int > s1(A.substr(a, b - a + 1)), s2(A.substr(c, d - c + 1));
            sort(s1.begin(), s1.end()), sort(s2.begin(), s2.end());
            bool diff(false);
            for(int i = 0; i < (int)s1.size(); ++i){
                if(s1.at(i) != s2.at(i)){
                    if(!diff)diff = true;
                    else{printf("NO\n"); break;}
                }
                if(i == (int)s1.size() - 1)printf("YES\n");
            }
        }
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

/*
1
6 3
1 3 4 2 3 4
1 3 4 6
1 2 5 6
3 5 2 4
*/