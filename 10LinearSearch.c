#include <stdio.h>
#include <conio.h>

void main()
{
	int n, i, search, found = 0, arr[100];
	clrscr();
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	printf("Enter %d elements:\n", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Enter the number to search: ");
	scanf("%d", &search);
	for (i = 0; i < n; i++)
	{
		if (arr[i] == search)
		{
			printf("Position = %d", i + 1);
			found = 1;
			break;
		}
	}
	if (!found)
	{
		printf("Number %d is not in the array.\n", search);
	}
	getch();
}
