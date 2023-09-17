#include <iostream>
#include <stdio.h>
#include <math.h>
#include<string.h>
typedef struct student {
	char name[100];
	int gender;
	int birthday;
	double height;
	int grade_c;
	int grade_math;
}Stu;//定义结构
typedef Stu* Stu_P;
int main()
{
	int n, max_c = 0, max_math = 0, min_c = 100, min_math = 100, sum_c = 0, sum_math = 0, count_m_c = 0, count_n_c = 0, count_m_m = 0, count_n_m = 0;
	scanf_s("%d", &n);
	Stu* list = (Stu*)malloc(sizeof(Stu) * n);//开辟内存
	if (list) {
		for (int i = 0; i < n; i++) {
			scanf_s("%s", &((list + i)->name), 100);
			scanf_s("%d %d %lf %d %d", &((list + i)->gender), &((list + i)->birthday), &((list + i)->height), &((list + i)->grade_c), &((list + i)->grade_math));
		}//数据录入
		int* max_n_c = (int*)malloc(sizeof(int) * n);
		int* min_n_c = (int*)malloc(sizeof(int) * n);
		int* max_n_math = (int*)malloc(sizeof(int) * n);
		int* min_n_math = (int*)malloc(sizeof(int) * n);
		if (max_n_c && min_n_c && max_n_math && min_n_math) {
			for (int i = 0; i < n; i++) {
				sum_c += (list + i)->grade_c;
				sum_math += (list + i)->grade_math;
				if ((list + i)->grade_c > max_c)
				{
					max_c = (list + i)->grade_c;
					count_m_c = 0;
					*(max_n_c + count_m_c) = i;
				}
				else if ((list + i)->grade_c == max_c) {
					count_m_c++;
					*(max_n_c + count_m_c) = i;
				}//判断C语言最大值
				if((list + i)->grade_c < min_c)
				{
					min_c = (list + i)->grade_c;
					count_n_c = 0;
					*(min_n_c + count_n_c) = i;
				}
				else if ((list + i)->grade_c == min_c) {
					count_n_c++;
					*(min_n_c + count_n_c) = i;
				}//判断C语言最小值
				if ((list + i)->grade_math > max_math)
				{
					max_math = (list + i)->grade_math;
					count_m_m = 0;
					*(max_n_math + count_m_m) = i;
				}
				else if ((list + i)->grade_math == max_math) {
					count_m_m++;
					*(max_n_math + count_m_m) = i;
				}//判断数学最大值
				if ((list + i)->grade_math < min_math)
				{
					min_math = (list + i)->grade_math;
					count_n_m = 0;
					*(min_n_math + count_n_m) = i;
				}
				else if ((list + i)->grade_math == min_math) {
					count_n_m++;
					*(min_n_math + count_n_m) = i;
				}//判断数学最小值
			}
		}
		//输出
		printf("C_average:%d\n", sum_c / n);
		printf("C_max:%d\n", max_c);
		for (int i = 0; i <= count_m_c; i++) {
			printf("%s ", ((list + *(max_n_c + i))->name));
			printf("%d %d %.2f %d %d\n", (list + *(max_n_c + i))->gender, (list + *(max_n_c + i))->birthday, (list + *(max_n_c + i))->height, (list + *(max_n_c + i))->grade_c, (list + *(max_n_c + i))->grade_math);
		}
		printf("C_min:%d\n", min_c);
		printf("Calculus_average:%d\n", sum_math / n);
		printf("Calculus_max:%d\n", max_math);
		for (int i = 0; i <= count_m_m; i++) {
			printf("%s ", ((list + *(max_n_math + i))->name));
			printf("%d %d %.2f %d %d\n", (list + *(max_n_math + i))->gender, (list + *(max_n_math + i))->birthday, (list + *(max_n_math + i))->height, (list + *(max_n_math + i))->grade_c, (list + *(max_n_math + i))->grade_math);
		}
		printf("Calculus_min:%d\n", min_math);
		free(max_n_c);
		free(min_n_c);
		free(max_n_math);
		free(min_n_math);
		free(list);
	}
}