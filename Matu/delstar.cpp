#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
bool judge(char a) {
    if (a == '*' || (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')) {
        return true;
    }
    else { return false; }
}
int main()
{
    
    //��ͼ��һ��
    /*������һ���ַ��������Ȳ�����100�����涨������ַ�����ֻ������ĸ��*�š�
    ��������������ţ��������error\n�� ���д����ʵ�����¹��ܣ�
    �����ַ���ǰ���*��֮�⣬�����е�����*��ȫ��ɾ���� 
    ����ַ���֮��Ҫ����س��ٽ�������������벻����Ҫ���������error���ͻس��� 
    ����������ַ�����****A*BC*DEF*G********,
    ɾ�����е�*��֮���ַ������****ABCDEFG******** */
    char c[100];
    cin >> c;
    int len = strlen(c);
    int l = 0, r = 0;
    for (int i = 0; i < len; i++) {
        if (judge(c[i])) {
            l = i;
            if (c[i] != '*') {
                l = i;//��һ���ַ�����λ��
                break;
            }
        }
        else {
            cout << "error" << endl;
            return 0;
        }
    }
    for (int i = len - 1; i >= 0; i--) {
        if (judge(c[i])) {
            r = i;
            if (c[i] != '*') {
                r = i;//���һ���ַ�����λ��
                break;
            }
        }
        else {
            cout << "error" << endl;
            return 0;
        }
    }
    char result[100];
    int count = 0;
    if (r < l) {
        for (int i = 0; i <= l; i++) {
            result[i] = '*';
        }
        result[len] = '\0';
        cout << result << endl;
        return 0;
    }//ȫΪ'*'�����
    for (int i = 0; i < l; i++) {
        result[i] = '*';
    }
    for (int i = l; i <= r; i++) {
        if (judge(c[i])) {
            if (c[i] != '*') {
                result[l + count] = c[i];
                count++;
            }
        }
        else {
            cout << "error" << endl;
            return 0;
        }
    }
    for (int i = r + 1, j = 0; i <= len; i++, j++) {
        result[l + count + j] = c[i];
    }
    cout << result << endl;
}