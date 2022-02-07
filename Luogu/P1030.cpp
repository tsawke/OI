//C++11
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
#include <unistd.h>
#include <functional>
#include <string>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
// char mid[10], behind[10];
// int len;
// int FindPos(char);
// void cal(int, int, int, int, char);
string in, post;
void createPre(string, string);
int main(){
	cin>>in>>post;
	createPre(in, post);
	printf("\n");
    return 0;
}
void createPre(string in, string post){
	if(in.empty() || post.empty())return;
	printf("%c", *(post.end() - 1));
	int pos = in.find(*(post.end() - 1));
	// printf("---END = %c, pos = %d\n", *(post.end))
	createPre(in.substr(0, pos), post.substr(0, pos));
	createPre(in.substr(pos + 1), post.substr(pos, post.size() - 1 - pos));
}
// void cal(int lRangeL, int lRangeR, int rRangeL, int rRangeR, char root){
// 	if(lRangeL > lRangeR || rRangeL > rRangeR)return;
//     printf("%c---", root);
//     int pos = FindPos(root);
//     // int lLen = pos - lRangeL + 1;
// 	int rLen = rRangeR - pos + 1;


// 	char rootL = behind[pos - 1];
// 	char rootR = behind[rRangeL + rLen - 1];

// 	printf("LRL = %d, LRR = %d, RRL = %d, RRR = %d, rL = %c, rR = %c, R = %c, FP(R) = %d\n", lRangeL, lRangeR, rRangeL, rRangeR, rootL, rootR, root, FindPos(root));
// 	sleep(5);

// 	cal(lRangeL, FindPos(rootL) - 1, FindPos(rootL) + 1, pos - 1, rootL);
// 	cal(pos + 1, FindPos(rootR) - 1, FindPos(rootR) + 1, rRangeR, rootR);
// }
// int FindPos(char c){
// 	for(int i = 1; i <= ::len; ++i)
// 		if(::mid[i] == c)return i;
// 	return -1;
// }
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