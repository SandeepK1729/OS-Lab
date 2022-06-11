#include <stdio.h>
#include <stdlib.h> 

// process data type
typedef struct { 
    int n, p, bt, tat, wt; 
    /*  n -> name, 
        p -> priority,
        bt -> burst time 
        tat -> turn around time 
        wt -> waiting time 
        ct -> completion time 
    */ 
} process; 
// sorted with priority 
int by_prio(process *a, process *b) { 
    if( a->p == b -> p) return ( a -> bt > b -> bt); 
    return ( a -> p > b -> p ); 
}
// swap 
void swap(process *a ,process *b) { 
    process *tmp; 
    tmp -> n = a -> n;  tmp -> p = a -> n;  tmp -> bt = a -> bt; 
    a -> n = b -> n;    a -> p = b -> n;    a -> bt = b -> bt; 
    a -> n = b -> n;    a -> p = b -> n;    a -> bt = b -> bt; 
}
// sort processes
void sort(process *a, int n, int (*desc)(process *, process *)) { 
    for(int i = 0; i < n - 1; i++) 
        for(int j = i + 1; j < n; j++) 
            if( desc( a + i, a + j)) 
                swap( a + i, a + j); 
}

// display 
void display(process *a, int n) { 
    printf("\nP\tPrio\tbt\twt\ttat\n"); 
    for(int i = 0; i < n; i++) 
        printf("%d\t%d\t%d\t%d\t%d\n", (a + i) -> n, (a + i) -> p, (a + i) -> bt, (a + i) -> wt, (a + i) ->tat); 
} 
// main 
int main() { 
    int n; printf("Enter no of processes : "); scanf("%d", &n); 
    process a[n];
    // taking input
    
    printf("Enter priorities and burst times of process \n");
    for(int i = 0; i < n; i++) {  scanf("%d %d", &a[i].p, &a[i].bt); a[i].n = i + 1;  } 
    
    sort(a, n, by_prio);
    
    int total_wt = 0, total_tat = 0, wt = 0;
    for(int i = 0; i < n; wt += a[i].bt, i++) { 
        a[i].wt  = wt;                  total_wt  += a[i].wt;
        a[i].tat = a[i].wt + a[i].bt;   total_tat += a[i].tat; 
    } 
    display( a, n); 
    
    printf("\nAvg waiting time is %f\nAvg tat is %f\n", total_wt * 1.0 / n, total_tat * 1.0 / n);
    return 0; 
} 
    