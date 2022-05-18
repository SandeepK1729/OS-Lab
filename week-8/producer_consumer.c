#include<stdio.h>

int main() {
    int d, n = 10, buffer[n], in = 0, out = 0, tmp;
    do {
        printf("\n\t1. Produce\n\t2. Consume\n\t3. Exit\nEnter your choice : "); scanf("%d", &d);
        if(d == 1) {
            if((in + 1) % n == out) printf("\nBuffer is Full");
            else {                  printf("\nEnter the value : ");   scanf("%d", &tmp); buffer[in] = tmp; in = (in + 1) % n; }
        }
        else if(d == 2) {
            if(in == out)   printf("\nBuffer is Empty");
            else {          printf("\nConsumed item is %d", buffer[out]);   out = (out + 1) % n; }
        }
    } while(d != 3);
    printf("\nProgram terminated...");
}