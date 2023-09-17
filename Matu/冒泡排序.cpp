#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
/*
typedef struct list {
    int* num = NULL;
    struct list* next= NULL;
}List;
*/
int *quicksort(int a[] ,int n) {
    if (n > 1) {
        int left[100];
        int right[100];
        int n_l = 0, n_r = 0;
        int key = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] <= key) {
                *(left + n_l) = a[i];
                n_l++;
            }
            else {
                *(right + n_r) = a[i];
                n_r++;
            }
        }
        quicksort(left, n_l);
        for (int i = 0; i < n_l; i++) {
            *(a + i) = *(left + i);
        }
        *(a + n_l) = key;
        quicksort(right, n_r);
        for (int i = 0; i < n_r; i++) {
            *(a+ n_l + 1 + i) = *(right + i);
        }
        return a;
    }
    else if(n == 1){
        return a;
    }
    else
    {
        return 0;
    }
}
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
    */
    int a[10];
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    int* result = NULL;
    quicksort(a, 10);
    for (int i = 0; i < 9; i++) {
        cout << a[i] << ",";
    }
    cout << a[9];
}