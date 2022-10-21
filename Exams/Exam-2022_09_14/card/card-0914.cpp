#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#ifdef __linux__
#include <unistd.h>
#endif
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

int N;
int winner(false); //0-A, 1-B
#define att(x) at(x - 1)
#define A P[0]
#define B P[1]
#define CP P[cpl] //current-player
vector < int > P[2];
int tmp[20];

void Clear(void){
    A.clear(), B.clear();

}
int Win(void){
    bool flag(false);
    for(int i = 1; i <= 15; ++i)
        if(B.att(i)){flag = true; break;}
    if(!flag)return -1;
    flag = false;
    for(int i = 1; i <= 15; ++i)
        if(A.att(i)){flag = true; break;}
    if(!flag)return 1;
    return 0;
}
bool Play(bool _cpl){
    int cst(6);//current-status
    int cpl(_cpl); //current-player: 0-A, 1-B
    int lst(0);
    int s5len(-1);
    while(true){
        switch(cst){
            case 1:{
                bool flag(false);
                for(int i = lst + 1; i <= 15; ++i){
                    if(CP.att(i)){
                        CP.att(i)--;
                        lst = i;
                        cpl = !cpl;
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    lst = 0;
                    cst = 6;
                    cpl = !cpl;
                }
                break;
            }
            case 2:{
                bool flag(false);
                for(int i = lst + 1; i <= 15; ++i){
                    if(CP.att(i) >= 2){
                        CP.att(i) -= 2;
                        lst = i;
                        cpl = !cpl;
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    lst = 0;
                    cst = 6;
                    cpl = !cpl;
                }
                break;
            }
            case 3:{
                bool flag(false);
                for(int i = lst + 1; i <= 15; ++i){
                    if(CP.att(i) >= 3){
                        CP.att(i) -= 3;
                        lst = i;
                        cpl = !cpl;
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    lst = 0;
                    cst = 6;
                    cpl = !cpl;
                }
                break;
            }
            case 4:{
                bool flag(false);
                for(int i = lst + 1; i <= 15; ++i){
                    if(CP.att(i) >= 4){
                        CP.att(i) -= 4;
                        lst = i;
                        cpl = !cpl;
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    lst = 0;
                    cst = 6;
                    cpl = !cpl;
                }
                break;
            }
            case 5:{
                bool flag(false);
                for(int i = lst + 1; i <= 13; ++i){
                    if(i > 13 - s5len + 1)break;
                    for(int j = i; j <= i + s5len - 1; ++j){
                        if(CP.att(j) != 1)break;
                        if(j == i + s5len - 1){
                            for(int k = i; k <= j; ++k){
                                CP.att(k)--;
                            }
                            lst = i;
                            cpl = !cpl;
                            flag = true;
                        }
                    }
                    if(flag)break;
                }
                if(!flag){
                    if(CP.att(14) && CP.att(15)){
                        CP.att(14) = CP.att(15) = 0;
                        lst = 0;
                        cst = 6;
                        flag = true;
                    }
                }
                if(!flag){
                    lst = 0;
                    cst = 6;
                    cpl = !cpl;
                }
                break;
            }
            case 6:{
                for(int i = 1; i <= 15; ++i){
                    if(!CP.att(i))continue;
                    bool flag = true;
                    int len(0);
                    if(i > 9 || CP.att(i) != 1){flag = false;}
                    else 
                        for(int j = i; j <= 13; ++j){
                            if(CP.att(j) != 1){break;}
                            else ++len;
                        }
                    if(flag && len >= 5){
                        for(int j = i; j <= i + len - 1; ++j)CP.att(j)--;
                        cst = 5;
                        lst = i;
                        s5len = len;
                        cpl = !cpl;
                        break;
                    }
                    cst = CP.att(i);
                    CP.att(i) = 0;
                    cpl = !cpl;
                    lst = i;
                    break;
                }
                break;
            }
        }
        if(Win())
            return Win() == 1 ? false : true;
        // printf("A: ");
        // for(auto i : A)printf("%d ", i);
        // printf("\n");
        // printf("B: ");
        // for(auto i : B)printf("%d ", i);
        // printf("\n");
        // printf("Status: cst = %d, lst = %d, cpl = %d, s5len = %d\n", cst, lst, cpl ,s5len);
        // sleep(1);
    }


}
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    N = read();
    for(int n = 1; n <= N; ++n){
        fprintf(stderr, "%d\n", n), fflush(stderr);
        Clear();
        for(int i = 1; i <= 15; ++i)tmp[i] = read();
        for(int i = 3; i <= 13; ++i)A.push_back(tmp[i]);
        for(int i = 1; i <= 2; ++i)A.push_back(tmp[i]);
        for(int i = 14; i <= 15; ++i)A.push_back(tmp[i]);
        for(int i = 1; i <= 15; ++i)tmp[i] = read();
        for(int i = 3; i <= 13; ++i)B.push_back(tmp[i]);
        for(int i = 1; i <= 2; ++i)B.push_back(tmp[i]);
        for(int i = 14; i <= 15; ++i)B.push_back(tmp[i]);
        // printf("A: ");
        // for(auto i : A)printf("%d ", i);
        // printf("\n");
        // printf("B: ");
        // for(auto i : B)printf("%d ", i);
        // printf("\n");
        int posl, posw;
        if(!winner){
            for(int i = 15; i >= 1; --i)
                if(B.att(i)){B.att(i)--; posl = i; break;}
            for(int i = 1; i <= 15; ++i)
                if(A.att(i)){A.att(i)--; posw = i; break;}
            A.att(posl)++, B.att(posw)++;
        }else{
            for(int i = 15; i >= 1; --i)
                if(A.att(i)){A.att(i)--; posl = i; break;}
            for(int i = 1; i <= 15; ++i)
                if(B.att(i)){B.att(i)--; posw = i; break;}
            B.att(posl)++, A.att(posw)++;
        }
        // printf("A: ");
        // for(auto i : A)printf("%d ", i);
        // printf("\n");
        // printf("B: ");
        // for(auto i : B)printf("%d ", i);
        // printf("\n");
        bool ret = Play(!winner);
        printf("%d\n", ret ? 1 : 0);
        winner = ret;
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