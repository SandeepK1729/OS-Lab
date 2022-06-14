#include<stdio.h>

int main() { 
    int n, max = 0, size, tmp, sb, cp, seek = 0; 
    
    printf("Enter no of requests : ");  scanf("%d", &n);
    printf("Enter size of disk : ");    scanf("%d", &size);

    int rq[size]; rq[0] = 1;
    for(int i = 1; i < size; i++)   	rq[i] = 0;
    
    printf("Enter requests : "); 
    for(int i = 0; i < n; i++) { 
        scanf("%d", &tmp);              rq[tmp] = 1;
        if(max < tmp) max = tmp;
    }

    printf("Enter starting position : ");  scanf("%d", &sb); //cp = sb;

    // left movement of disk from starting position
    for(cp = sb; cp >= 0; cp--) {
        if(rq[cp] == 0) continue;

		rq[cp] = 0;
        printf("\n%d \t %d \t %d", sb, cp, sb - cp);
        seek += sb - cp;
        sb = cp;
    }

    // right movement
    for(cp = 0; cp <= max; cp++) {
        if(rq[cp] == 0) continue;

        printf("\n%d \t %d \t %d", sb, cp, cp - sb);
        seek += cp - sb;
        sb = cp;
    }

    printf("\n\nTotal seek : %d", seek);
}