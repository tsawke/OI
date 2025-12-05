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



template<typename T = int>
inline T read(void);



int main(){
    string S; cin >> S;
    for(int s = 1; s <= S.length(); ++s){
        int cnt = S.at(s - 1) == '(' ? 1 : -1;
        for(int t = s + 1; t <= S.length(); ++t){
            cnt += S.at(t - 1) == '(' ? 1 : -1;
            if(!cnt){
                string T = S.substr(t, S.length() - t) + S.substr(0, t);
                if(S != T){
                    cout << T << endl; return 0;
                }else{
                    printf("no\n"); return 0;
                }
            }s = t + 1;
        }
    }//printf("no\n");

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