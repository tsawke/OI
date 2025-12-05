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

#define idx(x, y) ((x - 1) * M + y)
#define pos(p) ({p / M + 1, p % M})
#define posX(p) (p / M + 1)
#define posY(p) (p % M)

template < typename T = int >
inline T read(void);

int N, M, Q;
struct Edge{
    Edge* nxt;
    int to;
    int val;
    OPNEW;
}ed[110000];
ROPNEW;
Edge* head[21000];

struct Query{int idx; int s, t; int sx, sy, tx, ty;};
basic_string < Query > qs;
int nxtL[21000], nxtR[21000];

unordered_map < int, int > pdis[21000];
bitset < 21000 > vis[21000];
int ans[110000];

int main(){
    freopen("rin.in", "r", stdin);
    freopen("rin.out", "w", stdout);
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M - 1; ++j){
            int val = read();
            int s = idx(i, j), t = idx(i, j + 1);
            nxtR[idx(i, j)] = val;
            head[s] = new Edge{head[s], t, val};
            head[t] = new Edge{head[t], s, val};
        }
    for(int i = 1; i <= N - 1; ++i)
        for(int j = 1; j <= M; ++j){
            int val = read();
            nxtL[idx(i, j)] = val;
            int s = idx(i, j), t = idx(i + 1, j);
            head[s] = new Edge{head[s], t, val};
            head[t] = new Edge{head[t], s, val};
        }
    Q = read();
    // for(int i = 1; i <= Q; ++i){
    //     int sx = read(), sy = read(), tx = read(), ty = read();
    //     qs += Query{i, idx(sx, sy), idx(tx, ty), sx, sy, tx, ty};
    //     // if(sx + sy > tx + ty)swap(sx, tx), swap(sy, ty);
    //     // int s = idx(sx, sy), t = idx(tx, ty);
    //     // if(s > t)swap(s, t), swap(sx, tx), swap(sy, ty);
    //     // qs += Query{i, s, t, sx, sy, tx, ty};
    // }//sort(qs.begin(), qs.end(), [](const Query &a, const Query &b)->bool{return a.sx + a.sy > b.sx + b.sy;});
    auto Dijkstra = [](int S, int T)->void{
        static priority_queue < pair < int, int >, vector < pair < int, int > >, greater < pair < int, int > > > cur; while(!cur.empty())cur.pop();
        pdis[S][S] = 0, cur.push({pdis[S][S], S});
        while(!cur.empty()){
            int p = cur.top().second; cur.pop();
            if(vis[S][p])continue;
            vis[S][p] = true;
            for(auto i = head[p]; i; i = i->nxt)
                if(pdis[S].find(SON) == pdis[S].end() || pdis[S][p] + i->val < pdis[S][SON])
                    pdis[S][SON] = pdis[S][p] + i->val, cur.push({pdis[S][SON], SON});
        }
    };
    for(int i = 1; i <= Q; ++i){
        int sx = read(), sy = read(), tx = read(), ty = read();
        Dijkstra(idx(sx, sy), idx(tx, ty));
        printf("%d\n", pdis[idx(sx, sy)][idx(tx, ty)]);
        // qs += Query{i, idx(sx, sy), idx(tx, ty), sx, sy, tx, ty};
    }
    // auto Make = [](auto&& self, basic_string < Query > curQ, unordered_set < int > pts, int lx = 1, int rx = N, int ly = 1, int ry = M)->void{
    //     printf("Making %d~%d, %d~%d\n", lx, rx, ly, ry);
    //     int sizx = rx - lx + 1, sizy = ry - ly + 1;
    //     if(!sizx || !sizy)return;
    //     if(sizx == 1 && sizy == 1){
    //         pdis[idx(lx, ly)][idx(lx, ly)] = 0;
    //         return;
    //     }
    //     if(sizx == 2 && sizy == 1){
    //         pdis[idx(lx, ly)][idx(lx, ly)] = pdis[idx(rx, ly)][idx(rx, ly)] = 0;
    //         pdis[idx(lx, ly)][idx(rx, ly)] = pdis[idx(rx, ly)][idx(lx, ly)] = nxtL[idx(lx, ly)];
    //         return;
    //     }
    //     if(sizx == 1 && sizy == 2){
    //         pdis[idx(lx, ly)][idx(lx, ly)] = pdis[idx(lx, ry)][idx(lx, ry)] = 0;
    //         pdis[idx(lx, ly)][idx(lx, ry)] = pdis[idx(lx, ry)][idx(lx, ly)] = nxtR[idx(lx, ly)];
    //         return;
    //     }
    //     if(sizx == 2 && sizy == 2){
    //         pdis[idx(lx, ly)][idx(lx, ly)] = pdis[idx(lx, ry)][idx(lx, ry)] = pdis[idx(rx, ly)][idx(rx, ly)] = pdis[idx(rx, ry)][idx(rx, ry)] = 0;
    //         int p1 = idx(lx, ly), p2 = idx(lx, ry), p3 = idx(rx, ly), p4 = idx(rx, ry);
    //         pdis[p1][p2] = min()
    //     }
    //     if(sizx > sizy){
    //         int len = (sizx >> 1) + 1;
    //         int mid = lx + len - 1;
    //         basic_string < Query > lq, rq, lftq;
    //         unordered_set < int > ls, rs;
    //         for(auto q : curQ){
    //             if(q.sx <= mid || q.tx <= mid){
    //                 lq += q;
    //                     if(q.sx <= mid)ls.insert(q.s);
    //                     if(q.tx <= mid)ls.insert(q.t);
    //             }
    //             if(q.sx >= mid || q.tx >= mid){
    //                 rq += q;
    //                 if(q.sx >= mid)rs.insert(q.s);
    //                     if(q.tx >= mid)rs.insert(q.t);
    //             }
    //             if((q.sx <= mid && q.tx > mid) || (q.sx < mid && q.tx >= mid) || (q.sx >= mid && q.tx < mid) || (q.sx > mid && q.tx <= mid))lftq += q;
    //         }
    //         for(auto p : ls){
    //             for(int y = ly; y <= ry; ++y)lq += Query{0, p, idx(mid, y), posX(p), posY(p), mid, y};
    //         }
    //         for(auto p : rs){
    //             for(int y = ly; y <= ry; ++y)rq += Query{0, p, idx(mid, y), posX(p), posY(p), mid, y};
    //         }
    //         self(self, lq, ls, lx, mid, ly, ry);
    //         self(self, rq, rs, mid, rx, ly, ry);
    //         for(auto q : lftq){
    //             int s = q.s, t = q.t;
    //             int cans(numeric_limits < int >::max());
    //             for(int y = ly; y <= ry; ++y){
    //                 cans = min(cans, pdis[s][idx(mid, y)] + pdis[t][idx(mid, y)]);
    //             }pdis[s][t] = ans[q.idx] = cans;
    //         }

    //     }else{
    //         int len = (sizy >> 1) + 1;
    //         int mid = ly + len - 1;
    //         basic_string < Query > lq, rq, lftq;
    //         unordered_set < int > ls, rs;
    //         for(auto q : curQ){
    //             if(q.sy <= mid || q.ty <= mid){
    //                 lq += q;
    //                     if(q.sy <= mid)ls.insert(q.s);
    //                     if(q.ty <= mid)ls.insert(q.t);
    //             }
    //             if(q.sy >= mid || q.ty >= mid){
    //                 rq += q;
    //                 if(q.sy >= mid)rs.insert(q.s);
    //                     if(q.ty >= mid)rs.insert(q.t);
    //             }
    //             if((q.sy <= mid && q.ty > mid) || (q.sy < mid && q.ty >= mid) || (q.sy >= mid && q.ty < mid) || (q.sy > mid && q.ty <= mid))lftq += q;
    //         }
    //         for(auto p : ls){
    //             for(int x = lx; x <= rx; ++x)lq += Query{0, p, idx(x, mid), posX(p), posY(p), x, mid};
    //         }
    //         for(auto p : rs){
    //             for(int x = lx; x <= rx; ++x)rq += Query{0, p, idx(x, mid), posX(p), posY(p), x, mid};
    //         }
    //         self(self, lq, ls, lx, rx, ly, mid);
    //         self(self, rq, rs, lx, rx, mid, ry);
    //         for(auto q : lftq){
    //             int s = q.s, t = q.t;
    //             int cans(numeric_limits < int >::max());
    //             for(int x = lx; x <= rx; ++x){
    //                 cans = min(cans, pdis[s][idx(x, mid)] + pdis[t][idx(x, mid)]);
    //             }pdis[s][t] = cans;
    //         }
    //     }
    // };
    // unordered_set < int > pts;
    // for(auto q : qs)pts.insert(q.s), pts.insert(q.t);
    // Make(Make, qs, pts);







    
    // for(auto q : qs){
    //     // printf("Query : %d -> %d, (%d, %d), (%d, %d), idx = %d\n", q.s, q.t, q.sx, q.sy, q.tx, q.ty, q.idx);
    //     // Dijkstra(q.s, q.t);
    //     ans[q.idx] = pdis[q.s][q.t];
    // }
    // for(int i = 1; i <= Q; ++i)printf("%d\n", ans[i]);
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
/*
2 2
2
3
6 4
2
1 1 2 2
1 2 2 1
*/