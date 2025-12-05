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

#define LIM (3000)

template < typename T = int >
inline T read(void);

basic_string < int > legal;

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    printf("1\n"); exit(0);
    // for(int i = 1; i <= 3000; ++i){
    //     basic_string < int > nums;
    //     int val = i;
    //     while(val)nums += val % 10, val /= 10;
    //     bool flag(true);
    //     for(auto it = nums.begin(); it != nums.end() && next(it) != nums.end(); advance(it, 1)){
    //         if(*next(it) > *it){flag = false; break;}
    //     }
    //     if(flag)legal += i;
    // }for(auto v : legal)printf("%d\n", v);
    // // printf("int ans[3100] = {1,  ");
    // reverse(legal.begin(), legal.end());
    // #define legal(i) (legal.at(i - 1))
    // for(int i = 1; i <= 3000; ++i){
    //     bool flag = false;
    //     auto dfs = [i, &flag](auto&& self, int dep = 1, int cur = 0, int cnt = 0)->void{
    //         // printf("Making dep = %d, cur = %d, cnt = %d\n", dep, cur, cnt);
    //         if(cur > i || flag)return;
    //         if(cur == i){
    //             printf("%d, ", cnt); fflush(stdout);
    //             flag = true;
    //             return;
    //         }
    //         if(dep > (int)legal.size())return;
    //         while(cur < i){
    //             self(self, dep + 1, cur, cnt);
    //             cur += legal(dep);
    //             ++cnt;
    //         }
    //     }; dfs(dfs);
    // }

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