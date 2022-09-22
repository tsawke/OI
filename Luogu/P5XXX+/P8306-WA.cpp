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
int T, N, Q;
int transfer(char);
void ClearAll(void);
void Insert(string);
int Prefix(string);
int Trie[3000005][65];
int end[3000005];
int cnt[3000005];
int VertexN(0);
int main(){
	T = read();
	for(int t = 1; t <= T; ++t){
		N = read(); Q = read();
		for(int i = 1; i <= N; ++i){
			string str;
			cin>>str;
			Insert(str);
		}
		for(int i = 1; i <= Q; ++i){
			string str;
			cin>>str;
			printf("%d\n", Prefix(str));
		}
		ClearAll();
	}
    return 0;
}
// int FindAllPrefix(int pos){
// 	int ret(::end[pos]);
// 	for(int i = 1; i <= 70; ++i)
// 		if(Trie[pos][i])
// 			ret += FindAllPrefix(Trie[pos][i]);
// 	return ret;
// }
int Prefix(string s){
	//Find Prefix Last Pos
	int pos(1), ret(0), len = int(s.length());
	for(int i = 0; i < len; ++i){
		int chpos = transfer(s[i]);
		if(i == len - 1)
			ret = cnt[pos];
		if(!Trie[pos][chpos])
			return ret;
		pos = Trie[pos][chpos];
	}
	return ret;
	// return ret + FindAllPrefix(pos);
}
void Insert(string s){
	int pos(1), len = int(s.length());
	for(int i = 0; i < len; ++i){
		++cnt[pos];
		int chpos = transfer(s[i]);
		if(!Trie[pos][chpos])
			Trie[pos][chpos] = ++VertexN;
		pos = Trie[pos][chpos];
	}
	++::end[pos];
}
void ClearAll(void){
	memset(Trie, 0, sizeof(Trie));
	memset(::end, 0, sizeof(::end));
	memset(cnt, 0, sizeof(cnt));
	VertexN = 0;
}
int transfer(char c){
	if(isdigit(c))return int(c) - int('0');
	if(isupper(c))return int(c) - int('A') + 10;
	if(islower(c))return int(c) - int('a') + 36;
	return INT_MAX;
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