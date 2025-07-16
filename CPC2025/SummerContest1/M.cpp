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

#define EPS (1e-4)
#define EQUAL(a, b) (fabs((a) - (b)) <= EPS)

template<typename T = int>
inline T read(void);

int d;

bool Check(basic_string < double > cur){
    if(cur.size() == 1)return EQUAL(*cur.begin(), (double)d);
    for(auto it1 = cur.begin(); it1 != prev(cur.end()); ++it1){
        for(auto it2 = next(it1); it2 != cur.end(); ++it2){
            basic_string < double > nxt;
            for(auto it = cur.begin(); it != cur.end(); ++it){
                if(it != it1 && it != it2)nxt += *it;
                if(EQUAL(*it, (double)d))return true;
            }
            double A = *it1, B = *it2;
            basic_string < double > vals = {A + B, A - B, B - A, A * B};
            if(!EQUAL(A, 0))vals += B / A;
            if(!EQUAL(B, 0))vals += A / B;
            for(auto v : vals){
                nxt += v;
                if(Check(nxt))return true;
                nxt.pop_back();
            }
        }
    }return false;
}

int main(){
    d = read();
    for(int i = 1; i <= 100; ++i){
        for(int j = i + 1; j <= 100; ++j){
            for(int k = j + 1; k <= 100; ++k){
                if(i == d || j == d || k == d)continue;
                basic_string < double > cur = {(double)i, (double)j, (double)k};
                if(!Check(cur)){
                    printf("%d %d %d\n", i, j, k);
                    return 0;
                }
            }
        }
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