#include <stdio.h>

int main() {
    int n;
    double capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%lf", &capacity);

    double profit[n], weight[n], ratio[n];
    for (int i = 0; i < n; i++) {
        printf("Item %d profit and weight: ", i + 1);
        scanf("%lf %lf", &profit[i], &weight[i]);
        ratio[i] = profit[i] / weight[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                double t = ratio[i]; ratio[i] = ratio[j]; ratio[j] = t;
                t = profit[i]; profit[i] = profit[j]; profit[j] = t;
                t = weight[i]; weight[i] = weight[j]; weight[j] = t;
            }
        }
    }
    double totalProfit = 0;
    for (int i = 0; i < n; i++) {
        if (capacity >= weight[i]) {
            capacity -= weight[i];
            totalProfit += profit[i];
        } else {
            totalProfit += profit[i] * (capacity / weight[i]);
            break;
        }
    }

    printf("Max profit: %.2lf\n", totalProfit);
    return 0;
}
