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

int N;
int A[1100000];
basic_string < int > vals[1100000];
int mx(0);

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)vals[A[i] = read()] += i;
    deque < int > cur;
    for(int i = 1; i <= 1000000; ++i){
        for(int j = vals[i].size(); j >= 1; --j){
            int v = vals[i].at(j - 1);
            while(!cur.empty() && cur.back() > v){
                while(!cur.empty() && A[cur.front()] < A[cur.back()])cur.pop_front();
                cur.pop_back();
            }mx = max(mx, (int)cur.size() + (int)vals[i].size() - j + 1);
        }
        for(int j = 1; j <= (int)vals[i].size(); ++j)cur.emplace_back(vals[i].at(j - 1));
    }printf("%d\n", N - mx);
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