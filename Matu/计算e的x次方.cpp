/*
编写程序，计算
	e^x=1+x+(x^2)/(2!)+(x^3)/(3!)+(x^4)/(4!)+...+(x^n)/n!

说明：e^x表示e的x次方，2!表示2的阶乘

输入输出格式要求：
	输入格式：x n回车
	e^x, x, n均用double类型存储。
	要求输出小数点后6位。
	只输出运算结果，请不要输出其他字符，遇到异常情况（如n为负数），输出error
例如：
输入：3 10回车
输出：20.079665
输入：5.24 11回车
输出：187.210665
输入：5 -10
输出：error
*/
#include<stdio.h>
#include<math.h>
double factorial(double a)
{
double b = 0.0;
b = a * 1.0;
double result = 1.0;
for(int i = 1; i < b+1; ++i)
{
result = result * i;
}
return result;
}
int main()
{
double x=0.0, n=0.0;
scanf("%lf%lf",&x,&n);
if(n >= 0)
{
double e_x = 0.0;
for(double i = 0.0; i < n+1;i++)
{
e_x = e_x + (pow(x,i)/factorial(i));
}
printf("%.6f",e_x);
}
else
printf("error");
}