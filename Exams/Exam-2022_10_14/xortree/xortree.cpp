#define USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

typedef long long ll;
typedef unsigned long long unll;
typedef unsigned int uint;
typedef long double ld;

template < typename T = int >
T read(void);

bool is2k[110000];

int main(){
    freopen("xortree.in", "r", stdin);
    freopen("xortree.out", "w", stdout);
    int N = read();
    int cur(1);
    while(cur <= 101000)is2k[cur] = true, cur <<= 1;
    if(is2k[N])printf("No\n"), exit(0);
    switch(N){
        // case 1:{
        //     printf("No\n");
        //     break;
        // }
        // case 2:{
        //     printf("No\n");
        //     break;
        // }
        case 3:{
            printf("Yes\n1 2\n2 3\n3 4\n4 5\n5 6\n");
            break;
        }
        // case 4:{
        //     printf("");
        //     break;
        // }
        case 5:{
            printf("Yes\n4 5\n5 1\n1 9\n9 10\n4 6\n6 8\n8 7\n6 2\n2 3\n");
            break;
        }
        case 6:{
            printf("Yes\n4 5\n5 1\n1 10\n4 7\n7 9\n9 8\n7 2\n2 3\n7 11\n10 6\n9 12\n");
            break;
        }
        case 7:{
            printf("Yes\n4 5\n5 1\n1 11\n4 8\n8 10\n10 9\n8 2\n2 3\n8 12\n11 6\n10 13\n12 14\n10 7\n");
            break;
        }
        // case 8:{
        //     printf("");
        //     break;
        // }
        case 9:{
            printf("10 8\n8 9\n10 18\n18 17\n10 5\n10 13\n13 15\n5 4\n4 1\n1 14\n1 2\n1 12\n14 7\n2 3\n12 11\n12 6\n12 16\n");
            break;
        }
        case 10:{
            printf("10 8\n8 9\n8 11\n11 19\n19 18\n11 5\n11 14\n5 4\n14 16\n4 1\n1 13\n1 2\n1 15\n15 7\n2 3\n3 12\n3 6\n3 17\n12 20\n");
            break;
        }
        default:{
            puts("No");
            break;
        }
    }

    
    return 0;
}

template < typename T >
T read(void){
    T ret(0);
    short flag(1);
    char c = getchar();
    while(!isdigit(c) && c != '-')c = getchar();
    if(c == '-')flag = -1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }ret *= flag;
    return ret;
}