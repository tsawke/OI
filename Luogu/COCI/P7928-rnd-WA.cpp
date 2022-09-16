#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(315);
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

int N, K;
deque < bool > st;
deque < bool > stt;
int main(){
    N = read(), K = read();
    for(int i = 1; i <= N; ++i){
        char c = getchar();
        while(c != 'C' && c != 'P')c = getchar();
        stt.push_back(c == 'C' ? true : false);
    }
    int acnt, bcnt;
    while((double)clock() / CLOCKS_PER_SEC <= 0.9800){
        int ali(0), bob(0);
        st = stt;
        while(!st.empty()){
            if(!st.front())st.pop_front();
            else if(!st.back())st.pop_back();
            else if(st.size() <= 2)st.pop_front(), ++ali;
            else if(rndd(0, 114514) * 2 >= 114514)st.pop_front(), ++ali;
            else st.pop_back(), ++ali;
            if(ali >= K){
                ++acnt;
                break;
            }
            if(!st.empty()){
                if(!st.front())st.pop_front();
                else if(!st.back())st.pop_back();
                else if(st.size() <= 2)st.pop_front(), ++bob;
                else if(rndd(0, 114514) * 2 >= 114514)st.pop_front(), ++ali;
                else st.pop_back(), ++ali;
            }
            if(bob >= K){
                ++bcnt;
                break;
            }
        }
    }
    printf("%s\n", acnt < bcnt ? "DA" : "NE");
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