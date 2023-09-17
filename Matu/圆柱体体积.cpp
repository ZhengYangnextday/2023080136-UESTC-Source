#include <stdio.h>
#include <math.h>
int main()
{
double r,h,s,v;
const double pi=3.14;
scanf("%lf%lf",&r,&h);
s = pi*(r*r);
v = s*h;
printf("area=%.2f,volume=%.2f",s,v);
return 0;
}
