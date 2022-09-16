#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include "md5.h"

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

map < string, string > idx;

void Init(void){
    for(int i = 0; i <= 9999; ++i){
        char* tmp = new char[10];
        sprintf(tmp, "%d", i);
        string tmps(tmp);
        // cout << tmps << endl;
        string md5s = websocketpp::md5::md5_hash_hex(tmps);
        // cin >> md5s;
        idx.insert(make_pair(md5s, tmps));
        delete[] tmp;
    }
}

int main(){
    // freopen("T3/hackllq1.in", "w", stdout);
    // freopen("build.cpp", "w", stdout);
    // for(int i = 1; i <= 10000; ++i){
    //     printf("idx.insert( make_pair(\"");
    //     char* tmp;
    //     sprintf(tmp, "%d", i);
    //     string tmps(tmp);
    //     string md5s = websocketpp::md5::md5_hash_hex(tmps);
    //     cout << md5s << "\", \"" << tmps;
    //     printf("\") );");
    //     if(i % 10 == 0)printf("\n");
    // }
    // cout << websocketpp::md5::md5_hash_hex("0");  

    Init();
    int num = 2;
    for(int i = 114514; i <= 114514; ++i){
        num = i;

        char* filei = new char[50];
        char* fileo = new char[50];
        sprintf(filei, "T3/hackllq%d.in", num);
        sprintf(fileo, "T3/hackllq%d.out", num);
        // freopen(filei, "w", stdout);
        FILE* in = fopen(filei, "w");
        FILE* out = fopen(fileo, "w");
        int N = rndd(3, 5);
        // printf("TEST\n");
        fprintf(in, "%d\n", N);
        for(int i = 1; i <= N; ++i){
            int tmpd = rndd(1, 10);
            char* tmp = new char[10];
            sprintf(tmp, "%d", tmpd);
            string tmps(tmp);
            // freopen(filei, "w", stdout);
            fprintf(out, "%s\n", tmps.c_str());
            // cout << tmps << endl;

            string md5s = websocketpp::md5::md5_hash_hex(tmps);
            // freopen(fileo, "w", stdout)
            fprintf(in, "%s\n", md5s.c_str());
            // cout << md5s << endl;
            delete[] tmp;
        }
        delete[] filei;
        delete[] fileo;
        fclose(in);
        fclose(out);

    }
                                              

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