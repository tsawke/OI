#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int n;
class Worker{
	public:
		int Distance;
		int Power;
	public:
		void InIt();
};
bool cmp(Worker x, Worker y);
void Worker ::InIt(){
	scanf("%d%d", &this -> Distance, &this -> Power);
}

class Index_{
	protected:
		Worker worker[1100];
		bool Road[110000];
		int n;
		int ans;
	public:
		void InIt(int n);
		
		void make();
		void show();
}index__;

void Index_ ::InIt(int n){
	for(int i=1; i<=n; i++)this -> worker[i].InIt();
	for(int i=1; i<=101000; i++)this -> Road[i] = false;
	this -> n = n;
	this -> ans = 1;
}

void Index_ ::make(){
	for(int s=1; s<=this -> n; s++){
		this -> Road[this -> worker[s].Distance] = true;
		for(int i=this -> worker[s].Distance, j=1; j<=this -> worker[s].Power; i++, j++)this -> Road[i] = true;
		for(int i=this -> worker[s].Distance, j=1; j<=this -> worker[s].Power; i--, j++)this -> Road[i] = true;
	}sort(this -> worker+1, this -> worker + this -> n + 1, cmp);
	for(int i=this -> worker[1].Distance; i<=this -> worker[n].Distance; i++){
		if(this -> Road[i])continue;
		++ans;
		while(!this -> Road[++i]);
	}
}
void Index_ ::show(){
	printf("%d\n", this -> ans);
}
int main(){scanf("%d",&n);
	index__.InIt(n);
	index__.make();
	index__.show(); 
	return 0;
}
bool cmp(Worker x, Worker y){
	return x.Distance < y.Distance;
}

