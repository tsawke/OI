#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

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

int Check(void){
    int val = read();
    bool beg(false);
    basic_string < bool > nums;
    while(val)nums += val & 1, val >>= 1;
    for(int i = 1; i < (int)nums.size(); ++i){
        // printf("i is %d, beg = %d\n", nums.at(i - 1), beg ? 1 : 0);
        if(!beg){
            if(nums.at(i - 1)){
                if(nums.at(i))continue;
                else beg = true, ++i;
            }else return -1;
        }else{
            if(nums.at(i - 1)){
                if(!nums.at(i))++i;
                else ++i;
            }else{
                // if(!nums.at(i - 2)){beg = false; continue;}
                if(!nums.at(i))return -1;
                else beg = false;
            }
        }
    }
    return (int)nums.size();
}

int main(){
    // freopen("out.txt", "w", stdout);
    int T = read();
    while(T--){
        printf("%d\n", Check());
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