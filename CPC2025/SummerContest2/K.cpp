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
typedef long double ld;

#define EPS (1e-6)

#define int ll

template<typename T = int>
inline T read(void);

double Query(int x1, int y1, int x2, int y2){
    printf("query %d %d %d %d\n", x1, y1, x2, y2);
    fflush(stdout);
    double ret; scanf("%lf", &ret);
    return ret;
}

double x, y, r;

signed main(){
    for(int i = 0; i <= 100000; i += 199){
        double d1 = Query(i, 0, i, 100000);
        if(d1 > EPS){
            int x1 = i, x2 = i + 1;//i == 100000 ? (i - 1) : (i + 1);
            double d2 = Query(i + 1, 0, i + 1, 100000);//i == 100000 ? Query(i - 1, 0, i - 1, 100000) : Query(i + 1, 0, i + 1, 100000);
            if(d2 <= EPS)d2 = Query(i - 1, 0, i - 1, 100000), x2 = i - 1;
            if(d1 < d2)swap(d1, d2), swap(x1, x2);
            d1 /= 2.0, d2 /= 2.0;
            double d = (double)((double)x2 * x2 - 2.0 * x1 * x2 + x1 * x1 - d2 * d2 + d1 * d1) / (2 * x2 - 2 * x1);
            x = (double)x2 - d;
            // if((int)round(x) == 0){printf("answer 1145 1145 114514\n"), fflush(stdout); return 0;}
            r = sqrt(d * d + d2 * d2);
            break;
        }
    }
    for(int i = 0; i <= 100000; i += 199){
        double d1 = Query(0, i, 100000, i);
        if(d1 > EPS){
            int x1 = i, x2 = i + 1;
            double d2 = Query(0, i + 1, 100000, i + 1);
            if(d2 <= EPS)d2 = Query(0, i - 1, 100000, i - 1), x2 = i - 1;
            if(d1 < d2)swap(d1, d2), swap(x1, x2);
            d1 /= 2.0, d2 /= 2.0;
            double d = (double)((double)x2 * x2 - 2.0 * x1 * x2 + x1 * x1 - d2 * d2 + d1 * d1) / (2 * x2 - 2 * x1);
            y = (double)x2 - d;
            // r = sqrt(d * d + d2 * d2);
            break;
        }
    }
    // if((int)round(x) == 0){printf("answer 114 114514 114514\n"), fflush(stdout); return 0;}
    printf("answer %d %d %d\n", (int)round(x), (int)round(y), (int)round(r));
    fflush(stdout);

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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