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
    int T = read();
    while(T--){
        string S; cin >> S;
        int len = S.length();
        bool flag(false);
        for(int L = len >> 1; L >= 1; --L){
            if(flag)break;
            if(L == 1){
                printf("%c\n", S.at(0));
                break;
            }
            for(int s = 1; s <= len - L + 1; ++s){
                string sub = S.substr(s - 1, L);
                int LS = S.find(sub) + L - 1;
                // int RS = S.find_first_of(sub, LS + 1);
                // S.find()
                // printf("fst = %d, lst = %d\n", LS, S.find(sub, LS + 1));
                // if(LS < S.find_last_of(sub)){
                if(S.find(sub, LS + 1) != S.npos){
                    cout << sub << endl;
                    flag = true;
                    break;
                }
            }
        }
    }        

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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