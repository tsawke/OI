#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <climits>
#include <iostream>
#include <string>
#include <map>
#include <unistd.h>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T>
inline T read(void);
void dfs(int, const int&);
bool img[110][110];
int ans(0);
//up2 down2 left2 right2 coord4
int dx[20] = {0,  -1, -2, 1, 2, 0, 0, 0, 0, 1, 1, -1, -1};
int dy[20] = {0,  0, 0, 0, 0, -1, -2, 1, 2, 1, -1, 1, -1};
void rm(int, int); //remove
int main(){
    int n = read<int>(), m = read<int>();
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            char c = getchar();
            if(c == '-')img[i][j] = false;
            if(c == '#')img[i][j] = true;
        }
        char ct = getchar();
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(img[i][j]){
                ++ans;
                rm(i, j);
            }
        }
    }


    pause();
    return 0;
}
void rm(int x, int y){
    ;
}
//TODO Completion required

template <typename T>
inline T read(void){
    T ret(0);
    short flag(1);
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')flag = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        ret *= 10, ret += (c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}