
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int N=20;   //最多放皇后的个数
int q[N];         //各皇后所在的行号
int cont = 0;     //统计解得个数
//输出一个解

void print(int n)
{
  int i,j;
cont++;
  printf("第%d个解：",cont);
  for(i=1;i<=n;i++)
         printf("(%d,%d)",i,q[i]);
  printf("\n");
  for(i=1;i<=n;i++)        //行
  {               
         for(j=1;j<=n;j++)   //列
         {
                if(q[i]!=j)
                       printf("x");
                else
                       printf("Q");  
         }
         printf("\n");
  }
}
//检验第i行的k列上是否可以摆放皇后
int find(int i,int k) 
{
  int j=1;
  while(j<i)  //j=1~i-1是已经放置了皇后的行
  {
         //第j行的皇后是否在k列或(j,q[j])与(i,k)是否在斜线上
         if(q[j]==k ||abs(j-i)==abs(q[j]-k))
                return 0;
         j++;
  }
  return 1;
}
//放置皇后到棋盘上
void place(int k,int n) 
{
  int j;
  if(k>n)
         print(n);
  else
  {
         for(j=1;j<=n;j++)   //试探第k行的每一个列
         {
                if(find(k,j))
                {
             q[k] = j;
                place(k+1,n);  //递归总是在成功完成了上次的任务的时候才做下一个任务
                }
         }
  }
}
 
int main(void)
{
 clock_t start,finish;
  int n;
  printf("请输入皇后个数：");
  scanf("%d",&n);
  start = clock();
  printf("\n使用非递归回溯法解决 %d 皇后问题时的运行情况\n",n);    
  place(1,n);
  finish = clock();
  printf("共有 %d 种不同的排列 计算用时%.2fms \n",cont, (double) (finish - start));
  system("pause");
  return 0;
}