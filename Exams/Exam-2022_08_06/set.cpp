#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;


template<typename T = int>
inline T read(void);

vector<int>arr;
int N;
int main(){
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout); 
    N = read();
    for(int i = 1; i <= N; ++i){
        char mode = getchar();
        while(mode != 'A' && mode != 'B')mode = getchar();
        switch(mode){
            case 'A':{
                arr.push_back(read());
                break;
            }
            case 'B':{
                int minn(INT_MAX);
                int mod = read();
                if(arr.empty()){
                    printf("-1\n");
                    break;
                }
                for(auto i : arr){

                    minn = min(minn, i % mod);
                }
                printf("%d\n", minn);
                break;
            }
        }
    }  

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