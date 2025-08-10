#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void inputSales(float *sales, int days);
void addNewSale(float **sales, int *days);
void displaySales(float *sales, int days);
float calculateTotalSales(float *sales, int days);

int main() {
    int days;
    float *sales = NULL; // Pointer for dynamically allocated memory
    int choice;

    // Ask the user to input the number of days
    printf("Enter the number of days to track sales: ");
    scanf("%d", &days);

    // Allocate memory for the sales data
    sales = (float *)malloc(days * sizeof(float));
    if (sales == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Menu-driven program
    do {
        printf("\nMenu:\n");
        printf("1. Input Sales\n");
        printf("2. Add a New Sale\n");
        printf("3. Display Sales\n");
        printf("4. Calculate Total Sales\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputSales(sales, days);
                break;
            case 2:
                addNewSale(&sales, &days);
                break;
            case 3:
                displaySales(sales, days);
                break;
            case 4: {
                float total = calculateTotalSales(sales, days);
                printf("Total Sales: %.2f\n", total);
                break;
            }
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    // Free the allocated memory
    free(sales);
    return 0;
}

// Function to input sales data for all days
void inputSales(float *sales, int days) {
    for (int i = 0; i < days; i++) {
        printf("Enter sales for day %d: ", i + 1);
        scanf("%f", &sales[i]);
    }
}

// Function to add sales data for an additional day
void addNewSale(float **sales, int *days) {
    (*days)++;
    *sales = (float *)realloc(*sales, (*days) * sizeof(float));
    if (*sales == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter sales for day %d: ", *days);
    scanf("%f", &(*sales)[*days - 1]);
}

// Function to display sales data
void displaySales(float *sales, int days) {
    printf("Sales data:\n");
    for (int i = 0; i < days; i++) {
        printf("Day %d: %.2f\n", i + 1, sales[i]);
    }
}

// Function to calculate the total sales
float calculateTotalSales(float *sales, int days) {
    float total = 0.0;
    for (int i = 0; i < days; i++) {
        total += sales[i];
    }
    return total;
}
