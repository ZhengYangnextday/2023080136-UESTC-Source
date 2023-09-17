#include <iostream>
#include <stdio.h>
using namespace std;
struct node {
    int data;
    struct node* next;
};
struct node* createList(int data[], int n) {
    struct node* first = (struct node*)malloc((n+1) * sizeof(struct node));
	if (first) {
		first->data = NULL;
		first->next = first + 1;
		for (int i = 1; i < n; i++) {
			(first + i)->data = data[i - 1];
			(first + i)->next = first + i + 1;
		}
		(first + n)->data = data[n - 1];
		(first + n)->next = NULL;
		return first;
	}
}