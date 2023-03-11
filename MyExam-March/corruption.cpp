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

#define line(i) (lines.at(i - 1))

template < typename T = int >
inline T read(void);

int N;
int pos[50];
int status[50];
bool itsc[50][50];
int cur(0);
int ans(INT_MAX);
struct Line{int l, r;};
basic_string < Line > lines;

int main(){
    freopen("corruption.in", "r", stdin);
    freopen("corruption.out", "w", stdout);
    auto notIntersect = [](int a, int b)->bool{
        if(line(a).l > line(b).l)swap(a, b);
        switch(status[a]){
            case 1:{
                switch(status[b]){
                    case 1: return line(a).r < line(b).l || line(b).r < line(a).r;
                    case 2: return true;
                    case 3: return line(b).l > line(a).r;
                    case 4: return line(b).r > line(a).r;
                }break;
            }
            case 2:{
                switch(status[b]){
                    case 1: return true;
                    case 2: return line(a).r < line(b).l || line(b).r < line(a).r;
                    case 3: return line(b).r > line(a).r;
                    case 4: return line(b).l > line(a).r;
                }break;
            }
            case 3:{
                switch(status[b]){
                    case 1: return true;
                    case 2: return line(b).r < line(a).r || line(b).l > line(a).r;
                    case 3: return line(b).r > line(a).r;
                    case 4: return line(b).l > line(a).r;
                }break;
            }
            case 4:{
                switch(status[b]){
                    case 1: return line(b).r < line(a).r || line(b).l > line(a).r;
                    case 2: return true;
                    case 3: return line(b).l > line(a).r;
                    case 4: return line(b).r > line(a).r;
                }break;
            }
        }return false;
    };
    auto Intersect = [notIntersect](int i, int j)->bool{return !notIntersect(i, j);};//判断写反了，懒的改就写了个 notIntersect 转一下。。。。。。
    auto SetOrigin = [Intersect](void)->void{
        cur = 0;
        for(int i = 1; i <= N; ++i)for(int j = i + 1; j <= N; ++j)cur += (itsc[i][j] = itsc[j][i] = Intersect(i, j));//, printf("checking i = %d, j = %d, res = %d\n", i, j, itsc[i][j] ? 1 : 0);
        ans = min(ans, cur);
    };
    auto Anneal = [Intersect](void)->void{
        double T = 50.0, delta = 0.993;
        while(T > 1e-2){
            int idx = rndd(1, N);
            int val = rndd(1, 4);
            while(val == status[idx])val = rndd(1, 4);
            int nxt = cur;
            int lsts = status[idx]; status[idx] = val;
            for(int i = 1; i <= N; ++i)if(i != idx){
                if(itsc[idx][i] && !Intersect(idx, i))--nxt;
                else if(!itsc[idx][i] && Intersect(idx, i))++nxt;
            }
            if(nxt < cur || exp(-(double)(nxt - cur) / T) > (double)rndd(1, 114514) / 114514){
                cur = nxt;
                ans = min(ans, cur);
                for(int i = 1; i <= N; ++i)if(i != idx)itsc[idx][i] = itsc[i][idx] = Intersect(idx, i);
            }else status[idx] = lsts;
            T *= delta;
        }
    };
    int T = read();
    while(T--){
        memset(pos, 0, sizeof pos);
        memset(status, 0, sizeof status);
        lines.clear();
        ans = INT_MAX;
        N = read();
        for(int i = 1; i <= N; ++i){
            int val = read();
            if(pos[val])lines += Line{min(pos[val], i), max(pos[val], i)};
            else pos[val] = i;
        }N = lines.size();
        if(!N){printf("0\n"); continue;}
        int t = 30;
        while(t--){
            memset(itsc, 0, sizeof itsc);
            for(int i = 1; i <= N; ++i)status[i] = rndd(1, 4);
            // for(int i = 1; i <= N; ++i)printf("%d ", status[i]);
            // printf("\n");
            SetOrigin();
            Anneal();
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