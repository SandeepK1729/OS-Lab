#include<stdio.h>
#include<stdlib.h>


typedef struct {
    /*
    allo : allocation memory
    capa : maximum capacity
    need : capacity - allocated
    */
    //int allo[10], capa[10], need[10];
    int *allo, *capa, *need, is_executed;
} process;

int is_capable(int *a, int *b, int n) {
    int re = 1;
    for(int i = 0; i < n; i++) 
        re &= a[i] <= b[i];
    return re;
}

int main() {
    int n, r;
    printf("Enter the no of processes : ");  scanf("%d", &n);
    printf("Enter the no of resources : ");  scanf("%d", &r);

    int available[r];
    printf("Enter the available resources : \n");
    for(int i = 0; i < r; i++)  scanf("%d", available + i);

    process p[n];
    for(int i = 0; i < n; i++) {

        p[i].capa = (int *) calloc(r, sizeof(int));
        p[i].allo = (int *) calloc(r, sizeof(int));
        p[i].need = (int *) calloc(r, sizeof(int));
        p[i].is_executed = 0;

        printf("Enter the maximum capacities and allocation of resources of process %d : \n", i );
        for(int j = 0; j < r; j++) {
            scanf("%d %d", &p[i].capa[j], &p[i].allo[j]);
            available[j] -= p[i].allo[j];
            p[i].need[j] = p[i].capa[j] - p[i].allo[j];
        }
    }

    int remaining = n;


    while(remaining) {
        for(int i = 0; i < n; i++) {
            if( p[i].is_executed )  continue;
            
            if(is_capable( p[i].need, available, r)) {
                for(int j = 0; j < r; j++)  available[j] += p[i].allo[j];
                p[i].is_executed = 1;
                remaining--;
                printf("P%d -> ", i);
            }
        }
    }
    return 0;

}
