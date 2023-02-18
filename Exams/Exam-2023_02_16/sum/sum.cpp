/*
2
5
7 10 4 9 4
3
2 1 7

3
7
22 34 48 12 48 37 27
10
19 37 37 51 40 87 25 28 81 26
9
51 60 21 52 25 46 40 37 3
*/
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
int val[1100000];
int pri[1100000];
int pre[1100000], nxt[1100000];
bitset < 1100000 > vis;
ll ans(0);

priority_queue < pair < int, int >, vector < pair < int, int > >, less < pair < int, int > > > cur;

int main(){
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
    int T = read();
    while(T--){
        for(int i = 0; i <= N + 1; ++i)vis[i] = false;
        N = read();
        A[0] = A[N + 1] = 0; pre[0] = 0, nxt[N + 1] = N + 1, pre[N + 1] = N, nxt[0] = 1;
        val[0] = val[N + 1] = pri[0] = pri[N + 1] = 0, ans = 0;
        for(int i = 1; i <= N; ++i)A[i] = read();
        for(int i = 1; i <= N; ++i)pre[i] = i - 1, nxt[i] = i + 1;
        for(int i = 1; i <= N; ++i)val[i] = min(A[pre[i]], A[nxt[i]]);
        for(int i = 1; i <= N; ++i)pri[i] = val[i] - (val[pre[i]] - min(A[pre[pre[i]]], A[nxt[i]])) - (val[nxt[i]] - min(A[nxt[nxt[i]]], A[pre[i]]));
        for(int i = 1; i <= N; ++i)cur.push({pri[i], i});
        while(!cur.empty()){
            auto tp = cur.top(); cur.pop();
            int idx = tp.second;
            if(tp.first != pri[idx] || vis[idx])continue;
            ans += val[idx], vis[idx] = true;
            val[pre[idx]] = min(A[pre[pre[idx]]], A[nxt[idx]]);
            val[nxt[idx]] = min(A[nxt[nxt[idx]]], A[pre[idx]]);
            pri[pre[idx]] = val[pre[idx]] - (val[pre[pre[idx]]] - min(A[pre[pre[pre[idx]]]], A[nxt[idx]])) - (val[nxt[idx]] - min(A[nxt[nxt[idx]]], A[pre[pre[idx]]]));
            pri[nxt[idx]] = val[nxt[idx]] - (val[pre[idx]] - min(A[pre[pre[idx]]], A[nxt[nxt[idx]]])) - (val[nxt[nxt[idx]]] - min(A[nxt[nxt[nxt[idx]]]], A[pre[idx]]));
            cur.push({pri[pre[idx]], pre[idx]}), cur.push({pri[nxt[idx]], nxt[idx]});
            nxt[pre[idx]] = nxt[idx], pre[nxt[idx]] = pre[idx];
            int i = pre[pre[idx]];
            pri[i] = val[i] - (val[pre[i]] - min(A[pre[pre[i]]], A[nxt[i]])) - (val[nxt[i]] - min(A[nxt[nxt[i]]], A[pre[i]]));
            cur.push({pri[i], i});
            i = nxt[nxt[idx]];
            pri[i] = val[i] - (val[pre[i]] - min(A[pre[pre[i]]], A[nxt[i]])) - (val[nxt[i]] - min(A[nxt[nxt[i]]], A[pre[i]]));
            cur.push({pri[i], i});
        }printf("%lld\n", ans);
    }

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    // int flag(1);
    char c = getchar();
    while(!isdigit(c))c = getchar();
    // if(c == '-')flag = -1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    // ret *= flag;
    return ret;
}