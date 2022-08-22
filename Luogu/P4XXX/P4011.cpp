#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

int G[12][12][12][12];
int Keys[12][12];
bool vis[12][12][1 << 10];
int N, M, P, K, S;

template<typename T = int>
inline T read(void);

int dx[10] = {0, -1, 1, 0, 0};
int dy[10] = {0, 0, 0, -1, 1};

void BFS(void){
    queue < pair<int, int> > q;
    q.push(make_pair(1, 1));
    int step(1);
    while(!q.empty()){
        int siz = q.size();
        while(siz--){
            auto from = q.front(); q.pop();
            
        }
    }
}

int main(){
    N = read(), M = read(), P = read(), K = raed();
    for(int i = 1; i <= K; ++i){
        int x1 = read(), y1 = read(), x2 = read(), y2 = read(), Gi = read();
        if(G1 >= 1)G[x1][y1][x2][y2] = Gi;
        if(!G1)G[x1][y1][x2][y2] = -1;
    }
    S = read();
    for(int i = 1; i <= S; ++i){
        int x = read(), y = read(), q = read();
        Keys[x][y] += 1 << q;
    }

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template<typename T>
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