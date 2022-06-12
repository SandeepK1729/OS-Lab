#include<stdio.h>

typedef struct {
    int bt, ct, wt, tat;
} process;

// display 
void display(process *a, int n) { 
    printf("\nP\tbt\twt\ttat\n"); 
    for(int i = 0; i < n; i++) 
        printf("%d\t%d\t%d\t%d\n", i + 1, (a + i) -> bt, (a + i) -> wt, (a + i) ->tat); 
} 

int  main() {
    int n, max_bt = 0; printf("Enter the no. of processes : ");     scanf("%d", &n);

    process a[n];
    printf("enter the burst time of processes : ");
    for(int i = 0; i < n; i++) { 
        scanf("%d", &a[i].bt); 
        a[i].ct = a[i].bt;
        a[i].wt = a[i].tat = 0;
        if(max_bt < a[i].bt) max_bt = a[i].bt; 
    } 
    
    int tq; printf("Enter time quantum : "); scanf("%d", &tq); 
    int max_iter = (max_bt / tq) + 1, wt = 0; 

    /* 5
    bt  ct  wt  tat 
    10  5   0
    1   0   5
    2   
    5
    1
        5       1       2       5       1       5
    0       5       6       8       13      14      19*/
    for(int i = 0; max_iter ; i++) { 
        if(i == n) { max_iter--; i = 0; }

        if(a[i].ct == 0)    continue; 
        int current_bt = ((a[i].ct < tq) ? a[i].ct : tq);
        
        a[i].wt += (wt - a[i].tat); 
        wt = a[i].tat = (wt + current_bt);
        
        a[i].ct -= current_bt; 
    }
    
    display(a, n);
}