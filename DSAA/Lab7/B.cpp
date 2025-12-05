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
    vector < string > A;
    int N = read();
    int mxlen(0);
    for(int i = 1; i <= N; ++i){
        string S; cin >> S; A.emplace_back(S);
        mxlen = max(mxlen, (int)S.length());
    }
    for(auto &s : A)s += string(mxlen - s.length(), '.');
    sort(A.begin(), A.end());
    for(const auto &s : A){
        for(auto c : s)if(c != '.')printf("%c", c);
        printf("\n");
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