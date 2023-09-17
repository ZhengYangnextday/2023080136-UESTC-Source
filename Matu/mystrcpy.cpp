#include <iostream>
using namespace std;
void my_strcpy(char* destination, char* source) {
    if (destination && source){
    int i = strlen(destination);
    int j = 0;
    for (j = 0; *(source+j) != '\0'; j++) {
        *(destination + j) = *(source + j);
        if (*(source+j) == ' ')break;
    }
    if (i < j) {
        *(destination + j+1) = '\0';
    }}else{cout<<"error";}
    return;
}