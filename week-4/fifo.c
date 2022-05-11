#include<stdio.h>

int is_page_exist(int *a, int n, int key) {
    for(int i = 0; i < n; i++) {
        if(a[i] == key)     return 1;
        if(a[i] == -1)      return -1;
    }
    return 0;
}
int main() {
    int n;          printf("Enter the length of string : ");    scanf("%d", &n);
    char s[n + 1];  printf("Enter the page string : ");         scanf("%s", s);
    int f;          printf("Enter the no. of frames : ");          scanf("%d", &f);
    int frames[f], beg = 0, current = 0;

    printf("Page");
    for(int i = 0; i < f; i++) { printf("\tf%d", i + 1); frames[i] = -1; }

    for(int i = 0; i < n; i++) {
        int p = s[i] - '0', decision = is_page_exist(frames, f, p);

        if(!decision) {
            frames[beg] = p;
            beg = (beg + 1) % f;
        }
        if(decision == -1) {
            frames[current] = p;
            current = (current + 1) % f;
        }

        printf("\n%d", p);
        for(int j = 0; j < f; j++)  printf("\t%d", frames[j]);
    }
    printf("\n");
    return 0;

}
