#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int* primecheck(int max) {
    int n = sqrt(max * 1.0) + 1;
    int* list = (int*)malloc(n * sizeof(int));
    int count = 0;
    for (int i = 2; i < n; i++) {
        bool judge = true;
        for (int j = 0; j < count; j++) {
            if (i % list[j] == 0) {
                judge = false;
                break;
            }
        }
        if (judge) {
            list[count] = i;
            count++;
        }
    }
    list[count] = 0;
    list[count + 1] = count;
    return list;//质数表，倒数第二位为0，最后一位为质数的个数
}
int main()
{
    /*求指定范围之内的素数
问题描述：输入2个空格分隔的整数m和n，求这个2个数之间的所有素数并输出。
要求输出不包含m和n，且输出数据用空格分隔(包括最后1个数据输出后也要输出空格）。
任何不合法是输入输出"error"。 */
    int m, n;
    cin >> m >> n;
    if (cin.fail()) {
        cout << "error";
        return 0;
    }
    int max = 0, min = 0;
    if (m < 0 || n < 0) {
        cout << "error";
        return 0;
    }else if (m > n + 1) {
        max = m;
        min = n;
    }else if(n > m + 1 ) {
        max = n;
        min = m;
    }
    else {
        return 0;
    }
    int* list = primecheck(max);
    int count = 0;
    for (int i = 0; i < sqrt(max * 1.0) + 1; i++) {
        if (list[i] == 0) {
            count = list[i + 1];
            break;
        }
    }
    for (int i = min + 1; i < max; i++) {
        bool judge = true;
        for (int j = 0; j < count; j++) {
            if ((i != list[j] && i % list[j] == 0 )|| i == 1) {
                judge = false;
                break;
            }
        }
        if (judge) {
            cout << i << " ";
        }
    }
}