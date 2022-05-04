#include <stdio.h>
#include <math.h>
int sost;
void gstinfo();
void ptladdr();
struct segtab
{
	int sno;
	int baddr;
	int limit;
	int val[10];
} st[10];
void gstinfo()
{
	int i, j;
	printf("\n\tEnter the size of the segment table: ");
	scanf("%d", &sost);

	for (i = 1; i <= sost; i++)
	{
		printf("\n\tEnter the information about segment: %d", i);
		st[i].sno = i;
		printf("\n\tEnter the base Address: ");
		scanf("%d", &st[i].baddr);
		printf("\n\tEnter the Limit: ");
		scanf("%d", &st[i].limit);
		for (j = 0; j < st[i].limit; j++)
		{
			printf("Enter the %d address Value: ", (st[i].baddr + j));
			scanf("%d", &st[i].val[j]);
		}
	}
}
void ptladdr()
{
	int i, swd, d = 0, n, s, disp, paddr;
	printf("\n\n\t\t\t SEGMENT TABLE \n\n");
	printf("\n\t      SEG.NO\tBASE ADDRESS\t      LIMIT \n\n");
	for (i = 1; i <= sost; i++)
		printf("\t\t%d    \t\t%d\t\t%d\n\n", st[i].sno, st[i].baddr, st[i].limit);
	printf("\n\nEnter the logical Address: ");
	scanf("%d", &swd);
	n = swd;
	while (n != 0)
	{
		n = n / 10;
		d++;
	}

	s = swd / pow(10, d - 1);
	disp = swd % (int)pow(10, d - 1);

	if (s <= sost)
	{
		if (disp < st[s].limit)
		{
			paddr = st[s].baddr + disp;
			printf("\n\t\tLogical Address is: %d", swd);
			printf("\n\t\tMapped Physical address is: %d", paddr);
			printf("\n\tThe value is: %d", (st[s].val[disp]));
		}
		else
			printf("\n\t\tLimit of segment %d is high\n\n", s);
	}

	else
		printf("\n\t\tInvalid Segment Address \n");
}
void main()
{
	char ch;
	gstinfo();
	do
	{
		ptladdr();
		printf("\n\t Do U want to Continue(Y/N)");
		// flushall();
		scanf("%c", &ch);
	} while (ch == 'Y' || ch == 'y');
}