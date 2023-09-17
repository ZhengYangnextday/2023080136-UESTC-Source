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
    
    //码图第一题
    /*现在有一串字符串（长度不超过100），规定输入的字符串中只包含字母和*号。
    如果包含其他符号，则输出”error\n” 请编写程序，实现以下功能：
    除了字符串前后的*号之外，将串中的其他*号全部删除。 
    输出字符串之后要输出回车再结束程序。如果输入不符合要求，则输出”error”和回车。 
    假如输入的字符串是****A*BC*DEF*G********,
    删除串中的*号之后，字符串变成****ABCDEFG******** */
    char c[100];
    cin >> c;
    int len = strlen(c);
    int l = 0, r = 0;
    for (int i = 0; i < len; i++) {
        if (judge(c[i])) {
            l = i;
            if (c[i] != '*') {
                l = i;//第一个字符所在位置
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
                r = i;//最后一个字符所在位置
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
    }//全为'*'的情况
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