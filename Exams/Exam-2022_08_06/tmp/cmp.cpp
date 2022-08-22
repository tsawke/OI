#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;


template<typename T = int>
inline T read(void);



int main(){
    srand(2147); rand();
    int N = rand() % 200 + 1, M = rand() % 10 + 1;
    FILE *fp = fopen("values.in", "w");
    fprintf(fp, "%d %d\n", N, M);
    bool used[11000];
    memset(used, 0, sizeof(used));
    int cnt(0);
    while(cnt <= N - 1){
        int val = rand() % (N - 1) + 1;
        if(!used[val]){
            used[val] = true;
            ++cnt;
            fprintf(fp, "%d ", val);
        }
    }
    fclose(fp);
    system("./Q < values.in > out1.out");
    system("./Q_ < values.in > out2.out");
    system("diff out1.out out2.out");

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