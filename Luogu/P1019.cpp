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
#include <functional>
#include <unistd.h>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
class WORD{
    public:
        int use = 0;
        int head;//char 2 int
        int tail;//char 2 int
        int str[110];
        int len;
        void GetWord(void);
}word[30], base;
int n;
int ans(INT_MIN);
void dfs(int, WORD);
int CalLen(WORD, WORD);
void PrintWord(char*, WORD);
int main(){
    n = read();
    for(int i = 1; i <= n; ++i)word[i].GetWord();
    base.GetWord();

// ///////////////////////////////////////////
//     for(int i = 1; i <= n; ++i){
//         // printf("Words No.%d -- %d | %c  %d | %c\n", i, word[i].head, char(word[i].head), word[i].tail, char(word[i].tail));
//         printf("Words No.%d -- ", i);
//         PrintWord("", word[i]);
//         printf(",  len = %d\n", word[i].len);
//     }
//     PrintWord("Base -- ", base);
//     printf(",  len = %d\n", base.len);
// //////////////////////////////////////////

    dfs(1, base);
    printf("%d\n", ans);    
    return 0;
}
void PrintWord(char* str, WORD word){
    printf("%s", str);
    for(int i = 1; i <= word.len; ++i)printf("%c", char(word.str[i]));
//    printf("\n");
}
void dfs(int nowLen, WORD nowWord){
//    printf("Start DFS: nowLen = %d  Tail = %d\n", nowLen, nowTail);
    for(int i = 1; i <= ::n; ++i){
//        if(word[i].use <= 1 && word[i].head == nowTail){
        int ret = CalLen(nowWord, word[i]);
        // printf("  which value is %d\n", ret);
        if(word[i].use <= 1 && ret){
            ++word[i].use;
            dfs(nowLen + word[i].len - ret, word[i]);
            --word[i].use;
        }
    }
    ans = max(ans, nowLen);
}
int CalLen(WORD now, WORD next){
    // printf("CalLen between ");PrintWord(" ", now);PrintWord(" and ", next);
        
    for(int adv = 0; adv < min(now.len, next.len); ++adv){
        bool flag(true);
        for(int i = now.len - adv, j = 1, count = 0; count <= adv; ++count, ++i, ++j){
            if(now.str[i] != next.str[j]){flag = false; break;}
        }
        if(flag)return adv + 1;
    }
    return 0;
}
void WORD::GetWord(void){
    char c = getchar();
    while(c < 'A' || 'z' < c)c = getchar();
    this -> head = this -> tail = int(c);
    int count(0);
    this -> str[++count] = int(c);
    int len(1);
    c = getchar();
    while('A' <= c && c <= 'z'){
        ++len;
        this -> str[++count] = int(c);
        this -> tail = int(c);
        c = getchar();
    }
    this -> len = len;
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