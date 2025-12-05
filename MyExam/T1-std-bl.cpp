#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr

/******************************
abbr
px/py => position x/y
atk => Attack
def => defence
dir => direction
vel => velocity
dur => durability
txxx => transform xxx
opt/oper => operator
ins => instant
day => delayed
******************************/

#define SOLDIER 100, 100, 20, 10, 2, 30
#define ASSASSIN 20, 40, 50, 1, 5, 5
#define TANK 500, 800, 3, 50, 1, 2
#define MAGICIAN 100, 100, 20, 5, 2, 10
#define PRIEST 100, 100, 5, 5, 2, 10
#define PP player[playr]
#define PJ player[j]
#define PK player[k]

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

int height, width;
vector < char > oper_ins[5];
vector < char > oper_day[5];
int dx[10] = {0, 1, 0, -1, 0};
int dy[10] = {0, 0, 1, 0, -1};
int ddx[10] = {0, 1, 1, 1, 0, 0, -1, -1, -1};
int ddy[10] = {0, -1, 0, 1, -1, 1, -1, 0, 1};

enum Job{soldier = 1, assassin, tank, magician, priest};
string player_name[5] = {"", "tsawke", "sssmzy", "zpair", "cc0000"};
string job_name[6] = {"", "soldier", "assassin", "tank", "magician", "priest"};
int tplayer(string);
int tfps(string);
Job tjob(string);
void Attack(int, int, int = 1);
void pResults(void);
void JudgeWin(int);
void JudgeDie(void);
void MakeDayOPT(int);
void MakeInsOPT(int);

struct Player{
    int px, py;
    int HP, maxHP;
    int atk, def;
    int dir;
    int vel;
    int dur;
    int fps;
    Job job;
    bool team;
    void Player_Init(int, int, int, int, int, int, Job);
    void Init(int, int, int);
    void Desc(void){
        cout << job << "_" << team << endl;
        printf("Player Status:\nx = %d, y = %d\nHP = %d, mHP = %d\natk = %d, def = %d\n, dir = %d, vel = %d, dur = %d\nfps = %d\n\n",
            px, py, HP, maxHP, atk, def, dir, vel, dur, fps);
    }
}player[5];

