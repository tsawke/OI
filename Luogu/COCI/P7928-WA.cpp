#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);

int N, K;
deque < bool > st;
int ali(0), bob(0);
int main(){
    N = read(), K = read();
    for(int i = 1; i <= N; ++i){
        char c = getchar();
        while(c != 'C' && c != 'P')c = getchar();
        st.push_back(c == 'C' ? true : false);
    }
    while(!st.empty()){
        if(!st.front())st.pop_front();
        else if(!st.back())st.pop_back();
        else if(st.size() <= 2)st.pop_front(), ++ali;
        else{
            auto itl = st.begin(), itr = st.end() - 1;
            bool dire = false;
            while(itl < itr){
                if(*itl)break;
                if(*itr){dire = true; break;}
                itl++;
                itr--;
            }
            if(dire)st.pop_back();
            else st.pop_front();
            ++ali;
        }
        if(ali >= K){
            printf("NE\n");
            return 0;
        }
        if(!st.empty()){
            if(!st.front())st.pop_front();
            else if(!st.back())st.pop_back();
            else if(st.size() <= 2)st.pop_front(), ++bob;
            else {
                auto itl = st.begin() + 1, itr = st.end() - 1 - 1;
                bool dire = false;
                while(itl < itr){
                    if(*itl)break;
                    if(*itr){dire = true; break;}
                    itl++;
                    itr--;
                }
                if(dire)st.pop_back();
                else st.pop_front();
                ++bob;
            }
        }
        if(bob >= K){
            printf("DA\n");
            return 0;
        }
    }
    printf("NE\n");
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