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

#define EPS (1e-6)

template<typename T = int>
inline T read(void);

struct Point{
    double x, y;
    double angle;
    Point operator -(Point b){
        return Point{this->x - b.x, this->y - b.y};
    }
    double operator *(Point b){
        return (this->x * b.y - this->y * b.x);
    }
};

vector < Point > pts;

int main(){
    int N = read();
    for(int i = 1; i <= N; ++i){
        double x, y; cin >> x >> y;
        pts.emplace_back(Point{x, y});
    }

    auto mnp = min_element(
        pts.begin(),
        pts.end(),
        [](const Point &a, const Point &b)->bool{
            return a.x == b.x ? a.y < b.y : a.x < b.x;
        }
    );

    Point pivot = *mnp;
    pts.erase(mnp);

    for(auto &pt : pts)pt.angle = atan2(pt.y - pivot.y, pt.x - pivot.x);

    auto CalDis = [](Point a, Point b)->double{
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    };

    sort(
        pts.begin(),
        pts.end(),
        [&](const Point &a, const Point &b)->bool{
            return fabs(a.angle - b.angle) < EPS ? CalDis(a, pivot) < CalDis(b, pivot) : a.angle < b.angle;
        }
    );

    stack < Point > hull;
    hull.push(pivot);
    for(auto it = pts.begin(); it != pts.end(); advance(it, 1)){
        while(hull.size() > 1){
            auto tp = hull.top(); hull.pop();
            if((tp - hull.top()) * (*it - tp) >= 0){hull.push(tp); break;}
        }hull.push(*it);
    }

    double ans(0.0);

    auto fst = hull.top(); hull.pop();
    auto lst = fst;
    while(!hull.empty()){
        ans += CalDis(lst, hull.top());
        lst = hull.top();
        hull.pop();
    }ans += CalDis(fst, lst);

    printf("%.2lf\n", ans);

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template<typename T>
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