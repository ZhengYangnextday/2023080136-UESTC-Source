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
    return list;//�����������ڶ�λΪ0�����һλΪ�����ĸ���
}
int main()
{
    /*��ָ����Χ֮�ڵ�����
��������������2���ո�ָ�������m��n�������2����֮������������������
Ҫ�����������m��n������������ÿո�ָ�(�������1�����������ҲҪ����ո񣩡�
�κβ��Ϸ����������"error"�� */
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