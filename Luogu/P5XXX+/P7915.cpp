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

int T;
void Cal(const int, const vector<int>);

int main(){
	T = read();
    for(int t = 1; t <= T; ++t){
        int N = read();
		N *= 2;
        vector<int> arr;
        for(int i = 1; i <= N; ++i)arr.push_back(read());
		Cal(N, arr);
    }
    return 0;
}
void Cal(const int N, const vector<int> arr){
    auto rangeL = find(arr.begin() + 1, arr.end(), arr.at(0));
	printf("\n\n\n%d\n\n\n", *rangeL);
	printf("MARK");
    vector<int> currentArrL(arr.begin() + 1, rangeL);//2~range-1
    vector<int> currentArrR(rangeL + 1, arr.end());  //range+1~N
	vector<bool>ans;//TRUE--L, FALSE--R
	printf("MARK");
    while(!currentArrL.empty() || !currentArrR.empty()){
		if(!currentArrL.empty()){
			if(currentArrR.empty()){
				if(currentArrL.front() == currentArrL.back()){
					ans.push_back(true), ans.push_back(true);
					currentArrL.pop_back();
					currentArrL.erase(currentArrL.begin());
				}
				else
					break;
			}
			else{
				if(currentArrL.size() != 1 && currentArrL.front() == currentArrL.back()){
					ans.push_back(true), ans.push_back(true);
					currentArrL.pop_back();
					currentArrL.erase(currentArrL.begin());
				}
				else if(currentArrL.front() == currentArrR.front()){
					ans.push_back(true), ans.push_back(false);
					currentArrL.erase(currentArrL.begin());
					currentArrR.erase(currentArrR.begin());
				}
				else if(currentArrL.back() == currentArrR.back()){
					ans.push_back(false), ans.push_back(true);
					currentArrL.pop_back();
					currentArrR.pop_back();
				}
				else if(currentArrR.size() != 1 && currentArrR.front() == currentArrR.back()){
					ans.push_back(false), ans.push_back(false);
					currentArrL.erase(currentArrL.begin());
					currentArrL.pop_back();
				}
				else
					break;
			}
		}
		else{
			if(currentArrR.front() == currentArrR.back()){
				ans.push_back(false), ans.push_back(false);
				currentArrR.pop_back();
				currentArrR.erase(currentArrR.begin());
			}
			else
				break;
		}
	}
	if((int)ans.size() == N){
		for(int i = 1; i <= N / 2; ++i)
			printf("%c", ans.at(i * 2 - 1) ? 'L' : 'R');
		for(int i = N / 2; i >= 1; --i)
			printf("%c", ans.at(i * 2) ? 'L' : 'R');
		printf("\n");
		return;
	}
	ans.clear();
	auto rangeR = find(arr.begin(), arr.end() - 1, arr.at(arr.size() - 1));
	printf("$$$$$  %d  $$$$$\n", *rangeR);
	currentArrL.clear();
	currentArrR.clear();
	currentArrL.resize(110000);
	currentArrR.resize(110000);
	
	::copy(arr.begin(), rangeR, currentArrL.begin());
	::copy(rangeR + 1, arr.end() - 1, currentArrR.begin());
	while(!currentArrL.empty() || !currentArrR.empty()){
		if(!currentArrL.empty()){
			if(currentArrR.empty()){
				if(currentArrL.front() == currentArrL.back()){
					ans.push_back(true), ans.push_back(true);
					currentArrL.pop_back();
					currentArrL.erase(currentArrL.begin());
				}
				else
					break;
			}
			else{
				if(currentArrL.size() != 1 && currentArrL.front() == currentArrL.back()){
					ans.push_back(true), ans.push_back(true);
					currentArrL.pop_back();
					currentArrL.erase(currentArrL.begin());
				}
				else if(currentArrL.front() == currentArrR.front()){
					ans.push_back(true), ans.push_back(false);
					currentArrL.erase(currentArrL.begin());
					currentArrR.erase(currentArrR.begin());
				}
				else if(currentArrL.back() == currentArrR.back()){
					ans.push_back(false), ans.push_back(true);
					currentArrL.pop_back();
					currentArrR.pop_back();
				}
				else if(currentArrR.size() != 1 && currentArrR.front() == currentArrR.back()){
					ans.push_back(false), ans.push_back(false);
					currentArrL.erase(currentArrL.begin());
					currentArrL.pop_back();
				}
				else
					break;
			}
		}
		else{
			if(currentArrR.front() == currentArrR.back()){
				ans.push_back(false), ans.push_back(false);
				currentArrR.pop_back();
				currentArrR.erase(currentArrR.begin());
			}
			else
				break;
		}
	}
	if((int)ans.size() == N){
		for(int i = 1; i <= N / 2; ++i)
			printf("%c", ans.at(i * 2 - 1) ? 'L' : 'R');
		for(int i = N / 2; i >= 1; --i)
			printf("%c", ans.at(i * 2) ? 'L' : 'R');
		printf("\n");
		return;
	}
	printf("-1\n");
	return;
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