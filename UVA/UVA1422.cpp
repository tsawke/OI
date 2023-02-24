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

struct Task{
    int s, t;
    int w;
    friend const bool operator < (const Task &a, const Task &b){
        return a.t > b.t;
    }
}task[21000];

bool Check(int V){
    int curpos(1);
    priority_queue < Task > tsk;
    for(int i = 1; i <= 20000; ++i){
        while(curpos <= N && i >= task[curpos].s)tsk.push(task[curpos++]);
        int tot(V);
        while(!tsk.empty() && tot){
            if(i >= tsk.top().t)return false;
            // printf("i = %d, Making [%d, %d]\n", )
            if(tot >= tsk.top().w)tot -= tsk.top().w, tsk.pop();
            else{
                auto tp = tsk.top(); tsk.pop();
                tp.w -= tot; tot = 0; tsk.push(tp);
                break;
            }
        }
    }if(curpos <= N || !tsk.empty())return false;
    return true;
}

int main(){
    int T = read();
    while(T--){
        N = read();
        for(int i = 1; i <= N; ++i)task[i].s = read(), task[i].t = read(), task[i].w = read();
        sort(task + 1, task + N + 1, [](const Task &a, const Task &b)->bool{return a.s < b.s;});
        int l = 0, r = 21000000, ans(-1);
        while(l <= r){
            int mid = (l + r) >> 1;
            if(Check(mid))ans = mid, r = mid - 1;
            else l = mid + 1;
        }printf("%d\n", ans);
    }
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