#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
    char str[300];
    int judge = 0;
    int i = 0;
    int count = 0;
    while (judge != 2) {
        str[i] = getchar();
        if(str[i] == '\n'){
            break;
        }
        i++;
    }
    str[i] = '\0';
    for (int j = 0; j < i; j++) {
        if (str[j] != ' ' && (str[j + 1] == ' ' || str[j + 1] == '\0')) {
            count++;
        }
    }
    cout << count << endl;
}
