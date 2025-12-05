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

int N, K;
ll A[110000];
ll sum[110000];
ll dp[110000];
deque < pair < int, ll > > cur;

int main(){
    N = read(), K = read();
    for(int i = 1; i <= N; ++i)sum[i] = sum[i - 1] + (A[i] = read());
    cur.push_back({0, 0});
    for(int i = 1; i <= N; ++i){
        while(!cur.empty() && cur.front().first < i - K)cur.pop_front();
        while(!cur.empty() && cur.back().second < dp[i - 1] - sum[i])cur.pop_back();
        cur.push_back({i, dp[i - 1] - sum[i]});
        dp[i] = sum[i] + (cur.empty() ? 0 : cur.front().second);
    }printf("%lld\n", dp[N]);
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