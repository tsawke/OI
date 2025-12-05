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
int rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;



template<typename T = int>
inline T read(void);


enum Job{soldier = 1, assassin, tank, magician, priest};
string player_name[5] = {"", "tsawke", "sssmzy", "zpair", "cc0000"};
string job_name[6] = {"", "soldier", "assassin", "tank", "magician", "priest"};
int fps[5];
Job job[5];
int idx[5] = {0, 1, 2, 3, 4};
int main(){
    freopen("T1/snewbal1l2.in", "w", stdout);
    random_shuffle(idx + 1, idx + 4 + 1);
    for(int i = 1; i <= 4; ++i)fps[idx[i]] = rndd(10, 256), cout << player_name[idx[i]] << " " << fps[idx[i]] << endl;
    int N = rndd(5, 1000), M = rndd(5, 1000);
    printf("%d %d\n", N, M);
    random_shuffle(idx + 1, idx + 4 + 1);
    for(int i = 1; i <= 4; ++i)job[idx[i]] = (Job)rndd(1,5);
    for(int i = 1; i <= 4; ++i)cout << player_name[idx[i]] << " " << job_name[job[idx[i]]] << endl;
    random_shuffle(idx + 1, idx + 4 + 1);
    for(int i = 1; i <= 4; ++i){
        int px = rndd(1, N), py = rndd(1, M);
        int dir = rndd(1, 4);
        cout << player_name[idx[i]] << " ";
        printf("%d %d %d\n", px, py, dir);
    }
    int siz = rndd(2, 10); int last_time(0);
    for(int i = 1; i <= siz; ++i){
        last_time = last_time + rndd(1, 100);
        printf("%d\n", last_time);
        random_shuffle(idx + 1, idx + 4 + 1);
        for(int j = 1; j <= 4; ++j){
            int len(1000);
            cout << player_name[idx[j]] << " ";
            while(len > 0 && rnddd(99)){
                --len;
                if(rnddd(40)){printf("w"); continue;}
                if(rnddd(40)){printf("a"); continue;}
                if(rnddd(40)){printf("s"); continue;}
                printf("d"); continue;
            }
            printf("\n");
        }
    }
    printf("-1\n");
    // freopen("T1/snewbal1l2.in", "w", stdout);
    // random_shuffle(idx + 1, idx + 4 + 1);
    // for(int i = 1; i <= 4; ++i)fps[idx[i]] = rndd(10, 256), cout << player_name[idx[i]] << " " << fps[idx[i]] << endl;
    // int N = rndd(5, 100), M = rndd(5, 100);
    // printf("%d %d\n", N, M);
    // random_shuffle(idx + 1, idx + 4 + 1);
    // for(int i = 1; i <= 4; ++i)job[idx[i]] = (Job)rndd(1,5);
    // for(int i = 1; i <= 4; ++i)cout << player_name[idx[i]] << " " << job_name[job[idx[i]]] << endl;
    // random_shuffle(idx + 1, idx + 4 + 1);
    // for(int i = 1; i <= 4; ++i){
    //     int px = rndd(1, N), py = rndd(1, M);
    //     int dir = rndd(1, 4);
    //     cout << player_name[idx[i]] << " ";
    //     printf("%d %d %d\n", px, py, dir);
    // }
    // int siz = rndd(2, 10); int last_time(0);
    // for(int i = 1; i <= siz; ++i){
    //     last_time = last_time + rndd(1, 100);
    //     printf("%d\n", last_time);
    //     random_shuffle(idx + 1, idx + 4 + 1);
    //     for(int j = 1; j <= 4; ++j){
    //         int len(100);
    //         cout << player_name[idx[j]] << " ";
    //         if(rnddd(30))printf("+"), --len;
    //         if(rnddd(60)){
    //             int lenn = rndd(0, 80);
    //             len -= lenn;
    //             for(int t = 1; t <= lenn; ++t)printf("*");
    //         }
    //         while(len > 0 && rnddd(99)){
    //             --len;
    //             if(rnddd(15)){printf("w"); continue;}
    //             if(rnddd(15)){printf("a"); continue;}
    //             if(rnddd(15)){printf("s"); continue;}
    //             if(rnddd(15)){printf("d"); continue;}
    //             if(rnddd(15)){printf("t"); continue;}
    //             if(job[idx[j]] == tank){++len; continue;}
    //             if(rnddd(20)){printf("f"); continue;}
    //             if(rnddd(20)){printf("g"); continue;}
    //             if(job[idx[j]] == magician){
    //                 if(rnddd(50)){printf("x"); continue;}
    //                 else{printf("p"); continue;}
    //             }
    //         }
    //         printf("\n");
    //     }
    // }
    // printf("-1\n");


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