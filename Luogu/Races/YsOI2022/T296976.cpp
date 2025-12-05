#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

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

int exgcd(int a, int b, int &x, int &y){
    if(!b)return x = 1, y = 0, a;
    int d = exgcd(b, a % b, x, y);
    int tmp = x;
    x = y;
    y = tmp - a / b * y;
    return d;
}

int N;

int main(){
    N = read();
    for(int i = 1; i <= N; ++i){
        // int c = read() * 6;
        int c = read();
        if(i == 1){
            printf("400 600\n"); continue;
        }
        // int a = 15, b = 10, x, y;
        // int d = exgcd(a, b, x, y);
        // int tb = b / d;
        // x = (x % tb + tb) % tb;
        // y = (d - a * x) / b;
        // printf("%d %d\n", x, y);
        // int x, y;
        // int mul = c / 25;
        // x = y = mul;
        // int p = c % 25;
        // if(p >= 15)++x, p -= 15;
        // if(p >= 10)++y, p -= 10;
        // if(3 <= p && p < 9)++x, --y;
        // if(p == 9)x += 2, y -= 2;
        int x, y;
        if(c <= 1000){
            x = c / 5 * 2, y = 0;
            if(c % 5){
                int p = c % 5;
                switch(p){
                    case 1:{--x, y += 2; break;}
                    case 2:{++y; break;}
                    case 3:{++x; break;}
                    case 4:{++x, ++y; break;}
                }
            }
        }else{
            c -= 1000;
            x = 400, y = c / 5 * 3;
            if(c % 5){
                int p = c % 5;
                switch(p){
                    case 1:{--x, y += 2; break;}
                    case 2:{++y; break;}
                    case 3:{y += 2; break;}
                    case 4:{--x, y += 4; break;}
                }
            }
        }

        // int mul = c / 5;
        // x *= mul, y *= mul;
        // int e = c % 5;
        // switch(e){
        //     case 1:{
        //         if(y > 0 && x < 400)++x, --y;
        //         else --x, y += 2;
        //         break;
        //     }
        //     case 2:{++y; break;}
        //     case 3:{++x; break;}
        //     case 4:{++x, ++y; break;}
        // }
        printf("%d %d\n", x, y);
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