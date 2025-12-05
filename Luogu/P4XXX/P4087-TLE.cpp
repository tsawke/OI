#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template< typename T = int >
inline T read(void);

int N, G;
ll cur[110000];
struct Node{
    int date, num, delt;
    friend const bool operator < (const Node &x, const Node &y){return x.date < y.date;}
};
vector < Node > notes;
vector < ll > milk;
set < int > vals;
int main(){
    freopen("P4087_5.in", "r", stdin);
    N = read(), G = read();
    for(int i = 1; i <= N; ++i){
        int d = read(), n = read(), del = read();
        if(del == 0){--N, --i; continue;}
        notes.emplace_back(Node{d, n, del});
        milk.emplace_back(G);
        cur[i] = G;
        vals.insert(n);
    }sort(notes.begin(), notes.end());
    milk.emplace_back(G);
    int cnt(0);
    for(auto &x : notes)x.num = distance(vals.begin(), vals.upper_bound(x.num));
    // printf("sorted:\n");
    // for(auto x : notes){
    //     printf("%d %d %d\n", x.date, x.num, x.delt);
    // }int times(0);/////////////////////
    for(auto &x : notes){
        // x.num = distance(vals.begin(), vals.upper_bound(x.num));
        bool mvbst(false), insbst(false), mulbst(false);
        if(cur[x.num] == milk.back())mvbst = true;
        if((int)milk.size() >= 2 && milk.back() == *(milk.end() - 2))mulbst = true;
        milk.erase(lower_bound(milk.begin(), milk.end(), cur[x.num]));
        cur[x.num] += x.delt;
        if(cur[x.num] >= milk.back())insbst = true;
        milk.insert(upper_bound(milk.begin(), milk.end(), cur[x.num]), cur[x.num]);
        if((int)milk.size() >= 2 && milk.back() == *(milk.end() - 2))mulbst = true;
        if((mvbst && !insbst) || (!mvbst && insbst) || (mvbst && insbst && mulbst))++cnt;
        // printf("No.%d  ", ++times);
        // for(auto m : milk)printf("%d ", m);
        // puts("");printf("cnt:%d\n", cnt);
    }printf("%d\n", cnt);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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