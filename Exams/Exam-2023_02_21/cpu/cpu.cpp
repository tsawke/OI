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

#define EPS (1e-9)
/*
3
5
1 4 2
3 6 3
4 5 2
4 7 2
5 8 1
6
1 7 25
4 8 10
7 10 5
8 11 5
10 13 10
11 13 5
8
15 18 10
20 24 16
8 15 33
11 14 14
1 6 16
16 19 12
3 5 12
22 25 10
*/

template < typename T = int >
inline T read(void);

int N;

struct Task{
    ld s, t;
    ld w;
    friend const bool operator < (const Task &a, const Task &b){
        return a.t > b.t;
    }
}task[21000];

// class SegTree{
// private:
//     int tr[21000000 << 2], lz[]
// public:
//     void Pushup(int p){

//     }
// }

bool Check(int V){
    int curpos(1);
    priority_queue < Task > tsk;
    ld curT(1.0);
    while(true){
        if(tsk.empty()){
            if(curpos > N)return true;
            curT = max(curT, (ld)task[curpos].s);
            while(curpos <= N && curT >= (ld)task[curpos].s)tsk.push(task[curpos++]);
        }
        
        auto tp = tsk.top(); tsk.pop();
        curT = max(curT, (ld)tp.s);
        auto nxt = tsk.empty() ? Task{INT_MAX, INT_MAX, INT_MAX} : tsk.top();
        if(curT + (ld)tp.w / (ld)V <= nxt.s){
            curT += (ld)tp.w / (ld)V;
            if(curT - EPS > (ld)tp.t)return false;
        }else{
            tsk.push(Task{nxt.s, tp.t, tp.w - (nxt.s - curT) * V});
            curT = nxt.s;
        }
        
        // printf("V = %d, curT = %.5Lf,  [%d ~ %d]\n", V, curT, tp.s, tp.t);
        
        while(curpos <= N && curT >= (ld)task[curpos].s)tsk.push(task[curpos++]);
    }
}

int main(){
    freopen("cpu.in", "r", stdin);
    freopen("cpu.out", "w", stdout);
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