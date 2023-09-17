#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int* quicksort(int a[], int n) {
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
            *(a + n_l + 1 + i) = *(right + i);
        }
        return a;
    }
    else if (n == 1) {
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
    int n;
    cin >> n;
    int* num = (int*)malloc(sizeof(int) * n);
    if (num) {
        for (int i = 0; i < n; i++) {
            cin >> *(num + i);
        }
        quicksort(num, n);
        for (int i = 0; i < n - 1; i++) {
            cout << *(num + i) << ",";
        }
        cout << *(num + n - 1);
    }
    free(num);
    */
    char str[100];
    cin >> str;
    int i = 0;
    while (str[i] != '\0' && str[i + 1] != '\0' && str[i+2] != '\0') {
        cout << str[i] << str[i + 1] << "*";
        i += 2;
    }
    if (str[i + 2] == '\0') {
        cout << str[i] << str[i + 1] << endl;
        return 0;
    }
    else if (str[i + 1] == '\0') {
        cout << str[i] << endl;
        return 0;
    }
    else
    {
        cout << endl;
    }
}