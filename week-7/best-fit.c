#include<stdio.h>
#include<limits.h>

typedef struct { int n, size, block_index; } file;
typedef struct { int size, is_occupied; } block;

int main() {
    int b; printf("Enter no of blocks : ");  scanf("%d", &b);
    block blocks[b];
    printf("Enter block sizes of %d blocks : ", b); 
    for(int i = 0; i < b; i++) { 
        scanf("%d", &blocks[i].size); 
        blocks[i].is_occupied = 0;
    } 

    int f; printf("Enter no of files : ");   scanf("%d", &f);
    file files[f]; 
    printf("Enter file sizes of %d files : ", f);
    for(int i = 0; i < f; i++) { scanf("%d", &files[i].size); }

    printf("\nFile no\tFile size\tBlock no\tBlock size\tFragment\n");
    for(int i = 0; i < f; i++) {
        int idx, j = -1, frag = 0, min_frag = INT_MAX;
        
        while(j++ < b) {
            if(!blocks[j].is_occupied) {
                frag = blocks[j].size - files[i].size;
                
                if(frag < 0)    continue;
                if(min_frag > frag) { idx = j; min_frag = frag; }
            }
        }
        blocks[idx].is_occupied = 1;
        
        files[i].block_index = idx;
        blocks[idx].is_occupied = 1;

        printf("%d\t\t%d\t\t\t%d\t\t\t", i + 1, files[i].size, idx + 1);
        if(idx == -1)   printf("-\t\t-\n");
        else            printf("%d\t\t\t%d\n", blocks[idx].size, blocks[idx].size - files[i].size);
    }
}