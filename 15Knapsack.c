#include <stdio.h>
#include <conio.h>
#define MAX 20

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void knapSack(int n, int weight[], int value[], int W)
{
    int i, w;
    int K[MAX][MAX];
    int selected[MAX] = {0};

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weight[i - 1] <= w)
                K[i][w] = max(value[i - 1] + K[i - 1][w - weight[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    printf("\nMaximum value in KnapSack = %d\n", K[n][W]);

    i = n;
    w = W;
    while (i > 0 && w > 0)
    {
        if (K[i][w] != K[i - 1][w])
        {
            selected[i - 1] = 1;
            w = w - weight[i - 1];
        }
        i--;
    }

    printf("Items included:\n");
    for (i = 0; i < n; i++)
    {
        if (selected[i] == 1)
        {
            printf("Item %d (Weight=%d, Value=%d)\n", i + 1, weight[i], value[i]);
        }
    }
}

void main()
{
    int weight[MAX], value[MAX], n, W, i;
    clrscr();
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weights of items:\n");
    for (i = 0; i < n; i++)
    {
        printf("Weight of item %d: ", i + 1);
        scanf("%d", &weight[i]);
    }
    printf("Enter values of items:\n");
    for (i = 0; i < n; i++)
    {
        printf("Value of item %d: ", i + 1);
        scanf("%d", &value[i]);
    }
    printf("Enter maximum capacity of KnapSack: ");
    scanf("%d", &W);
    knapSack(n, weight, value, W);
    getch();
}
