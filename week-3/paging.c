#include<stdio.h>
#include<stdlib.h>
int main() { 
	int memory_size; printf("Enter size of memory : "); scanf("%d", &memory_size); 
	int page_size  ; printf("Enter size of page   : "); scanf("%d", &page_size); 
	int no_of_pages = memory_size / page_size; printf("no of pages available are %d", no_of_pages); 

	int pages_available = no_of_pages; 
	int p; printf("\nEnter no of process : "); scanf("%d", &p); 
	int **process = (int **) calloc (p, sizeof(int*)); 
	for(int i = 0; i < p; i++) { 
		int pages;	printf("Enter pages required for process %d : ", i + 1); scanf("%d", &pages); 
		process[i] = (int *) calloc (pages, sizeof(int)); 

		if(pages > pages_available) { printf("Memory is full \n"); break; }
		pages_available -= pages; 
		
		printf("Enter pagetable for process %d : ", i + 1); 
		for(int j = 0; j < pages; j++) { scanf("%d", process[i] + j); }
	}

	int process_no;   	printf("Enter process no : ");	scanf("%d", &process_no); process_no--;
	int page_no; 		printf("Enter page no    : ");  scanf("%d", &page_no);    page_no--;
	int offset; 		printf("Enter offset     : ");  scanf("%d", &offset); 

	if(process_no > p)					printf("Invalid Process"); 
	else if(page_no > sizeof(process[process_no]) / sizeof(int)) printf("Invalid page"); 
	else if(offset > page_size)			printf("Invalid Offset");
	else 								printf("physical address is %d", process[process_no][page_no] * page_size + offset);
}