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

template < typename T = int >
inline T read(void);

int main(){

    int T = read();
    while(T--){
        string S; cin >> S;
        stack < char > cur;
        for(int i = 0; i < S.size(); ++i){
            char c = S.at(i);
            if(c == '-')++i, cur.push('>');
            else if(c != ')')cur.push(c);
            else{
                char v2 = cur.top(); cur.pop();
                
                if(!cur.empty() && cur.top() == '!'){
                    cur.pop();
                    if (!cur.empty() && cur.top() == '(')cur.pop();
                    cur.push(v2 == '1' ? '0' : '1');
                }else{
                    char op = cur.top(); cur.pop();
                    char v1 = cur.top(); cur.pop();
                    if (!cur.empty() && cur.top() == '(') cur.pop();
                    bool a = v1 == '1', b = v2 == '1', r(false);
                    switch(op){
                        case '&': r = a & b; break;
                        case '|': r = a | b; break;
                        case '^': r = a ^ b; break;
                        case '>': r = (!a) | b; break;
                    }
                    cur.push(r ? '1' : '0');
                }
                
            }
        }printf("%c\n", cur.top());
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