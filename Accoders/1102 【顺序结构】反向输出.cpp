#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
vector<char>v;
int main(){
	char c; while(scanf("%c", &c) != EOF)v.push_back(c);
	while(*v.end() == '0')v.pop_back();
	reverse(v.begin(), v.end()); 
	while(*v.begin() == '0')v.erase(v.begin());
	vector<char>::iterator iter;
	for(iter = v.begin(); iter != v.end(); iter++){printf("%c", *iter);}
	return 0;
}
