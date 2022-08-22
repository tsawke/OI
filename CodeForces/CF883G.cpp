#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define RESET(str) memset(str, 0, sizeof(str))

template<typename T = int>
inline T read(void);

int N, M, s;

class Edge{
    public:
        int to;
        int nxt;
        int dir;
        int num_U;
        void set(int to, int nxt, int dir){
            this->to = to;
            this->nxt = nxt;
            this->dir = dir;// 1-from->to -1-to->from 0-ignore
        }
}edgeD[3100000], edgeU[3100000];
int headD[3100000], headU[3100000];

bool usedD[3100000], usedU[3100000];
bool vis[3100000];
int anss(1);
int cnt(0);
queue<int>vert;
// map<int, pair<int, int>>idx;
// map<pair<int, int>, int>ansidx;
int ans[3100000];

void Reset(void){
    // memset(used, false, sizeof(usedD));
    // memset(vis, false, sizeof(vis));
    // RESET(edgeD);
    // RESET(edgeU);
    // RESET(headD);
    // RESET(headU);
    RESET(vis);
    RESET(ans);
    anss = 1;
    while(!vert.empty())vert.pop();
    // ansidx.clear();
}


void BFS1(void);
void BFS2(void);

int Ucnt(0), Dcnt(0), ucnt(0);

// int idx[310000];

int main(){
    // freopen("./in.txt", "r", stdin);
    N = read(), M = read(), s = read();
    for(int i = 1; i <= M; ++i){
        int mode = read();
        int from = read(), to = read();
        if(mode == 1){
            edgeD[++Dcnt].set(to, headD[from], 0);
            headD[from] = Dcnt;
        }
        else{
            edgeU[++Ucnt].set(to, headU[from], 1);
            headU[from] = Ucnt;
            edgeU[++Ucnt].set(from, headU[to], -1);
            headU[to] = Ucnt;
            edgeU[Ucnt].num_U = edgeU[Ucnt - 1].num_U = ++ucnt;
            // idx[++Ucnt] = ucnt;
        }
        // edge[++cnt].to = to;
        // edge[cnt].nxt = head[from];
        // edge[cnt].mode = mode;



        // edge[cnt].set(to, head[from], mode);
        // head[from] = cnt;
        // idx.insert(make_pair(i, make_pair(from, to)));
        // edge[cnt].isFrom = true;
        // if(mode == 2){
        //     swap(from, to);
        //     // edge[++cnt].to = to;
        //     // edge[cnt].nxt = head[from];
        //     // edge[cnt].mode = mode;
        //     edge[cnt].set(to, head[from], mode);
        //     head[from] = cnt;
        // }
    }
    vert.push(s);
    vis[s] = true;
    BFS1();
    printf("%d\n", anss);
    // for(int i = 1; i <= M; ++i){
    //     pair<int, int>tmp(idx.find(i)->second);
    //     auto flag = ansidx.find(make_pair(tmp.first, tmp.second));
    //     if(flag == ansidx.end() || flag->second == 1)printf("+");
    //     else printf("-");
    // }
    for(int i = 1; i <= ucnt; ++i)printf("%c", ans[i] == 1 ? '+' : '-');
    printf("\n");
    Reset();

    vert.push(s);
    vis[s] = true;
    BFS2();
    printf("%d\n", anss);
    // for(int i = 1; i <= M; ++i){
    //     pair<int, int>tmp(idx.find(i)->second);
    //     auto flag = ansidx.find(make_pair(tmp.first, tmp.second));
    //     if(flag == ansidx.end() || flag->second == 1)printf("+");
    //     else printf("-");
    // }
    for(int i = 1; i <= ucnt; ++i)printf("%c", ans[i] == 1 ? '+' : '-');
    printf("\n");
    return 0;
}
void BFS2(void){
    int len = vert.size();
    while(len--){
        int cur = vert.front();
        vert.pop();
        for(int i = headD[cur]; i; i = edgeD[i].nxt){
            int to = edgeD[i].to;
            if(!vis[to]){
                vis[to] = true;
                vert.push(to);
                ++anss;
            }
        }
        for(int i = headU[cur]; i; i = edgeU[i].nxt){
            int to = edgeU[i].to;
            if(!vis[to]){
                // vis[to] = true;
                // vert.push(to);
                // ++anss;
                ans[edgeU[i].num_U] = edgeU[i].dir * -1;
            }
        }
    }
    if(!vert.empty())BFS2();
}
// void BFS2(void){
//     int len = vert.size();
//     while(len--){
//         int cur = vert.front();
//         vert.pop();
//         for(int i = head[cur]; edge[i].nxt; i = edge[i].nxt){
//             if(used[i])continue;
//             used[i] = true;
//             if(edge[i].mode == 1){
//                 if(!vis[edge[i].to]){
//                     int from = cur, to = edge[i].to;
//                     if(!edge[i].isFrom)swap(from, to);
//                     ansidx.insert(make_pair(make_pair(from, to), -1));
//                     vis[edge[i].to] = true;
//                     ++ans;
//                     vert.push(edge[i].to);
//                 }
//             }
//         }
//     }
// }
void BFS1(void){
    int len = vert.size();
    while(len--){
        int cur = vert.front();
        vert.pop();
        for(int i = headD[cur]; i; i = edgeD[i].nxt){
            int to = edgeD[i].to;
            if(!vis[to]){
                vis[to] = true;
                vert.push(to);
                ++anss;
                // printf("DEdge[%d], from%d to%d  ans%d\n", i, cur, to, anss);
            }
        }
        for(int i = headU[cur]; i; i = edgeU[i].nxt){
            int to = edgeU[i].to;
            if(!vis[to]){
                vis[to] = true;
                vert.push(to);
                ++anss;
                ans[edgeU[i].num_U] = edgeU[i].dir * 1;
                // printf("UEdge[%d], from%d to%d  ans%d\n", i, cur, to, anss);
            }
        }
    }
    if(!vert.empty())BFS1();
}
// void BFS1(void){
//     int len = vert.size();
//     while(len--){
//         int cur = vert.front();
//         vert.pop();
//         bool flag(false);
//         for(int i = head[cur]; edge[i].nxt; i = edge[i].nxt){
//             if(used[i])continue;
//             used[i] = true;
//             if(edge[i].mode == 1){
//                 flag = true;
//                 if(!vis[edge[i].to]){
//                     vis[edge[i].to] = true;
                    
//                     ++ans;
//                     vert.push(edge[i].to);
//                 }
//             }
//         }
//         if(!flag){
//             for(int i = head[cur]; edge[i].nxt; i = edge[i].nxt){
//                 if(used[i])continue;
//                 used[i] = true;
//                 if(edge[i].mode == 2){
//                     if(!vis[edge[i].to]){
//                         int from = cur, to = edge[i].to;
//                         if(!edge[i].isFrom)swap(from, to);
//                         ansidx.insert(make_pair(make_pair(from, to), 1));
//                         vis[edge[i].to] = true;
//                         ++ans;
//                         vert.push(edge[i].to);
//                     }
//                 }
//             }
//         }
//     }
// }


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