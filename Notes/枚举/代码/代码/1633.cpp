#include<stdio.h>
 
int a[9][2];
int b[9] = {1234,2345,3456,4567,5678,6789,7891,8912,9123};
int main()
{
 
    int i,j,k,m,n;
    int flag = 0;
 
    for (i = 0 ; i < 9; i++)
    {
        scanf("%dA%dB",a[i],a[i]+1);
    }
    for (j = 1234 ; j <= 9876 ; j++)
    {
         
        int cnt = 0;
        int j_bit4[4] = {j/1000,j%1000/100,j%100/10,j%10};
        for (k = 0; k < 9; k++)
        {
            int bit_right = 0;
            int sum_right =0;
            int k_bit4[4] = {b[k]/1000,b[k]%1000/100,b[k]%100/10,b[k]%10};
 
            for (m = 0; m < 4; m++)
            {
                if (k_bit4[m] == j_bit4[m])
                {
                    bit_right++;
                }
                else
                {
                    for (n = 0 ; n < 4; n++)
                    {
                        if (k_bit4[n] == j_bit4[m])
                        {
                            sum_right++;
                        }
                    }
                }
 
            }
            if (a[k][0] != bit_right || a[k][1] != sum_right)
            {
                cnt ++;
                break;
                 
            }
 
        }
        if (cnt == 0&& flag == 0)
        {
             
            printf("%d\n",j);
            flag ++;
        }
    }
    return 0;
}