int main(){
    freopen("snewbal1l.in", "r", stdin);
    freopen("snewbal1l.out", "w", stdout);
    ios::sync_with_stdio(false);
    player[1].team = player[2].team = false;
    player[3].team = player[4].team = true;
    for(int i = 1; i <= 4; ++i){
        string name, fps;
        cin >> name >> fps;
        player[tplayer(name)].fps = tfps(fps);
    }
    cin >> height >> width;
    for(int i = 1; i <= 4; ++i){
        string name, job;
        cin >> name >> job;
        int namep = tplayer(name);
        Job jobp = tjob(job);
        switch(jobp){
            case soldier:
                player[namep].Player_Init(SOLDIER, jobp); break;
            case assassin:
                player[namep].Player_Init(ASSASSIN, jobp); break;
            case tank:
                player[namep].Player_Init(TANK, jobp); break;
            case magician:
                player[namep].Player_Init(MAGICIAN, jobp); break;
            case priest:
                player[namep].Player_Init(PRIEST, jobp); break;
        }
    }
    for(int i = 1; i <= 4; ++i){
        string name; int px, py, dir;
        cin >> name;
        cin >> px >> py >> dir;
        player[tplayer(name)].Init(px, py, dir);
    }
    while(true){
        int time;
        cin >> time;
        if(!~time){
            printf("No one is the winner!\n-1\n");
            pResults();
        }
        vector < int > ord;
        for(int i = 1; i <= 4; ++i){
            oper_ins[i].clear();
            oper_day[i].clear();
            string name, opt;
            cin >> name >> opt;
            int pname = tplayer(name);
            for(auto i : opt){
                if(i == 'w' || i == 'a' || i == 's' || i == 'd' || i == '*' || i == '+')oper_day[pname].push_back(i);
                else oper_ins[pname].push_back(i);
            }
            MakeInsOPT(pname);
            ord.push_back(pname);
        }
        JudgeWin(time);
        for(auto o : ord)MakeDayOPT(o), JudgeWin(time);
    }
    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
struct Snb{
    int x, y;
    int dir;
    int atk;
    int v;
    Snb(int x, int y, int dir, int atk, int v):x(x), y(y), dir(dir), atk(atk), v(v){;}
    Snb(void) = default;
};
void MakeDayOPT(int playr){
    int ori_def[5];
    int exdef[5];
    int def_fps[5];
    memset(def_fps, 0, sizeof(def_fps));
    vector < Snb > snb; 
    vector < char > move[5];
    for(int j = 1; j <= 4; ++j){
        ori_def[j] = PJ.def;
        exdef[j] = int(floor((double)PJ.def * 1.2));
        for(auto i : oper_day[j]){
            switch(i){
                case '*':
                    snb.push_back(Snb(PP.px, PP.py, PP.dir, PP.atk, PP.vel));
                    break;
                case '+':
                    def_fps[j] = PP.dur;
                    break;
                default:
                    move[j].push_back(i);
                    break;
            }
        }
        reverse(move[j].begin(), move[j].end());
    }
    for(int i = 1; i <= PP.fps; ++i){
        for(int j = 1; j <= 4; ++j)
            if(def_fps[j]-- > 0)PJ.def = exdef[j];
            else PJ.def = ori_def[j];
        for(auto &s : snb){
            switch(s.dir){
                case 1: s.x -= s.v; break;
                case 2: s.y += s.v; break;
                case 3: s.x += s.v; break;
                case 4: s.y -= s.v; break;
            }
        }
        for(int j = 1; j <= 4; ++j){
            if(move[j].empty())continue;
            switch(move[j].back()){
                case 'w': PJ.px -= 1; break;
                case 'd': PJ.py += 1; break;
                case 's': PJ.px += 1; break;
                case 'a': PJ.py -= 1; break;
            }
            move[j].pop_back();
        }
        for(int j = 1; j <= 4; ++j)
            for(auto s : snb)
                if(PJ.px == s.x && PJ.py == s.y)
                    Attack(s.atk, j);
    }
    for(int j = 1; j <= 4; ++j)PJ.def = ori_def[j];
    JudgeDie();
} 
void MakeInsOPT(int playr){
    for(auto i : oper_ins[playr]){
        switch(i){
            case 't':{
                if(PP.dir <= 3)PP.dir++;
                else PP.dir = 1;
                break;
            }
            case 'f':{
                switch(PP.job){
                    case soldier:{
                        for(int i = 1; i <= 8; ++i)
                            for(int j = 1; j <= 4; ++j)
                                if(PJ.HP > 0 && PJ.px == PP.px + ddx[i] && PJ.py == PP.py + ddy[i])
                                    Attack(PP.atk * 3, j);
                        break;
                    }
                    case assassin:{
                        for(int j = 1; j <= 4; ++j)
                            if(
                                PJ.HP > 0 &&
                                (
                                    (PP.dir == 1 && PJ.px < PP.px && PJ.px >= PP.px - 2 && PJ.py == PP.py) ||
                                    (PP.dir == 3 && PJ.px > PP.px && PJ.px <= PP.px + 2 && PJ.py == PP.py) ||
                                    (PP.dir == 2 && PJ.py > PP.py && PJ.py <= PP.py + 2 && PJ.px == PP.px) ||
                                    (PP.dir == 4 && PJ.py < PP.py && PJ.py >= PP.py - 2 && PJ.px == PP.px)
                                )
                            )
                                Attack(PP.atk * floor((PJ.maxHP - PJ.HP) * 1.00 / PJ.maxHP), j);
                        break;
                    }
                    case magician:{
                        for(int j = 1; j <= 4; ++j)
                            if(PJ.team != PP.team)
                                PJ.def = floor((double)PJ.def * 0.8);
                        break;
                    }
                    case priest:{
                        for(int j = 1; j <= 4; ++j)
                            if(PJ.team == PP.team && PJ.HP > 0)
                                PJ.HP = min(PJ.maxHP, int(floor((double)PJ.HP * 1.5)));
                        break;
                    }
                    default: break;
                }
                break;
            }
            case 'g':{
                switch(PP.job){
                    case soldier:{
                        if((double)PP.HP < (double)PP.maxHP * 0.1){
                            for(int j = 1; j <= 4; ++j)
                                if(PJ.team == PP.team)
                                    PJ.atk = int(floor((double)PJ.atk * 1.2));
                            PP.fps = int(floor((double)PP.fps * 0.8));
                        }else
                            PP.HP = int(floor((double)PP.HP * 0.7));
                        break;
                    }
                    case assassin:{
                        PP.HP = int(floor((double)PP.HP * 0.9));
                        switch(PP.dir){
                            case 1: PP.px -= 3; break;
                            case 3: PP.px += 3; break;
                            case 2: PP.py += 3; break;
                            case 4: PP.py -= 3; break;
                        }
                        break;
                    }
                    case magician:{
                        for(int j = 1; j <= 4; ++j)
                            if(PJ.team == PP.team)
                                PJ.atk = int(floor((double)PJ.atk * 1.2));
                        break;
                    }
                    case priest:{
                        for(int j = 1; j <= 4; ++j)
                            if(PJ.team == PP.team)
                                PJ.def = floor((double)PJ.def * 1.2);
                        break;
                    }
                    default: break;
                }
                break;
            }
            case 'x':{
                bool died(false);
                for(int j = 1; j <= 4; ++j)
                    if(PJ.team != PP.team && PJ.HP > 0)
                        if((double)PJ.HP < (double)PJ.maxHP * 0.1){
                            PJ.HP = -1;
                            died = true;
                        }
                if(!died)
                    PP.HP = int(floor((double)PP.HP * 0.6));
                break;
            }
            case 'p':{
                for(int j = 1; j <= 4; ++j)
                    if(PJ.team == PP.team)
                        PJ.fps = int(floor((double)PJ.fps * 0.8));
                    else 
                        PJ.fps = int(floor((double)PJ.fps * 1.2));
                break;
            }
        }
    }
}
void JudgeDie(void){
    for(int j = 1; j <= 4; ++j){
        if(PJ.px <= 0 || PJ.py <= 0 || PJ.px > height || PJ.py > width)
            PJ.HP = -1;
    }
}
void JudgeWin(int time){
    if(player[1].HP <= 0 && player[2].HP <= 0){
        printf("zpair & cc0000 are the winners!\n%d\n", time);
        return pResults();
    }
    if(player[3].HP <= 0 && player[4].HP <= 0){
        printf("tsawke & sssmzy are the winners!\n%d\n", time);
        return pResults();
    }
}
void Attack(int atk, int playr, int cnt){
    // printf("ATTACK: %d, to %d\n", atk, playr);
    if(PP.HP <= 0)return;
    PP.HP -= max(1, atk - PP.def) * cnt;
}
void pResults(void){
    for(int i = 1; i <= 4; ++i)printf("%d%c", player[i].HP > 0 ? player[i].HP : 0, i == 4 ? '\n' : ' ');
    for(int i = 1; i <= 4; ++i)printf("%d%c", player[i].fps, i == 4 ? '\n' : ' ');
    exit(0);
}
int tfps(string fps){
    int ret(0);
    for(auto i : fps){
        if(isdigit(i)){
            ret *= 10;
            ret += i - '0';
        }
    }
    return ret;
}
Job tjob(string job){for(int i = 1; i <= 5; ++i)if(!job_name[i].compare(job))return (Job)i; return (Job)1;}
int tplayer(string name){for(int i = 1; i <= 4; ++i)if(!player_name[i].compare(name))return i; return -1;}
void Player::Init(int px, int py, int dir){
    this->px = px, this->py = py;
    this->dir = dir;
}
void Player::Player_Init(int HP, int maxHP, int atk, int def, int vel, int dur, Job job){
    this->HP = HP, this->maxHP = maxHP,
    this->atk = atk, this->def = def,
    this->vel = vel, this->dur = dur;
    this->job = job;
}