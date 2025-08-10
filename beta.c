#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PASSWORD "admin123"
#define SGST_RATE 0.025
#define CGST_RATE 0.025
#define MAX_CUSTOMERS 100

typedef struct {
    int id;
    float totalBill;
    float sgst;
    float cgst;
    int roomBooked;  // 1 if room is booked, 0 if not
    char roomType[20];  // Room type (e.g., 'Single', 'Double', 'Suite')
    int stayDuration;   // Duration of stay in days
} Customer;

Customer customers[MAX_CUSTOMERS];
int customerCount = 0;
int customerIDCounter = 101;

void customerInterface();
void ownerInterface();

float calculateTotalTax();
float calculateProfit();

int main() {
    int choice;

    while (1) {
        printf("\n========= Hotel Management System =========\n");
        printf("1. Customer Interface\n");
        printf("2. Owner Interface\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                customerInterface();
                break;
            case 2:
                ownerInterface();
                break;
            case 3:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void customerInterface() {
    int item;
    float totalBill = 0.0;
    int customerID = customerIDCounter++;

    printf("\n========= Customer Interface =========\n");
    printf("Your Customer ID is: %d\n", customerID);

    printf("\nMenu:\n");
    printf("1. Dosa - Rs. 50\n");
    printf("2. Pongal - Rs. 60\n");
    printf("3. Idly - Rs. 30\n");
    printf("4. Poori - Rs. 40\n");
    printf("5. Masala Dosa - Rs. 70\n");
    printf("6. Podi Dosa - Rs. 60\n");
    printf("7. Sambar Vada - Rs. 50\n");
    printf("8. Exit Ordering\n");

    while (1) {
        printf("\nEnter the item number you want to order (8 to exit): ");
        scanf("%d", &item);

        if (item == 8) {
            break;
        }

        if (item < 1 || item > 7) {
            printf("Invalid choice. Try again.\n");
            continue;
        }

        int quantity;
        float price[] = {50, 60, 30, 40, 70, 60, 50};
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        totalBill += price[item - 1] * quantity;
    }

    // Ask if the customer wants to stay
    char stayOption;
    printf("\nDo you want to stay at the hotel? (y/n): ");
    scanf(" %c", &stayOption);

    if (stayOption == 'y' || stayOption == 'Y') {
        printf("\nAvailable Room Categories:\n");
        printf("1. Single Room - Rs. 1000 per day\n");
        printf("2. Double Room - Rs. 1500 per day\n");
        printf("3. Suite Room - Rs. 3000 per day\n");

        int roomChoice;
        printf("\nSelect Room Type (1-3): ");
        scanf("%d", &roomChoice);

        int stayDuration;
        printf("Enter the duration of stay (in days): ");
        scanf("%d", &stayDuration);

        // Assign room type and price
        float roomPrice = 0.0;
        switch (roomChoice) {
            case 1:
                strcpy(customers[customerCount].roomType, "Single");
                roomPrice = 1000;
                break;
            case 2:
                strcpy(customers[customerCount].roomType, "Double");
                roomPrice = 1500;
                break;
            case 3:
                strcpy(customers[customerCount].roomType, "Suite");
                roomPrice = 3000;
                break;
            default:
                printf("Invalid choice. Room booking skipped.\n");
                break;
        }

        if (roomPrice > 0) {
            totalBill += roomPrice * stayDuration;
            customers[customerCount].roomBooked = 1;
            customers[customerCount].stayDuration = stayDuration;
        }
    }

    // Calculate taxes
    float sgst = totalBill * SGST_RATE;
    float cgst = totalBill * CGST_RATE;
    float grandTotal = totalBill + sgst + cgst;

    printf("\nTotal Bill: Rs. %.2f\n", totalBill);
    printf("SGST: Rs. %.2f\n", sgst);
    printf("CGST: Rs. %.2f\n", cgst);
    printf("Grand Total: Rs. %.2f\n", grandTotal);

    // Store customer data
    if (customerCount < MAX_CUSTOMERS) {
        customers[customerCount].id = customerID;
        customers[customerCount].totalBill = totalBill;
        customers[customerCount].sgst = sgst;
        customers[customerCount].cgst = cgst;
        customerCount++;
    } else {
        printf("Customer limit reached. Cannot save details.\n");
    }
}

void ownerInterface() {
    char password[20];
    printf("\n========= Owner Interface =========\n");
    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(password, PASSWORD) != 0) {
        printf("Incorrect password!\n");
        return;
    }

    printf("\nCustomer Bills:\n");
    for (int i = 0; i < customerCount; i++) {
        printf("Customer ID: %d, Total Bill: Rs. %.2f, SGST: Rs. %.2f, CGST: Rs. %.2f\n",
               customers[i].id, customers[i].totalBill, customers[i].sgst, customers[i].cgst);
        if (customers[i].roomBooked) {
            printf("Room Type: %s, Duration: %d days\n", customers[i].roomType, customers[i].stayDuration);
        }
    }

    printf("\nTotal Tax Paid: Rs. %.2f\n", calculateTotalTax());
    printf("Total Profit: Rs. %.2f\n", calculateProfit());
}

float calculateTotalTax() {
    float totalTax = 0.0;
    for (int i = 0; i < customerCount; i++) {
        totalTax += customers[i].sgst + customers[i].cgst;
    }
    return totalTax;
}

float calculateProfit() {
    float profit = 0.0;
    float costs[] = {30, 35, 15, 20, 40, 35, 25};  // Cost per item
    for (int i = 0; i < customerCount; i++) {
        float customerProfit = 0.0;
        for (int j = 0; j < 7; j++) {
            int quantity = customers[i].totalBill / costs[j];  // Assuming this logic for simplicity
            customerProfit += quantity * (costs[j] - 20);  // Subtracting fixed margin for profit
        }
        profit += customerProfit;
        // Add room profit
        if (customers[i].roomBooked) {
            float roomPrice = 0.0;
            if (strcmp(customers[i].roomType, "Single") == 0) {
                roomPrice = 1000;
            } else if (strcmp(customers[i].roomType, "Double") == 0) {
                roomPrice = 1500;
            } else if (strcmp(customers[i].roomType, "Suite") == 0) {
                roomPrice = 3000;
            }
            profit += roomPrice * customers[i].stayDuration;
        }
    }
    return profit;
}