#include<stdio.h>
#include<stdlib.h>

// Process data type
typedef struct {
    int wt, tat, bt;
} process;

void print_process(process *arr, int n) {
    printf("Process\tbt\twt\ttat\n");
    for(int i = 0; i < n; i++) 
        printf("P%d\t%d\t%d\t%d\n", i + 1, (arr + i) -> bt, (arr + i) -> wt, (arr + i) -> tat);
}
int main() {
    int n;  printf("Enter the no of process : ");   scanf("%d", &n);
    process *arr = (process *) calloc(n, sizeof(process));

    printf("Enter the arriving time and burst time for n processes :\n");
    for(int i = 0; i < n; i++)  scanf("%d", &((arr + i) -> bt));
    
    // sort(arr, n, by_at);

    int wt_avg = 0, tat_avg = arr -> bt;   
    arr -> wt = 0;  arr -> tat = arr -> bt;

    for(int i = 1; i < n; i++) {
        (arr + i) -> wt  = (arr + i - 1) -> wt + (arr + i - 1) -> bt;
        (arr + i) -> tat = (arr + i) -> bt + (arr + i) -> wt;

        wt_avg += (arr + i) -> wt;
        tat_avg += (arr + i) -> tat;
    }
    print_process(arr, n);
    printf("average waiting time : %.2f,\naverage turn around time : %.2f", wt_avg * 1.0 / n, tat_avg * 1.0 / n);
    return 0;
}