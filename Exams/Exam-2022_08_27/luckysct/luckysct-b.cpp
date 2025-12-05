#define _USE_MATH_DEFINES
#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef unsigned long long unll;
typedef long double ld;
typedef unsigned int uint;
typedef __float128 f128;

#define npt nullptr
#define PI M_PI
#define E M_E

#define eps (f128)(1e-5)

template < typename T = int >
inline T read(void);

bool cmp(f128 a, f128 b){return fabsf128(a - b) <= eps;}
f128 x;
f128 ans;

#define vf vector < func > 

enum func{sinn = 1, coss, atann, out_of_range__};
vf oper;

void bfs(int q__){
    double begT = (double)clock() / CLOCKS_PER_SEC;
    queue < pair < f128, vf > > q;
    vf empt;
    q.push(make_pair((f128)0.0, empt));
    while(!q.empty()){
        auto head = q.front(); q.pop();
        // if(cmp(head.first, ans)){
        //     oper = head.second;
        //     return;
        // }
        // if((double)clock() / CLOCKS_PER_SEC >= 0.90)return;
        for(func f = sinn; f <= atann; f = func(f + 1)){

            head.second.push_back(f);
            // printf("current: %.5lf\n", (double)head.first);
            f128 tmp(0.0);
            switch(f){
                case sinn:{
                    tmp = sinf128(head.first);
                    break;
                }
                case coss:{
                    tmp = cosf128(head.first);
                    break;
                }
                case atann:{
                    tmp = atanf128(head.first);
                    break;
                }
                default:{
                    printf("error\n");
                    break;
                }
            }
            if(cmp(tmp, ans)){
                oper = head.second;
                return;
            }
            if((int)head.second.size() > q__ * 2 + 1 || (double)clock() / CLOCKS_PER_SEC - begT >= 5.00){
                printf("None");
                oper.clear();
                return;
            }
            // head.first = tmp;
            q.push(make_pair(tmp, head.second));
            head.second.pop_back();
        }
    }
}


void CAL(int p, int q){
    fprintf(stderr, "caling p=%d, q=%d\n", p, q);
    oper.clear();
    ans = sqrtf128((f128)p / (f128)q);
    // printf("%.7lf\n%.7lf\n", (double)ans, (double)(sin(atan(cos(0.0)))));
    printf("else if(p==%d&&q==%d)printf(\"", p, q);
    bfs(q);
    // reverse(oper.begin(), oper.end());
    for(auto i : oper){
        switch(i){
            case sinn:{
                printf("s");
                break;
            }
            case coss:{
                printf("c");
                break;
            }
            case atann:{
                printf("t");
                break;
            }
            default:{
                printf("error\n");
                break;
            }
        }
    }
    printf("\\n\");\n");
    // if(p % 5 == 0 || q % 5 == 0){
    //     printf("\n");
    //     // fprintf(stderr, "Complete p=%d, q=%d\n", p, q);
    //     // fflush(stderr);
    // }
    fflush(stdout);
}
bool check(int p, int q){
    for(int i = 2; i * i <= min(p, q); ++i){
        if(p % i == 0 && q % i == 0)return false;
    }
    return true;
}


int main(){
    // int p = read(), q = read();
    
    // printf("\n");
    //     fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    freopen("/home/jdoi/cpp/OI/Exams/Monkey/luckysct/build.txt", "w", stdout);
    for(int q = 10; q <= 1000; ++q){
        for(int p = 1; p <= q; ++p){
            if(check(p, q))CAL(p, q);
        }
    }



    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    T flag(1);
    char c = getchar();
    while(!isdigit(c) && c != '-')c = getchar();
    if(c == '-'){flag = -1; c = getchar();}
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}