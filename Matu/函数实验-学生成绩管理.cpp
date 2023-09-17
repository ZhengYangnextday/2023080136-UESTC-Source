#include <iostream>
#include <fstream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct student
{
	int id;
	char name[50];
	float chinese;
	float math;
	float english;
	float sum;
}student;
/*输入参数：字符串name是要打开的文件名称。输出参数：stu是读出的学生的详细信息。函数的返回值：学生人数.任何错误返回0*/
int ReadStuInfoFromFile(char* name, student** stu) {
	//ifstream file(name, ios::in | ios::binary);
	ifstream file(name);
	if (file) {
		int number;
		file.read((char*)&number, sizeof(number));
		*stu = (student*)malloc(number * sizeof(student));
		if (*stu) {
			if (number >= 0){
				for (int i = 0; i < number; i++) {
					//file >> (*stu + i)->id >> (*stu + i)->name >> (*stu + i)->chinese >> (*stu + i)->math >> (*stu + i)->english;
					file.read((char*)(*stu + i), sizeof(student));
					if ((*stu + i)->chinese <= 0 || (*stu + i)->math <= 0 || (*stu + i)->english <= 0) {
						return 0;
					}
					for (int j = 0; j < i; j++) {
						if ((*stu + i)->id == (*stu + j)->id) {
							return 0;
						}
					}
					(*stu + i)->sum = (*stu + i)->chinese + (*stu + i)->math + (*stu + i)->english;
				}
				return number;
			}
			else {
				return 0;
			}
		}	
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

/*输入参数：stu是全班学生信息，n是人数。输出参数：3科平均成绩不及格人名单noPassStudent,不及格人数m.操作成功返回0，失败返回-1*/
int NoPass(student stu[], int n, student** noPassStudent, int* m) {
	int* nopass = (int*)malloc(n * sizeof(int));
	int count = 0;
	if (stu) {
		if (nopass) {
			for (int i = 0; i < n; i++) {
				if (stu[i].sum < 180 || stu[i].chinese < 60 || stu[i].math < 60 || stu[i].english < 60) {
					*(nopass + count) = i;
					count++;
				}
			}
			*m = count;
			*noPassStudent = (student*)malloc(count * sizeof(student));
			if (*noPassStudent) {
				for (int i = 0; i < count; i++) {
					(*noPassStudent + i)->id = (stu + nopass[i])->id;
					strcpy_s((*noPassStudent + i)->name, (stu + nopass[i])->name);
					(*noPassStudent + i)->chinese = (stu + nopass[i])->chinese;
					(*noPassStudent + i)->math = (stu + nopass[i])->math;
					(*noPassStudent + i)->english = (stu + nopass[i])->english;
					(*noPassStudent + i)->sum = (stu + nopass[i])->sum;
				}
				free(nopass);
				return 0;
			}
			else {
				return -1;
			}
		}
		else {
			return -1;
		}
	}
	else {
		return -1;
	}
}

/*输入参数：stu是全班学生信息，n是人数。输出参数：3科平均成绩及格人名单PassStudent,及格人数m.操作成功返回0，失败返回-1*/
int Pass(student stu[], int n, student** PassStudent, int* m) {
	int* pass = (int*)malloc(n * sizeof(int));
	int count = 0;
	if (stu) {
		if (pass) {
			for (int i = 0; i < n; i++) {
				if (stu[i].sum >= 180 && stu[i].chinese >= 60 && stu[i].math >= 60 && stu[i].english >= 60) {
					*(pass + count) = i;
					count++;
				}
			}
			*m = count;
			*PassStudent = (student*)malloc(count * sizeof(student));
			if (*PassStudent) {
				for (int i = 0; i < count; i++) {
					(*PassStudent + i)->id = (stu + pass[i])->id;
					strcpy_s((*PassStudent + i)->name, (stu + pass[i])->name);
					(*PassStudent + i)->chinese = (stu + pass[i])->chinese;
					(*PassStudent + i)->math = (stu + pass[i])->math;
					(*PassStudent + i)->english = (stu + pass[i])->english;
					(*PassStudent + i)->sum = (stu + pass[i])->sum;
				}
				free(pass);
				return 0;
			}
			else {
				return -1;
			}
		}
		else {
			return -1;
		}
	}
	else {
		return -1;
	}
}
void equal(student* a, student* b) {
	a->id = b->id;
	a->chinese = b->chinese;
	a->math = b->math;
	a->english = b->english;
	a->sum = b->sum;
	strcpy_s(a->name, b->name);
}
/*输入参数：stu是全班学生信息，n是人数。输出参数：按照总分/平均分排序后的结果也存储在stu中.操作成功返回0，失败返回-1*/
int SortStudents(student stu[], int n) {
	if (stu) {
		student temp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (stu[j].sum < stu[j + 1].sum) {
					student* a = stu + j;
					student* b = stu + j + 1;
					equal(&temp, a);
					equal(a, b);
					equal(b, &temp);
				}
			}
		}
		return 0;
	}
	else {
		return -1;
	}
}

/*输入参数：stu是全班学生信息，n是人数。操作成功返回0，失败返回-1。本函数在码图上不会进行检测，只是供同学们调试使用。*/
int PrintStudents(student stu[], int n) {
	if (stu) {
		for (int i = 0; i < n; i++) {
			cout << stu[i].id << " " << stu[i].name << " " << stu[i].chinese << " " << stu[i].math << " " << stu[i].english << " " << stu[i].sum << endl;
		}
		return 0;
	}
	else {
		return -1;
	}
}

/*输入参数：stu是全班学生信息，n是人数,id是待查找的学号。输出参数：rank是在班上的排名；stu是这个学生的详细信息。返回值：查找成功返回0，失败返回-1*/
int SearchStudent(student stu[], int n, int id, int* rank, student* rstu) {
	if (stu) {
		if (stu) {
			student temp;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n - i - 1; j++) {
					if (stu[j].sum < stu[j + 1].sum) {
						student* a = stu + j;
						student* b = stu + j + 1;
						equal(&temp, a);
						equal(a, b);
						equal(b, &temp);
					}
				}
			}
		}
		else {
			return -1;
		}
		for (int i = 0; i < n; i++) {
			if (i > 0 && stu[i].sum != stu[i - 1].sum) {
				*rank = i + 1;
			}
			if (i > 0 && stu[i].sum == stu[i - 1].sum) {
				*rank = i;
			}
			if (i == 0) {
				*rank = 1;
			}
			if (stu[i].id == id) {				
				student* a = stu + i;
				equal(rstu, a);
				return 0;
			}
		}
		return -1;
	}
	else {
		return -1;
	}
}