#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

using ll = long long;
using unll = unsigned long long;
using uint = unsigned int;
using ld = long double;

template < typename T = int >
inline T read(void){
    T ret(0);
    short flag(1);
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

struct Edge{
    Edge* nxt;
    int to;
};

int main(){
    int N = read(), M = read();
    
    vector < Edge* > head(N + 1, nullptr);
    
    for(int k = 1; k <= M; ++k){
        int x = read(), y = read();
        head[x] = new Edge{head[x], y};
        head[y] = new Edge{head[y], x};
    }
    
    vector < int > dis1(N + 1, -1);
    queue < int > q;
    dis1[1] = 0;
    q.push(1);
    
    int farNode(1), farDist(0), cnt(0);
    
    while(!q.empty()){
        int p = q.front(); q.pop();
        ++cnt;
        if(dis1[p] > farDist)farDist = dis1[p], farNode = p;
        for(auto i = head[p]; i; i = i->nxt){
            int v = i->to;
            if(dis1[v] != -1)continue;
            dis1[v] = dis1[p] + 1;
            q.push(v);
        }
    }
    
    if(cnt < N){printf("-1\n"); return 0;}
    
    
    vector < int > dis2(N + 1, -1);
    queue < int > q2;
    dis2[farNode] = 0;
    q2.push(farNode);
    
    int dPrime(0);
    
    while(!q2.empty()){
        int p = q2.front(); q2.pop();
        if(dis2[p] > dPrime)dPrime = dis2[p];
        for(auto i = head[p]; i; i = i->nxt){
            int v = i->to;
            if(dis2[v] != -1)continue;
            dis2[v] = dis2[p] + 1;
            q2.push(v);
        }
    }
    
    int k(0), len(1);
    while(len < dPrime)len <<= 1, ++k;
    
    printf("%d\n", k + 1);
    
    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
