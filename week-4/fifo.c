#include<stdio.h> 

int is_exist(int *a, int n, int t) { 
    for(int i = 0; i < n; i++) 
        if(a[i] == t)   return 1; 
    return 0;
}

int main() { 
    int h = 0, m = 0, replace_idx = 0;
    int p; printf("Enter the no of pages : "); scanf("%d", &p); 
    int pages[p];
    
    printf("Enter the pages : "); 
    for(int i = 0; i < p; i++)  scanf("%d", pages + i); 
    
    int f; printf("Enter the no of frames : "); scanf("%d", &f); 
    int frames[f]; 
    
    printf("Page"); 
    for(int i = 0; i < f; i++) { frames[i] = -1; printf("\tf%d", i + 1); }
    
    for(int i = 0; i < p; i++) { 
        int c = pages[i]; // current page 
        
        if(is_exist(frames, f, c))  h++; // if already exists 
        else { 
            frames[replace_idx] = c; 
            m++; replace_idx = (replace_idx + 1) % f;
        } 
        
        printf("\n%d", c); 
        for(int i = 0; i < f; i++)  printf("\t%d", frames[i]);
    } 
    
    printf("\nno of hits : %d \nno of misses / faults : %d", h, m); 
    return 0; 
}