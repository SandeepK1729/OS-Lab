#include<stdio.h>

int is_page_exist(int *a, int n, int key) {
    for(int i = 0; i < n; i++) {
        if(a[i] == key)     return 1;
        if(a[i] ==0 -1)      return -1;
    }
    return 0;
}
int least_used_page(int *a, int n) {
    int min_page = a[0], idx = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] < min_page) {
            idx = i;    min_page = a[i];
        }
    }
    return idx;
}
int main() {
    int n;          printf("Enter the length of string : ");    scanf("%d", &n);
    char s[n + 1];  printf("Enter the page string : ");         scanf("%s", s);
    int f;          printf("Enter the no. of frames : ");       scanf("%d", &f);
    int frames[f], usage[n], beg = 0, current = 0;

    printf("Page");
    
    for(int i = 0; i < f; i++) { printf("\tf%d", i + 1); frames[i] = -1; }

    for(int i = 0; i < n; i++)  usage[i] = 0;
    for(int i = 0; i < n; i++) {
        int p = s[i] - '0', decision = is_page_exist(frames, f, p);

        if(decision == -1) {
            frames[beg++] = p;
        }
        else if(!decision) {
            current = least_used_page(usage, n);
            frames[current] = p;
            usage[current] = 1;
        }
        else {
            usage[i]++;
        }

        printf("\n%d", p);
        for(int j = 0; j < f; j++)  printf("\t%d", frames[j]);
    }
    printf("\n");
    return 0;

}