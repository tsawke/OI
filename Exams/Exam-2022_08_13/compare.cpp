#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

mt19937 rnd(random_device{}());
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;


template<typename T = int>
inline T read(void);

string My = "test.cpp", STD = "std.cpp";
void ExitErr(string s){
    cout<<s<<endl;
    exit(1);
}
int cnt(0);
int cntAC(0);
int main(){
    char shell[110000];
    sprintf(shell, "g++ %s -o tmp1 -fdiagnostics-color=always -Wall -fsanitize=undefined,signed-integer-overflow,address -std=c++14 -g", My);
    if(!system(shell))ExitErr("G++ Error");
    sprintf(shell, "g++ %s -o tmp2 -fdiagnostics-color=always -Wall -fsanitize=undefined,signed-integer-overflow,address -std=c++14 -g", STD);
    if(!system(shell))ExitErr("G++ Error");
    sleep(2);
    while(true){
        // Build();//in.txt
        ++cnt;
        sprintf(shell, "./tmp1 < in.txt > out1.txt");
        if(!system(shell))ExitErr("Run Error");
        sprintf(shell, "./tmp2 < in.txt > out2.txt");
        if(!system(shell))ExitErr("Run Error");
        sprintf(shell, "diff out1.txt out2.txt > nul");
        if(!system(shell))++cntAC, printf("Accept!\n");
        if(cnt % 100 == 0)printf("\n\n\nChecked %d Values, Rate:%.6lf\n\n\n", cnt, (double)cntAC * 1.0000000 / cnt * 1.00000000);
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