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

struct Node{
    int l, r;
    friend const bool operator < (const Node &a, const Node &b){
        return a.r < b.l;
    }
};
set < Node > s;

int main(){
    int N = read();
    while(N--){
        char c = getchar(); while(!isupper(c))c = getchar();
        if(c == 'A'){
            int l = read(), r = read();
            int cnt(0);
            while(s.find(Node{l, r}) != s.end())
                ++cnt, s.erase(s.find(Node{l, r}));
            s.insert(Node{l, r});
            printf("%d\n", cnt);
        }else printf("%d\n", (int)s.size());
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