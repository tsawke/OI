#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr

******************************/

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template<typename T = int>
inline T read(void);



int main(){
    freopen("out.txt", "w", stdout);
    printf("int arr[110000] = {");
    int cnt(0);
    int ht = 12, mt = 0;
    int len(0);
    bool flag(false);
    while(true){
        int a1 = ht / 10, a2 = ht % 10, a3 = mt / 10, a4 = mt % 10;
        if(
            (!a1 && a3 - a2 == a4 - a3) ||
            (a1 && a2 - a1 == a3 - a2 && a4 - a3 == a3 - a2)
        )++cnt;
        printf("%d,", cnt);
        ++mt;
        ++len;
        if(mt > 59)mt = 0, ++ht;
        if(ht > 12){
            ht = 1;
            if(!flag){
                flag = true;
            }else{
                printf("};\n\n\n%d\n", len);
                return 0;
            }
        }
        if(mt == 50)printf("\n");
    }

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