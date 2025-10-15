#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define SIZE 100

void main()
{
    int i, arr[SIZE], n, choice, element, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        clrscr();
        printf("\n1. Display Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Array: ");
                for(int i = 0; i < n; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 2:
                if (n == SIZE)
                {
                    printf("Array is full!\n");
                    break;
                }
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (0 to %d): ", n);
                scanf("%d", &pos);

                if(pos < 0 || pos > n)
                {
                    printf("Invalid position!\n");
                    break;
                }

                for(i = n; i > pos; i--)
                {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = element;
                n++;
                printf("Element inserted.\n");
                break;
            case 3:
                if(n == 0)
                {
                    printf("Array is empty!\n");
                    break;
                }
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);

                if(pos < 0 || pos >= n)
                {
                    printf("Invalid position!\n");
                    break;
                }

                for( i = pos; i < n - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }
                n--;
                printf("Element deleted.\n");
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
        getch(); // Pauses the screen until a key is pressed
    } while(choice != 4);
}
