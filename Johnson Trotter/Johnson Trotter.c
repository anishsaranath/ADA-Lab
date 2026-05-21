#include <stdio.h>

#define MAX 10
void printPermutation(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}

int findMC(int a[], int dir[], int n)
{
    int mc = 0;

    for (int i = 0; i < n; i++)
    {
        if (dir[i] == -1 && i != 0)
        {
            if (a[i] > a[i - 1] && a[i] > mc)
            {
                mc = a[i];
            }
        }

        if (dir[i] == 1 && i != n - 1)
        {
            if (a[i] > a[i + 1] && a[i] > mc)
            {
                mc = a[i];
            }
        }
    }

    return mc;
}

int findPosition(int a[], int n, int mc)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == mc)
        {
            return i;
        }
    }

    return -1;
}

void johnsonTrotter(int n)
{
    int a[MAX];
    int dir[MAX];

    int mc, pos, temp;

    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;

        dir[i] = -1;
    }

    printPermutation(a, n);

    while (1)
    {
        mc = findMC(a, dir, n);

        if (mc == 0)
        {
            break;
        }

        pos = findPosition(a, n, mc);

        if (dir[pos] == -1)
        {
            temp = a[pos];
            a[pos] = a[pos - 1];
            a[pos - 1] = temp;

            temp = dir[pos];
            dir[pos] = dir[pos - 1];
            dir[pos - 1] = temp;

            pos = pos - 1;
        }
        else
        {
            temp = a[pos];
            a[pos] = a[pos + 1];
            a[pos + 1] = temp;

            temp = dir[pos];
            dir[pos] = dir[pos + 1];
            dir[pos + 1] = temp;

            pos = pos + 1;
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] > mc)
            {
                dir[i] = -dir[i];
            }
        }

        printPermutation(a, n);
    }
}

int main()
{
    int n;

    printf("Enter n : ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
