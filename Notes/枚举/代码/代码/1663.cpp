#include <stdio.h>
 
int is_in_input(int *arr ,int n)
{
    while (n)
    {
        if (arr[n % 10] != 1)
        {
            return 0;
        }
        n /= 10;
    }
    return 1;
}
int a[11];
int main()
{
    int n, temp;
    int cnt = 0;
 
    scanf("%d",&n);
    for (int i = 0; i < n; i ++)
    {
        scanf("%d",&temp);
        a[temp] = 1;
    }
 
    for (int j = 111; j <= 999; j++)
    {
        for (int k = 11; k <= 99; k++)
        {
            if ((!is_in_input(a, k))||(!is_in_input(a, j)))
            {
                continue;
            }
            int one = j * (k % 10);
            int second = j * (k / 10);
            int result = j * k;
            if (one > 999 || second > 999 || result > 9999)
            {
                continue;
            }
             
            if ((!is_in_input(a, second))||(!is_in_input(a, one))||(!is_in_input(a, result)))
            {
                continue;
            }else
            {
                cnt ++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
 
}
