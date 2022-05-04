#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int b, l, *a;
} segment;
void print_segmentation_table(segment *s, int n) {
    printf("\nS.no\tbase address\tlimit\n");
    for(int i = 0; i < n; i++)  
        printf("%d\t\t\t%d\t\t\t%d\n", i + 1, s[i].b, s[i].l);
}
int query(segment *s, int n) {
    int s_no, p_ad;
    printf("Enter the Segment no : ");          scanf("%d", &s_no);	s_no--;
    printf("Enter the physical address : ");    scanf("%d", &p_ad);

    printf("The value is %d", s[s_no].a[p_ad - s[s_no].b]);

    char c;
    printf("\nEnter Y to continue or any other to stop : ");  scanf("%c", &c);
    return c == 'Y';
}
int main() {
    int n; printf("Enter the no of segments : ");   scanf("%d", &n);
    segment s[n];

    for(int i = 0; i < n; i++) {
        printf("Enter the details of segment %d : \n", i + 1);
        printf("\tEnter base address : ");  scanf("%d", &s[i].b);
        printf("\tEnter limit : ");         scanf("%d", &s[i].l);

        s[i].a = (int *) calloc(s[i].l, sizeof(int));

        printf("\tEnter the address values : ");
        for(int j = 0; j < s[i].l; j++)     scanf("%d", &s[i].a[j]);
    }
    print_segmentation_table(s, n);

    while(query(s, n)) ;
    return 0;
}   