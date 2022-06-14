#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct file {
    char name[20];
    int sb, n, *blocks;
} File;

int main() { 
    int n; printf("Enter no of files : "); scanf("%d", &n);
    File files[n];
    
    char file_name[n][20];
    for(int i = 0; i < n; i++) { 
        printf("\nEnter name of file %d : ", i + 1);                scanf("%s", files[i].name);
        printf("\nEnter starting block of file %d : ", i + 1);      scanf("%d", &files[i].sb);
        printf("\nEnter no of blocks of file %d : ", i + 1);        scanf("%d", &files[i].n);
        printf("\nEnter block values of %d blocks : ", files[i].n);
        files[i].blocks = (int *) calloc(files[i].n, sizeof(int));
        for(int j = 0; j < files[i].n; j++)                         scanf("%d", &files[i].blocks[j]);
    }
    char s[20];    printf("\n\nEnter file name to search : ");      scanf("%s", s);
    int i = 0;
    for(i; i < n; i++)  if(strcmp(s, files[i].name) == 0)    break;
    if(i == n)      printf("\nFile not found");
    else { 
        printf("\nfile name\tstarting block\tno of blocks\tvalues\n");
        printf("%s\t\t%d\t\t%d\t\t", files[i].name, files[i].sb, files[i].n);
        for(int j = 0; j < files[i].n; j++) printf("%d, ", files[i].blocks[j]);
    }
    return 0;
}