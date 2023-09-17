#include <iostream>
#include <cstring>
using namespace std;
int cubic(int n) {
    int result = 1;
    for (int i = 0; i < 3; i++) {
        result = result * n;
    }
    return result;
}
int find(int n) {
    if (n < 1000 && n >= 100) {
        int c1, c2, c3, count = 0;
        for (int j = 100; j <= n; j++) {
            c1 = j / 100;
            c2 = j / 10 % 10;
            c3 = j % 100 % 10;
            if ((cubic(c1) + cubic(c2) + cubic(c3)) == j) {
                count++;
            }
        }
        return count;
    }else {
        return 0;
    }
    
}