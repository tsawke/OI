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

int K;
bitset < 110000 > vis;
int dis[110000];

void bfs(void){
    memset(dis, 0x3f, sizeof dis);
    deque < int > cur;
    vis[1] = true, dis[1] = 1;
    cur.push_front(1);
    while(!cur.empty()){
        int p = cur.front(); cur.pop_front();
        if(auto val = p * 10 % K; !vis[val]){
            vis[val] = true;
            dis[val] = min(dis[val], dis[p]);
            cur.push_front(val);
        }
        if(auto val = (p + 1) % K; !vis[val]){
            dis[val] = min(dis[val], dis[p] + 1);
            cur.push_back(val);
        }
    }
}

int main(){
    K = read();
    bfs();
    printf("%d\n", dis[0]);
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