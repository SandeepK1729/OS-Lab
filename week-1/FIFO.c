#include<stdio.h> 

typedef struct { 
    int n, bt, wt, tat; 
} process; 

void display(process *a, int n) { 
    printf("Process\tBurst time\tWaiting time\tTurn around time\n"); 
    for(int i = 0; i < n; i++) 
        printf("P%d \t%d \t\t %d\t\t %d\n", a[i].n, a[i].bt, a[i].wt, a[i].tat); 
} 
int main() { 
    int n; printf("Enter the no of procesess : "); scanf("%d", &n); 
    
    process a[n]; 
    printf("Enter the burst times of n processes : \n"); 
    for(int i = 0; i < n; i++)   scanf("%d", &a[i].bt);
    
    int total_wt = 0, total_tat = 0, wt = 0;
    for(int i = 0; i < n; wt += a[i].bt, i++) { 
        a[i].wt  = wt;                  total_wt  += a[i].wt;
        a[i].tat = a[i].wt + a[i].bt;   total_tat += a[i].tat; 
    } 
    display(a, n); 
    printf("\nAvg waiting time is %f\nAvg tat is %f", total_wt * 1.0 / n, total_tat * 1.0 / n); 
}
    
    
