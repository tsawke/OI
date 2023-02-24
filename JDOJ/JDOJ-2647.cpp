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

// mt19937 rnd(random_device{}());
// int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
// bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

// template < typename T = int >
template < typename T >
inline T read(void);
#define read read < int >

int N;
int w[110000];
ll s[110000];
ll F[110000], G[110000];
deque < pair < int, ll > > cur;

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)w[i] = read();
    reverse(w + 1, w + N + 1);
    for(int i = 1; i <= N; ++i)s[i] = s[i - 1] + w[i];
    cur.push_back(make_pair(0, 0ll));
    for(int i = 1; i <= N; ++i){
        pair < int, ll > lst = make_pair(-1, -1ll);
        while(!cur.empty() && cur.front().second <= s[i])lst = cur.front(), cur.pop_front();
        if(~lst.first)cur.push_front(lst);
        F[i] = F[cur.empty() ? 0 : cur.front().first] + 1;
        G[i] = s[i] - s[cur.empty() ? 0 : cur.front().first];
        while(!cur.empty() && cur.back().second > s[i] + G[i])cur.pop_back();
        cur.push_back({i, s[i] + G[i]});
    }printf("%lld\n", F[N]);
    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

#undef read

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