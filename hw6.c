/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

// calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}


int knapsack(int numItems, int values[], int weights[], int capacity) {
    int dp[numItems + 1][capacity + 1];

    for (int i = 0; i <= numItems; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[numItems][capacity];
}

int main() {
    int numItems;
    printf("Number of items: ");
    scanf("%d", &numItems);

    int values[numItems];
    printf("Item values:\n");
    for (int i = 0; i < numItems; i++) {
        scanf("%d", &values[i]);
    }

    int weights[numItems];
    printf("Item weights:\n");
    for (int i = 0; i < numItems; i++) {
        scanf("%d", &weights[i]);
    }

    int capacity;
    printf("Knapsack weight capacity: ");
    scanf("%d", &capacity);

    int result = knapsack(numItems, values, weights, capacity);
    printf("Maximum value: %d\n", result);

    return 0;
}
