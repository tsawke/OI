#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define EPS (1e-3)

using namespace std;

typedef long long ll;
typedef unsigned long long unll;

template < typename T = int >
inline T read(void);

double a, b, c, d;
double x1, x2, x3;

basic_string < double > ans;

int main(){
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    auto equal = [](double a, double b) -> bool{
        return fabs(a - b) <= EPS;
    };

    auto func = [](double x) -> double{
        return pow(x, 3.0) * a + pow(x, 2.0) * b + x * c + d;
    };

    for(int l = -100; l <= 100; ++l){
        int r = l + 1;
        double ll = l, rr = r;
        double mid = (ll + rr) / 2.0;
        // printf("func l = %.2lf, r = %.2lf\n", func(ll), func(rr));
        if(equal(func(ll), 0.0))ans += ll;
        else if(equal(func(rr), 0.0))ans += rr, ++l;
        else if(func(ll) * func(rr) < 0){
            // printf("%d %d\n", l, r);
            while(ll < rr && !equal(ll, rr)){
                mid = (ll + rr) / 2.0;
                // printf("%.2lf %.2lf %.2lf %.2lf %.2lf %.2lf\n", ll, mid, rr, func(ll), func(mid), func(rr));
                if(func(ll) * func(mid) <= 0)rr = mid - EPS;
                else if(func(rr) * func(mid) <= 0)ll = mid + EPS;
                else break;
                
            }
            // if(equal(func(ll), 0.0))
            ans += ll;
        }
    }
    sort(ans.begin(), ans.end());
    for(auto v : ans)printf("%.2lf%c", v, v == ans.back() ? '\n' : ' ');

    return 0;
}

template < typename T >
inline T read(void) {
    T ret(0);
    short flag(1);
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