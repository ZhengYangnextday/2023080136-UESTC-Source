#include <iostream>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n = 0, n_0, count = 1, j, k, judge, j_0;
    scanf_s("%d", &n);
    if (n <= 1) {
        printf("error");
        return 0;
    }
    else {
        n_0 = (int)sqrt(n * 1.0) + 1;
        int* prime = (int*)malloc(sizeof(int) * n);
        if (prime != NULL) {
            *prime = 2;
            for (j = 3; j < n; j++)
            {
                judge = 1;
                j_0 = (int)sqrt(j * 1.0) + 1;
                for (k = 0; k < count && prime[k] < j_0; k++) {
                    if (!(j % *(prime + k))) {
                        judge = 0;
                        break;
                    }
                }
                if (judge) {
                    *(prime + count) = j;
                    count++;
                }
            }
            for (int m = 0; m < count; m++) {
                printf("%d,", prime[m]);
            }
        }
        free(prime);
    }
}