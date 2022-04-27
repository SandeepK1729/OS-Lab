#include<stdio.h> 

typedef struct { 
    int n, bt, wt, tat; 
} process; 
void sjf(process *a, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i].bt > a[j].bt) {
                process tmp = {a[i].n, a[i].bt, a[i].wt, a[i].tat};
                a[i].n = a[j].n;    a[i].bt = a[j].bt;
                a[j].n = tmp.n;     a[j].bt = tmp.bt;
            }
        }
    }
}
void display(process *a, int n) { 
    printf("Process\tBT\tWT\tTAT\n"); 
    for(int i = 0; i < n; i++) 
        printf("P%d\t%d\t%d\t%d\n", a[i].n , a[i].bt, a[i].wt, a[i].tat); 
} 
int main() { 
    int n; 
    printf("Enter the no of procesess : "); scanf("%d", &n); 
    
    process a[n]; 
    printf("Enter the burst times of n processes : \n"); 
    for(int i = 0; i < n; i++) {    scanf("%d", &a[i].bt);  a[i].n = i; }
    sjf(a, n);
    int total_wt, total_tat; 
    a[0].wt = total_wt = 0; 
    a[0].tat = total_tat = a[0].bt;
    for(int i = 1; i < n; i++) { 
        a[i].wt = a[i - 1].wt + a[i - 1].bt;    total_wt += a[i].wt;
        a[i].tat = a[i - 1].tat + a[i].bt;      total_tat += a[i].tat;
    } 
    display(a, n); 
    printf("\nAvg waiting time is %f\nAvg tat is %f\n", total_wt * 1.0 / n, total_tat * 1.0 / n); 
}
    
    
