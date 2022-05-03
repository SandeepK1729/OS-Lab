#include <stdio.h>
#include <stdlib.h> 

// process data type
typedef struct { 
    int n, p, bt, tat, wt, ct; 
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
// sorted with name 
int by_process( process *a, process *b ) { 
    return ( a -> n > b -> n ); 
}
// sort processes
void sort(process *a, int n, int (*desc)()) { 
    for(int i = 0; i < n - 1; i++) 
        for(int j = i + 1; j < n; j++) 
            if( desc( a + i, a + j)) 
                swap( a + i, a + j); 
}
// swap 
void swap(process *a  process *b) { 
    process *tmp; 
    tmp -> n = a -> n;  tmp -> p = a -> n;  tmp -> bt = a -> bt; 
    a -> n = b -> n;    a -> p = b -> n;    a -> bt = b -> bt; 
    a -> n = b -> n;    a -> p = b -> n;    a -> bt = b -> bt; 
}
// display 
void display(process *a, int n) { 
    printf("\nP\tPrio\tbt\tct\ttat\twt\n"); 
    for(int i = 0; i < n; i++) 
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", (a + i) -> n, (a + i) -> p, (a + i) -> bt, (a + i) -> ct, (a + i) ->tat, (a + i) -> wt); 
} 
// main 
int main() { 
    int n; printf("Enter n : "); scanf("%d", &n); 
    process *a = (process*) calloc ( n, sizeof(process) ); 
    // taking input
    for(int i = 0; i < n; i++) { 
        printf("Enter priority and burst time of process %d", i + 1); 
        scanf("%d %d", &(a + i) -> p, &(a + i) -> bt); 
    } 
    
    sort(a, n, by_prio);
    
    a -> wt = a -> tat = 0; 
    a -> ct = a -> bt;
    /*
    ct  = tat + at
    wt = tat - by 
    n   p   bt  ct  tat wt
    1   1   2   2   2   0  
    2   4   3   5   5   2
    3   5   1   6   6   5
    4   6   4   10  10  6
    */
    for(int i = 1; i < n; i++) {
        (a + i) -> ct = (a + i) -> tat = (a + i - 1) -> tat + (a + i) -> bt; 
        (a + i) -> wt = (a + i + 1) -> wt + (a + i + 1) -> bt; 
    } 
    
    display( a, n); 
    return 0; 
} 
    