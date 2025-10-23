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

template < typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    int val;
};

int main(){
    int T = read();
    while(T--){
        ll A = read < ll >(); int B = read(); ll C = read < ll >();
        int base(1); while(base <= B)base <<= 1;
        vector < Edge* > head(base << 1, nullptr);
        vector < ll > dis(base << 1, LLONG_MAX >> 2);
        for(int i = 0; i < base; ++i){
            head[i] = new Edge{head[i], i ^ B, 0};
            head[i] = new Edge{head[i], (i + B) % base, (i + B) >= base ? 1 : 0};
        }
        auto BFS = [&](void)->void{
            deque < int > cur;
            dis[A % base] = A / base;
            cur.push_back(A % base);
            while(!cur.empty()){
                int p = cur.front(); cur.pop_front();
                for(auto i = head[p]; i; i = i->nxt)
                    if(dis[i->to] > dis[p] + i->val){
                        dis[i->to] = dis[p] + i->val;
                        i->val ? cur.push_back(i->to) : cur.push_front(i->to);
                    }
            }
        }; BFS();
        printf("%s\n", dis[C % base] <= C / base ? "YES" : "NO");
    }

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template < typename T >
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