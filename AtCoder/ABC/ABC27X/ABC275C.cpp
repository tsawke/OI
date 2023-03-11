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

#define tot(i) (cur.at(i - 1))
#define tott(i) (tot.at(i - 1))
#define EPS (1e-6)

template < typename T = int >
inline T read(void);

struct Point{int x, y;};
bitset < 100 > vis;
basic_string < Point > pts;
basic_string < Point > cur;
int ans(0);

int dis(Point a, Point b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
double K(Point a, Point b){
    return (double)(a.y - b.y) / (a.x - b.x);
}

void dfs(int dep = 1){
    if(dep > 4){
        // auto tot = cur;
        // sort(tot.begin(), tot.end(), [](const Point &a, const Point &b)->bool{return a.x == b.x ? a.y < b.y : a.x < b.x;});
        // if(tot(1).x == tot(2).x && tot(1).y == tot(3).y && tot(2).y == tot(4).y && tot(3).x == tot(4).x && tot(2).y - tot(1).y == tot(3).x - tot(1).x)++ans;
        if(
            dis(tot(1), tot(2)) == dis(tot(2), tot(3)) &&
            dis(tot(2), tot(3)) == dis(tot(3), tot(4)) &&
            dis(tot(3), tot(4)) == dis(tot(4), tot(1)) &&
            dis(tot(4), tot(1)) == dis(tot(1), tot(2)) &&
            (
                (
                    fabs(-1.0 - K(tot(1), tot(2)) * K(tot(2), tot(3))) < EPS &&
                    fabs(-1.0 - K(tot(2), tot(3)) * K(tot(3), tot(4))) < EPS &&
                    fabs(-1.0 - K(tot(3), tot(4)) * K(tot(4), tot(1))) < EPS
                ) ||
                (
                    (tot(1).x == tot(2).x && tot(1).y == tot(4).y && tot(2).y == tot(3).y && tot(4).x == tot(3).x) ||
                    (tot(1).y == tot(2).y && tot(1).x == tot(4).x && tot(2).x == tot(3).x && tot(4).y == tot(3).y)
                )
            )
            
        )
        // {
        //     auto tot = cur;
        //     sort(tot.begin(), tot.end(), [](const Point &a, const Point &b)->bool{return a.x == b.x ? a.y < b.y : a.x < b.x;});
        //     if(!(((tott(1).x <= tott(2).x && tott(2).x <= tott(3).x) || (tott(2).x <= tott(3).x && tott(3).x <= tott(4).x)) ||
        //     ((tott(1).y <= tott(2).y && tott(2).y <= tott(3).y) || (tott(2).y <= tott(3).y && tott(3).y <= tott(4).y))))++ans;
        // }
            ++ans;
        return;
    }
    for(int i = 1; i <= (int)pts.size(); ++i){
        if(vis[i])continue;
        vis[i] = true, cur += pts.at(i - 1);
        dfs(dep + 1);
        vis[i] = false, cur.pop_back();
    }
}

int main(){
    for(int i = 1; i <= 9; ++i)
        for(int j = 1; j <= 9; ++j){
            char c = getchar(); while(c != '.' && c != '#')c = getchar();
            if(c == '#')pts += Point{i, j};
        }
    dfs();
    printf("%d\n", ans / 8);
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