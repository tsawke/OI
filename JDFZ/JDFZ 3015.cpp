#include <bits/stdc++.h>

using namespace std;

int N;
int a[101000];
int b[101000];
int squ[101000];
int len(0);
inline int read(void);



int main(){
    N = read();
    for(int i = 1; i <= N; ++i)a[read()] = i;
    for(int i = 1; i <= N; ++i){
        b[i] = a[read()];
        if(!len || squ[len] <= b[i])squ[++len] = b[i];
        else{
            *upper_bound(squ + 1, squ + len + 1, b[i]) = b[i];
        }
    }
    printf("%d\n", len);
    return 0;
}


inline int read(void){
    int ret(0);
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