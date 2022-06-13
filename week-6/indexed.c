#include<stdio.h>
#include<string.h>

int main() { 
    int n; printf("Enter no of files : "); scanf("%d", &n);

    int block_sizes[n], starting_block[n], block_values[n][20];
    char file_name[n][20];
    for(int i = 0; i < n; i++) { 
        printf("\nEnter name of file %d : ", i + 1);                scanf("%s", file_name + i);
        printf("\nEnter starting block of file %d : ", i + 1);      scanf("%d", starting_block + i);
        printf("\nEnter no of blocks of file %d : ", i + 1);        scanf("%d", block_sizes + i);
        printf("\nEnter block values of %d blocks : ", block_sizes[i]);
        for(int j = 0; j < block_sizes[i]; j++)                     scanf("%d", &block_values[i][j]);
    }
    char s[20];    printf("\n\nEnter file name to search : ");      scanf("%s", s);
    int i = 0;
    for(i; i < n; i++)  if(strcmp(s, file_name[i]) == 0)    break;
    if(i == n)      printf("\nFile not found");
    else { 
        printf("\nfile name\tstarting block\tno of blocks\tvalues\n");
        printf("%s\t\t%d\t\t%d\t\t", file_name[i], starting_block[i], block_sizes[i]);
        for(int j = 0; j < block_sizes[i]; j++) printf("%d, ", block_values[i][j]);
    }
    return 0;
}