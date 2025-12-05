#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;


template<typename T = int>
inline T read(void);

vector<int>vert[110];
int fa[110];
int pos[110];
int dep[110];
int ans(0);
int N, M;
int maxLen(0);
void LCA(int, int, int);
void dfs(int, int);
vector<int> path[110];
int main(){
    freopen("lyh.in", "r", stdin);
    freopen("lyh.out", "w", stdout); 
    int T = read();
    T = 1;
    N = read();
    for(int i = 1; i <= N - 1; ++i){
        int from = read(), to = read(), v = read();
        vert[from].push_back(to);
        fa[to] = from;
    }
    dfs(1, 1);
    M = read();
    for(int i = 1; i <= M; ++i){
        int from = read(), to = read(), v = read();
        LCA(i, from, to);
    }
    int times(0);
    for(int i = 1; i <= M; ++i){
        while(path[i].size() < maxLen)path[i].push_back(-1);
    }
    for(int k = 1; k <= maxLen; ++k)
        for(int i = 1; i <= M; ++i){
            for(int j = i + 1; j <= M; ++j){
                if(path[i].at(k - 1) == path[j].at(k - 1))++times;
            }
        }
    printf("%d\n", times);

    return 0;
}
void dfs(int deep, int v){
    dep[v] = deep;
    for(auto i : vert[v])dfs(deep + 1, i);
}
void LCA(int x, int from, int to){
    // printf("-\n");
    vector<int>rpath;
    if(dep[from] > dep[to]){
        while(dep[from] != dep[to])
            from = fa[from],
            path[x].push_back(from);
    }else{
        while(dep[from] != dep[to])
            to = fa[to],
            rpath.push_back(to);
    }
    // printf("---\n");
    while(from != to){
        path[x].push_back(from);
        rpath.push_back(to);
        from = fa[from], to = fa[to];
    }
    // printf("----------\n");
    reverse(rpath.begin(), rpath.end());
    path[x].push_back(from);
    for(auto i : rpath)path[x].push_back(i);
    maxLen = max(maxLen, (int)path[x].size());
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