#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
typedef struct Person {
    int no;
    int age;
    int height;
}Person;
void exchange(Person* a, Person* b) {
    int temp;
    temp = a->no;
    a->no = b->no;
    b->no = temp;
    temp = a->age;
    a->age = b->age;
    b->age = temp;
    temp = a->height;
    a->height = b->height;
    b->height = temp;
}
void sort(Person* array, int n) {
    if (array && n > 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if ((array + j)->no > (array + j + 1)->no) {
                    exchange((array + j), (array + j + 1));
                }
                else if ((array + j)->no == (array + j + 1)->no) {
                    if ((array + j)->age > (array + j + 1)->age) {
                        exchange((array + j), (array + j + 1));
                    }
                    else if ((array + j)->age == (array + j + 1)->age) {
                        if ((array + j)->height > (array + j + 1)->height) {
                            exchange((array + j), (array + j + 1));
                        }
                    }
                }
            }
        }
    }
    else {
        cout << "error";
        return;
    }
}