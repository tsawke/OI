#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct cor{int x,y;}robot;
int n,m; bool wall[110][110]={false}; 
int mov[110]; int len;
void Input(int &len){
	char c[110]; gets(c); len=strlen(c);
	for(int i=0; i<strlen(c); i++){
		switch(c[i]){
			case 'N':{
				mov[i+1]=1;
				break;
			}
			case 'S':{
				mov[i+1]=2;
				break;
			}
			case 'W':{
				mov[i+1]=3;
				break;
			}
			case 'E':{
				mov[i+1]=4;
				break;
			}
			default:break;
		}
	}
}
void InIt(int n,int m,cor &robot,int &len){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			char t=getchar(); //scanf("%c",&t);
			switch(t){
				case '#':{
					wall[i][j]=true;
					break;
				}
				case '.':{
					wall[i][j]=false;
					break;
				}
				case '*':{
					wall[i][j]=false;
					robot.x=i; robot.y=j;
					break;
				}
				default:{
					j--; break;
				}
			}
		}
	}char temp=getchar(); Input(len);
}

int main(){
//	for(int i=0; i<=100; i++)for(int j=0; j<=100; j++)wall[i][j]=true;
	scanf("%d%d",&n,&m); InIt(n,m,robot,len); //swap(robot.x,robot.y);
	for(int i=1; i<=len; i++){
		switch(mov[i]){
			case 1:{
				if(wall[--robot.x][robot.y])robot.x++;
				break;
			}
			case 2:{
				if(wall[++robot.x][robot.y])robot.x--;
				break;
			}
			case 3:{
				if(wall[robot.x][--robot.y])robot.y++;
				else i++;
				break;
			}
			case 4:{
				if(wall[robot.x][++robot.y])robot.y--;
				break;
			}
			default:break;
		}
	}
	printf("%d\n%d\n",robot.x,robot.y);
	return 0;
}

