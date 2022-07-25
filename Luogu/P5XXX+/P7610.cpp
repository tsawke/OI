//C++11 - Template
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
#include <queue>
#include <stack>
#include <functional>
#include <unistd.h>
using namespace std;
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);

class Character{
    public:
        int Num;
        int maxHP, HP;
        int maxMP, MP;
        int Atk, deltaAtk;
        int Def, deltaDef;
        int AttackNum[11];
        int talent, talentValue[3];
        int skill, skillValue[4];
        int A(void);
        int D(void);
        void Init(int);
        void ResetHP_MP(void);
}Alice[11], Bob[11];
int N;
int Rounds(0);
int IfFinish(void);// 0-None 1-AliWin 2-BobWin
vector < Character > AliAlive;
vector < Character > BobAlive;
bool cmp(Character A, Character B){
    if(A.skill == B.skill)return A.Num > B.Num;
    return A.skill > B.skill;
}
void MakeRound();
int main(){
	N = read();
    for(int i = 1; i <= N; ++i)Alice[i].Init(i);
    for(int i = 1; i <= N; ++i)Bob[i].Init(i);
    for(int i = 1; i <= N; ++i)AliAlive.push_back(Alice[i]), BobAlive.push_back(Bob[i]);


    return 0;
}
void MakeRound(){

}
int IfFinish(void){
    // bool AliWin(true);
    // for(int i = 1; i <= N; ++i){
    //     if(Bob[i].HP > 0){
    //         AliWin = false;
    //         break;
    //     }
    // }
    // if(AliWin)return 1;
    // bool BobWin(true);
    // for(int i = 1; i <= N; ++i){
    //     if(Alice[i].HP > 0){
    //         BobWin = false;
    //         break;
    //     }
    // }
    // if(BobWin)return 2;
    if(BobAlive.empty())return 1;
    if(AliAlive.empty())return 2;
    return 0;
}
int Character::A(void){
    return max(this->Atk + this->deltaAtk, 1);
}
int Character::D(void){
    return max(this->Def + this->deltaDef, 1);
}
void Character::ResetHP_MP(void){
    if(this->HP > this->maxHP)this->HP = this->maxHP;
    if(this->MP > this->maxMP)this->MP = this->maxMP;
    if(this->HP < 0)this->HP = 0;//TODO MP<0?
}
void Character::Init(int i){
    this->Num = i;
    this->maxHP = read(), this->maxMP = read();
    this->Atk = read(), this->Def = read();
    this->HP = maxHP, this->MP = 0;
    this->deltaAtk = this->deltaDef = 0;
    for(int i = 1; i <= ::N; ++i)this->AttackNum[i] = read();
    this->talent = read(), this->talentValue[1] = read(), this->talentValue[2] = read();
    this->skill = read(), this->skillValue[1] = read(), this->skillValue[2] = read(), this->skillValue[3] = read();
}
template <typename T = int>
inline T read(void)
{
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