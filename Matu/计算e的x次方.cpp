/*
��д���򣬼���
	e^x=1+x+(x^2)/(2!)+(x^3)/(3!)+(x^4)/(4!)+...+(x^n)/n!

˵����e^x��ʾe��x�η���2!��ʾ2�Ľ׳�

���������ʽҪ��
	�����ʽ��x n�س�
	e^x, x, n����double���ʹ洢��
	Ҫ�����С�����6λ��
	ֻ������������벻Ҫ��������ַ��������쳣�������nΪ�����������error
���磺
���룺3 10�س�
�����20.079665
���룺5.24 11�س�
�����187.210665
���룺5 -10
�����error
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