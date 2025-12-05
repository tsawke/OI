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

int N, M;
struct Node{int val, pos;};
basic_string < Node > line[1100000];
queue < Node > rval[1100000];
// basic_string < Node > rval[1100000];

struct Pair{int x, y;};
basic_string < Pair > lines;

int cnt[1100000];
int curdep[1100000];
// basic_string < int > eend;
queue < int > eend;
int cnt_end(0);
bitset < 1100000 > vis;
basic_string < int > row[1100000];
multiset < int > all_exist;

int main(){
    // freopen("000.txt", "r", stdin);
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            line[i] += {read(), j};
    for(int i = 1; i <= N; ++i)sort(line[i].begin(), line[i].end(), [](const Node &a, const Node &b)->bool{return a.val < b.val;});
    for(int i = 1; i <= N; ++i){
        auto it = line[i].begin();
        while(it != line[i].end() && !it->val)advance(it, 1);
        if(it != line[i].end())lines += Pair{it->val, line[i].back().val};
    }sort(lines.begin(), lines.end(), [](const Pair &a, const Pair &b)->bool{return a.x == b.x ? a.y < b.y : a.x < b.x;});
    for(auto it = lines.begin(); it != lines.end() && next(it) != lines.end(); advance(it, 1))
        if(it->y > next(it)->x)printf("No\n"), exit(0);
    // for(int i = 1; i <= N; ++i)
        // for(auto v : line[i])if(!v.val)++cnt[v.pos]; else 
    for(int i = 1; i <= N; ++i)
        for(auto v : line[i])if(!v.val)row[v.pos] += -1;/*++cnt[v.pos];*/ else rval[i].push(v);//rval[i] += v;//rval[i].push(v);
    for(int i = 1; i <= N; ++i){
        int lst(-1);
        while(!rval[i].empty() && (!~lst || rval[i].front().val == lst))
            row[rval[i].front().pos] += i, all_exist.insert(i), lst = rval[i].front().val, rval[i].pop();//++cnt[rval[i].front().]
    }
    for(int i = 1; i <= M; ++i)if((int)row[i].size() == N)eend.push(i);//eend += i; //if(cnt[i] == N)++cnt_end;//eend += i;
    for(int m = 1; m <= M; ++m){
        // printf("m = %d\n", m);
        if(eend.empty())printf("No\n"), exit(0);
        int rw = eend.front(); eend.pop();//eend.pop_back();
        for(auto v : row[rw]){
            if(!~v)continue;
            all_exist.erase(all_exist.find(v));
            if(!all_exist.count(v)){
                int lst(-1);
                while(!rval[v].empty() && (!~lst || rval[v].front().val == lst)){
                    row[rval[v].front().pos] += v, all_exist.insert(v); lst = rval[v].front().val;
                    if((int)row[rval[v].front().pos].size() == N)eend.push(rval[v].front().pos);//eend += rval[v].front().pos;
                    rval[v].pop();
                }
            }
        }

        // for(int i = 1; i <= N; ++i){
        //     while(curdep[i] < m && curdep[i] + 1 <= (int)rval[i].size()){
        //         // cnt[rval[i].front().pos]++;
        //         cnt[rval[i].at(curdep[i]++).pos]++;
        //         if(cnt[rval[i].at(curdep[i] - 1).pos] == N)++cnt_end;//eend += rval[i].front().pos;

        //     }
        //     while(curdep[i] + 1 <= (int)rval[i].size() && curdep[i] + 1 <= M && rval[i].at(curdep[i] + 1 - 1).val == rval[i].at(curdep[i] + 1 - 2).val){
        //         cnt[rval[i].at(curdep[i]++).pos]++;
        //         if(cnt[rval[i].at(curdep[i] - 1).pos] == N)++cnt_end;//eend += rval[i].front().pos;
        //     }
        //     // int lst(-1);
        //     // while(!rval[i].empty() && (!~lst || rval[i].front().val == lst)){
               
                
        //     //     lst = rval[i].front().val, rval[i].pop();
        //     // }
        // }
        // if(!cnt_end)printf("No\n"), exit(0);
        // --cnt_end;
        // // if(eend.empty())printf("No\n"), exit(0);
        // // eend.pop_back();
    }printf("Yes\n");
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