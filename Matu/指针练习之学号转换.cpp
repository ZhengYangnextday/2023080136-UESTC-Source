#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
using namespace std;
#define min '0'
#define max '9'
int tens(int n) {
	int result = 1;
	for (int i = 0; i < n; i++) {
		result = result * 10;
	}
	return result;
}
int fun(const char* p, int result[])
{
	if (strlen(p) != 13)return 0;
	result[0] = result[1] = result[2] = result[3] = 0;
	for (int i = 0; i < strlen(p); i++) {
		if (*(p + i) > max || *(p + i) < min) {
			return 0;
		}
		else if (i <= 3)
		{			
			result[0] += tens(3 - i) * (*(p + i) - min);
		}
		else if (i <= 5) {
			result[1] += tens(5 - i) * (*(p + i) - min);
		}
		else if (i <= 9) {
			result[2] += tens(9 - i) * (*(p + i) - min);
		}
		else {
			result[3] += tens(12 - i) * (*(p + i) - min);
		}
	}
	if (result[1] != 0 && result[2] != 0 && result[3] != 0) {
		return 1;
	}
	else {
		return 0;
	}
}