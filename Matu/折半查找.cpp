#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    /*
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
    */
    int n = 0;
    cin >> n;
    int* num = (int*)malloc(sizeof(int) * n);
    if (num) {
        for (int i = 0; i < n ; i++) {
            scanf_s("%d", num + i);
            getchar();
        }
        int search = 0;
        cin >> search;
        int judgenumber = n / 2, left = 0, right = n - 1, count_0 = 15, count = 0;
        while (num[judgenumber] != search) {
            if (num[judgenumber] > search) {
                judgenumber = (judgenumber + left) / 2;
                right = judgenumber;
                count++;
                if (count == n||count == n+1) {
                    judgenumber = left;
                }
                else if (count >= n + 2) {
                    judgenumber = left - 1;
                }
            }
            else if(num[judgenumber] < search) {
                judgenumber = (judgenumber + right) / 2;
                left = judgenumber;
                count++;
                if (count == n || count == n+1) {
                    judgenumber = right;
                }
                else if(count >= n+2) {
                    judgenumber = right + 1;
                }
            }
        }
        printf("%d", judgenumber+1);
    }
    free(num);
}