#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

using ll = long long;
using unll = unsigned long long;
using uint = unsigned int;
using ld = long double;

template < typename T = int >
inline T read(void);



int main(){
    int T = read();
    while(T--){
        int N = read();
        stack < int > cur;
        while(N--){
            char c = getchar();
            int val(0);
            bool isd(false);
            while(!isdigit(c) && c != '+' && c != '-' && c != '*')c = getchar();
            while(isdigit(c))isd = true, val = (val * 10) + int(c - '0'), c = getchar();
            if(isd)cur.push(val);
            else{
                int v1 = cur.top(); cur.pop();
                int v2 = cur.top(); cur.pop();
                cur.push(c == '+' ? (v1 + v2) : (c == '-' ? (v2 - v1) : v1 * v2));
            }
        }printf("%d\n", cur.top());
    }

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template < typename T >
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