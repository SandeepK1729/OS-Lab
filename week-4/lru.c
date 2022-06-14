#include<stdio.h> 

int find_replace_index( int *a, int f, int *usage) { 
    int m, u = 1e9;
    for(int i = 0; i < f; i++) { 
        int v = a[i];
        
        if(v == -1)  return i;
        if(usage[v] < u) { u = usage[v]; m = i; } 
    } 
    return m; 
} 

int is_exist(int *a, int n, int t) { 
    for(int i = 0; i < n; i++) 
        if(a[i] == t)   return 1; 
    return 0;
}

int main() { 
    int h = 0, m = 0, usage[20] = { 0 };
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
            int idx = find_replace_index(frames, f, usage); 
            frames[idx] = c;    // replace the new page
            m++;                // miss = miss + 1 i.e, page faults 
        } 
        
        usage[c] = i;       // updates last usage with index
        
        printf("\n%d", c); 
        for(int i = 0; i < f; i++)  printf("\t%d", frames[i]);
    } 
    
    printf("\nno of hits : %d \nno of misses / faults : %d", h, m); 
    return 0; 
}