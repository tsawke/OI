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
struct Node{
    ll val, add;
    ll times;
    friend const bool operator < (const Node &a, const Node &b){
        return a.times > b.times;
    }
};
basic_string < Node > posi;
priority_queue < Node > neg;

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i){
        ll val = read();
        ll times = ll(ceil(-(ld)val / i));
        if(val >= N || times > M)continue;
        if(val >= 0)posi += Node{val, i, -1};
        else neg.push(Node{val, i, times});
    }
    int cur(0);
    while(!neg.empty()){
        auto tp = neg.top(); neg.pop();
        // printf("top val = %lld, add = %lld, times = %lld\n", tp.val, tp.add, tp.times);
        for(int i = cur + 1; i <= tp.times - 1; ++i)printf("0\n");
        for(auto &p : posi)p.val += p.add * (tp.times - cur);
        cur = tp.times;
        posi += Node{tp.val + tp.add * tp.times, tp.add, -1};
        while(!neg.empty() && neg.top().times == tp.times)
            posi += Node{neg.top().val + neg.top().add * neg.top().times, neg.top().add, -1}, neg.pop();
        sort(posi.begin(), posi.end(), [](const Node &a, const Node &b)->bool{return a.val < b.val;});
        // printf("posi: ");
        // for(auto v : posi)printf("%lld ", v.val);
        // printf("\n");
        while(!posi.empty() && posi.back().val >= N)posi.pop_back();
        for(int i = 0, curr = 0; true; ++i, ++curr){
            while((int)posi.size() - 1 >= i && posi.at(i).val < curr)++i;
            if((int)posi.size() - 1 < i || posi.at(i).val != curr){printf("%d\n", curr); break;}
        }
    }for(int i = cur + 1; i <= M; ++i)printf("0\n");

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