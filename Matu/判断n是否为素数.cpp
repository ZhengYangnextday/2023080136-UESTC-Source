#include <iostream>
#include<stdio.h>
#include<math.h>
double sqrt(int num)//牛顿迭代法(num^1/2 = a 转化为 a^2 - num = 0求方程的根）
{
    double guess_0 = 0.0;//第一代
    double guess_1 = 1.0;//第二代
    if (num < 0) {
        printf("error");
        return -1;
    }
    else if (num == 0)
    {
        return 0;
    }
    else if (num == (num/2) * (num/2))
    {
        return (num / 2);
    }
    else
    {
        do
        {
            guess_0 = guess_1;
            guess_1 = (guess_0 + num / guess_0) / 2;
        } while (guess_1 - guess_0 > 0.01 || guess_1 - guess_0 < -0.01);//迭代//2 * x_0 * (x - x_0) = y - (x_0^2 - a)
    }
    return (guess_1);
}
int main()
{
    int x;
    int j = 0;
    scanf_s("%d", &x);
    int *prime =new int[100000];//质数表
    int count = 0, count_0 = 0, count_1 = 0, count_3 = 0, count_4 = 0;//计数器，count_0,count_1作为小循环的判断条件，count_2,count_3作为大循环的判断条件
    prime[0] = 2;
    switch (x)
    {
    case 0:
    case 1:
        count = 0;
        break;
    case 2:
        count = 1;
        break;
    case 3:
        prime[1] = 3;
        count = 2;
        break;//排除1-3的情况
    default:
        count++;
        if (sqrt(x) > 9) {
            for (int i = 3; i <= sqrt(x); i++)
            {
                for (; j < count && prime[j] < sqrt(x); j++)
                {
                    count_1++;
                    count_3++;
                    if (x % prime[j] != 0)
                        count_4++;
                    if (i % prime[j] != 0)
                    {
                        count_0++;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                if (count_0 == count_1)
                {
                    prime[count] = i;
                    count++;
                }
                count_0 = 0;
                count_1 = 0;
                if (count_3 != count_4)
                {
                    printf("no");
                    break;
                }
            }
        }
        else
        {
            for (int i = 3; i < x + 1; i++)
            {
                for (int j = 0; j < count && prime[j] < sqrt(x) + 1; j++)
                {
                    count_1++;
                    count_3++;
                    if (x % prime[j] != 0)
                        count_4++;
                    if (i % prime[j] != 0)
                    {
                        count_0++;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                if (count_0 == count_1)
                {
                    prime[count] = i;
                    count++;
                }//质数表的录入
                count_0 = 0;
                count_1 = 0;
                if (count_3 != count_4)
                {
                    printf("no");
                    break;
                }//循环内判断是否为质数，不为后直接跳出循环
            }
        }
    }
    if (count_3==count_4)
    {
        printf("yes");
    }
    delete[] prime;
    return 0;
}//判断是否为质数