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



template<typename T = int>
inline T read(void);

int N, M;
char mp[114][514];

int main(){
    FILE* in = fopen("in.txt", "r");
    fscanf(in, "%d%d", &N, &M);
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            char c = fgetc(in); while(c != '#' && c != '.' && c != '@' && c != '*' && c != '!')c = fgetc(in);
            mp[i][j] = c;
        }
    }
    fclose(in);

    in = fopen("out.txt", "r");
    int step = fscanf(in, "%d", &step);
    while(step--){
        int x, y;
        fscanf(in, "%d%d", &x, &y);
        char c = fgetc(in); while(c != 'L' && c != 'R' && c != 'U' && c != 'D')c = fgetc(in);

        if(mp[x][y] != '@' && mp[x][y] != '!'){
            cerr << "BOX UNEXISTS" << endl;
            return 1;
        }

        int tx, ty;
        switch(c){
            case 'L':{
                tx = x + 0, ty = y - 1;
                break;
            }
            case 'R':{
                tx = x + 0, ty = y + 1;
                break;
            }
            case 'U':{
                tx = x - 1, ty = y + 0;
                break;
            }
            case 'D':{
                tx = x + 1, ty = y + 0;
                break;
            }
        }
        if(tx < 1 || tx > N || ty < 1 || ty > M){
            cerr << "OUT OF BOUNDS" << endl;
            return 1;
        }

        if(mp[tx][ty] == '#' || mp[tx][ty] == '@' || mp[tx][ty] == '!'){
            cerr << "TARGET BLOCKED" << endl;
            return 1;
        }

        if(mp[tx][ty] == '.'){
            if(mp[x][y] == '@')swap(mp[tx][ty], mp[x][y]);
            else if(mp[x][y] == '!')mp[x][y] = '*', mp[tx][ty] = '@';
        }else if(mp[tx][ty] == '*'){
            if(mp[x][y] == '@')mp[x][y] = '.', mp[tx][ty] = '!';
            else if(mp[x][y] == '!')swap(mp[tx][ty], mp[x][y]);
        }
    }

    fclose(in);

    cerr << "Complete." << endl;

    for(int i = 1; i <= N; ++i)for(int j = 1; j <= M; ++j){
        if(mp[i][j] == '@' || mp[i][j] == '*'){
            cerr << "FAIL" << endl;
            return 1;
        }
    }

    cerr << "Success" << endl;




    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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