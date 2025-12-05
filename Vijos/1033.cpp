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

class Number{
private:
    basic_string < int > nums;
public:
    Number(void){
        nums += 1;
    }
    void Print(void){
        for(auto it = nums.rbegin(); it != nums.rend(); ++it)
            printf("%d", *it);
        printf("\n");
    }
    void operator *= (const int &v){
        for(auto &d : nums)d *= v;
        for(auto it = nums.begin(); it != nums.end(); ++it)
            if(*it >= 10){
                if(next(it) != nums.end())*next(it) += *it / 10;
                else{
                    int temp = *it / 10;
                    *it %= 10;
                    nums += temp;
                    break;
                }
                *it %= 10;
            }
    }
}ans;

int main(){
    int N = read();
    if(N <= 3)printf("%d\n", N), exit(0);
    int cnt3 = N / 3 - (N % 3 == 1 ? 1 : 0), cnt2 = N % 3 == 2 ? 1 : (N % 3 == 1 ? 2 : 0);
    while(cnt3--)ans *= 3;
    while(cnt2--)ans *= 2;
    ans.Print();
    // printf("%lld\n", qpow(3, N / 3 - (N % 3 == 1 ? 1 : 0)) * qpow(2, N % 3 == 2 ? 1 : (N % 3 == 1 ? 2 : 0)));
    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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