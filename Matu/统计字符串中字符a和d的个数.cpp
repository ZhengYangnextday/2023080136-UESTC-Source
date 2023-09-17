#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    char str[50];
    int count_a = 0, count_d = 0;
    cin >> str;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a') {
            count_a++;
        }
        else if(str[i]=='d') {
            count_d++;
        }
    }
    cout << "a:" << count_a << ",d:" << count_d << endl;
}