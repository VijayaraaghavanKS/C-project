#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Customer structure
typedef struct Customer_Details {
    char *name;               // Dynamically allocated name
    int days;
    int roomCost;
    int foodCost;
    int servicesCost;
    int totalCost;
} Customer;

// Global variables
Customer **customers = NULL;  // Pointer to dynamically allocated customer array
int customerCount = 0;
int totalEarnings = 0;
const char OWNER_PASSWORD[] = "admin123"; // Pre-defined password for owner

// Function prototypes
void bookRoom(Customer *cust);
void orderFood(Customer *cust);
void useHotelServices(Customer *cust);
void customerInterface();
void ownerInterface();
int validateOwnerPassword();
void viewTotalEarnings();
void viewAllCustomers();
void freeCustomerMemory(Customer *cust);

// Room Booking
void bookRoom(Customer *cust) {
    int roomType, days;
    printf("\nWelcome to Room Booking!\n");
    printf("We offer a variety of luxurious rooms to make your stay unforgettable. Please choose one:\n");
    printf("1. Suite - Rs. 2,500/day\n");
    printf("2. 2-Person Room - Rs. 1,500/day\n");
    printf("3. Single Room - Rs. 700/day\n");
    printf("Enter your choice: ");
    scanf("%d", &roomType);
    printf("How many days would you like to stay with us? ");
    scanf("%d", &days);
    cust->days = days;
    switch (roomType) {
        case 1: cust->roomCost = days * 2500; break;
        case 2: cust->roomCost = days * 1500; break;
        case 3: cust->roomCost = days * 700; break;
        default:
            printf("Invalid choice! But don't worry, we've assigned you a cozy Single Room.\n");
            cust->roomCost = days * 700;
    }
    printf("Room booked for %d days! Total Room Cost: Rs. %d\n", days, cust->roomCost);
}

// Food Ordering
void orderFood(Customer *cust) {
    int days = cust->days;
    int mealChoice, dinnerChoice;
    int breakfastCost = 100, lunchCost = 300, buffetDinnerCost = 500, roomServiceDinnerCost = 600;
    printf("\nLet's Talk About Food!\n");
    printf("We provide delicious meals to make your stay delightful.\n");
    for (int day = 1; day <= days; day++) {
        printf("\nDay %d - Start Your Day Right!\n", day);
        // Breakfast
        printf("Would you like a hearty breakfast? (1 for Yes, 0 for No): ");
        scanf("%d", &mealChoice);
        if (mealChoice == 1) {
            cust->foodCost += breakfastCost;
            printf("Breakfast added for Rs. %d. Current Food Cost: Rs. %d\n", breakfastCost, cust->foodCost);
        } else {
            printf("Breakfast skipped. Maybe tomorrow!\n");
        }
        // Lunch
        printf("How about a delightful lunch? (1 for Yes, 0 for No): ");
        scanf("%d", &mealChoice);
        if (mealChoice == 1) {
            cust->foodCost += lunchCost;
            printf("Lunch added for Rs. %d. Current Food Cost: Rs. %d\n", lunchCost, cust->foodCost);
        } else {
            printf("Lunch skipped. Don't miss our specials tomorrow!\n");
        }
        // Dinner
        printf("End your day with a splendid dinner? (1 for Yes, 0 for No): ");
        scanf("%d", &mealChoice);
        if (mealChoice == 1) {
            printf("Choose your dinner option (1 for Buffet - Rs. 500, 2 for Room Service - Rs. 600): ");
            scanf("%d", &dinnerChoice);
            if (dinnerChoice == 1) {
                cust->foodCost += buffetDinnerCost;
                printf("Buffet dinner added for Rs. %d. Current Food Cost: Rs. %d\n", buffetDinnerCost, cust->foodCost);
            } else if (dinnerChoice == 2) {
                cust->foodCost += roomServiceDinnerCost;
                printf("Room service dinner added for Rs. %d. Current Food Cost: Rs. %d\n", roomServiceDinnerCost, cust->foodCost);
            } else {
                printf("Invalid choice! Skipping dinner for now.\n");
            }
        } else {
            printf("Dinner skipped. Don't miss our chef's specials tomorrow!\n");
        }
    }
    printf("\nTotal Food Cost: Rs. %d\n", cust->foodCost);
}

// Hotel Services
void useHotelServices(Customer *cust) {
    int choice;
    int spaFee = 500, gymFee = 200, poolFee = 300, massageFee = 400, tourFee = 600;
    int totalServiceCost = 0;
    printf("\nExplore Our Premium Hotel Services\n");
    printf("Choose from these amazing options:\n");
    printf("1. Spa - Rs. %d\n2. Gym - Rs. %d\n3. Swimming Pool - Rs. %d\n4. Massage - Rs. %d\n5. Guided Tour - Rs. %d\n", spaFee, gymFee, poolFee, massageFee, tourFee);
    printf("Would you like to indulge in a Spa? (1 for Yes, 0 for No): ");
    scanf("%d", &choice);
    if (choice == 1) totalServiceCost += spaFee;
    printf("Want to sweat it out in our Gym? (1 for Yes, 0 for No): ");
    scanf("%d", &choice);
    if (choice == 1) totalServiceCost += gymFee;
    printf("Take a refreshing dip in our Swimming Pool? (1 for Yes, 0 for No): ");
    scanf("%d", &choice);
    if (choice == 1) totalServiceCost += poolFee;
    printf("Relax with a soothing Massage? (1 for Yes, 0 for No): ");
    scanf("%d", &choice);
    if (choice == 1) totalServiceCost += massageFee;
    printf("Discover the city with a Guided Tour? (1 for Yes, 0 for No): ");
    scanf("%d", &choice);
    if (choice == 1) totalServiceCost += tourFee;
    cust->servicesCost += totalServiceCost;
    printf("Services Total Cost: Rs. %d\n", totalServiceCost);
}

// Customer Interface
void customerInterface() {
    Customer *cust = (Customer *)malloc(sizeof(Customer));
    if (!cust) {
        printf("Memory allocation failed!\n");
        return;
    }

    cust->foodCost = 0;
    cust->servicesCost = 0;
    cust->totalCost = 0;

    printf("\nWelcome to Our Hotel!\n");
    printf("We're thrilled to have you here. Let's get started with your details.\n");
    cust->name = (char *)malloc(50 * sizeof(char));
    if (!cust->name) {
        printf("Memory allocation failed!\n");
        free(cust);
        return;
    }

    printf("Please enter your name: ");
    scanf(" %49[^\n]", cust->name);
    printf("\nThank you, %s! Let's proceed to plan your stay.\n", cust->name);

    bookRoom(cust);  // Book the room
    orderFood(cust); // Order food
    useHotelServices(cust); // Use hotel services

    // Calculate total cost (room + food + services)
    cust->totalCost = cust->roomCost + cust->foodCost + cust->servicesCost;

    // Store the customer data
    customers = (Customer **)realloc(customers, (customerCount + 1) * sizeof(Customer *));
    if (!customers) {
        printf("Memory allocation failed!\n");
        freeCustomerMemory(cust); 
        return;
    }
    customers[customerCount++] = cust;

    totalEarnings += cust->totalCost;  // Update total earnings

    printf("\nAll set, %s! Your stay details have been saved.\n", cust->name);

    // Provide option to generate the bill
    int choice;
    printf("Would you like to generate your bill now? (1 for Yes, 0 for No): ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("\n--- Generating Your Bill ---\n");
        cust->totalCost = cust->roomCost + cust->foodCost + cust->servicesCost;
        float cgst = cust->totalCost * 0.05;
        float sgst = cust->totalCost * 0.05;
        float totalTax = cgst + sgst;
        float finalTotal = cust->totalCost + totalTax;

        printf("Room Cost: Rs. %d\n", cust->roomCost);
        printf("Food Cost: Rs. %d\n", cust->foodCost);
        printf("Services Cost: Rs. %d\n", cust->servicesCost);
        printf("CGST (5%%): Rs. %.2f\n", cgst);
        printf("SGST (5%%): Rs. %.2f\n", sgst);
        printf("Total Tax: Rs. %.2f\n", totalTax);
        printf("Final Total (Including Tax): Rs. %.2f\n", finalTotal);
        printf("Thank you for staying with us, %s!\n", cust->name);
    }
}


// Validate Owner Password
int validateOwnerPassword() {
    char enteredPassword[50];
    printf("Enter Owner Password: ");
    scanf(" %49s", enteredPassword);
    if (strcmp(enteredPassword, OWNER_PASSWORD) == 0) {
        printf("Access Granted! Welcome, esteemed owner!\n");
        return 1;
    } else {
        printf("Invalid Password! Access Denied.\n");
        return 0;
    }
}

// View Total Earnings
void viewTotalEarnings() {
    printf("\nTotal Earnings\n");
    printf("Total earnings from all customers (Excluding Tax): Rs. %d\n", totalEarnings);

    float totalCGST = totalEarnings * 0.05;
    float totalSGST = totalEarnings * 0.05;
    float totalTax = totalCGST + totalSGST;
    float finalEarnings = totalEarnings + totalTax;

    printf("CGST (5%%): Rs. %.2f\n", totalCGST);
    printf("SGST (5%%): Rs. %.2f\n", totalSGST);
    printf("Total Tax Collected: Rs. %.2f\n", totalTax);
    printf("Final Earnings (Including Tax): Rs. %.2f\n", finalEarnings);
}

// View All Customers
void viewAllCustomers() {
    printf("\nAll Customer Details\n");
    if (customerCount == 0) {
        printf("No customers have checked in yet. Business is just warming up!\n");
        return;
    }
    for (int i = 0; i < customerCount; i++) {
        Customer *cust = customers[i];
        printf("\nCustomer %d:\n", i + 1);
        printf("Name: %s\n", cust->name);
        printf("Room Cost: Rs. %d\n", cust->roomCost);
        printf("Food Cost: Rs. %d\n", cust->foodCost);
        printf("Services Cost: Rs. %d\n", cust->servicesCost);
        printf("Total Cost (Excluding Tax): Rs. %d\n", cust->totalCost);
        printf("\n");
    }
}

// Free Customer Memory
void freeCustomerMemory(Customer *cust) {
    if (cust) {
        free(cust->name);
        free(cust);
    }
}

// Owner Interface
void ownerInterface() {
    if (!validateOwnerPassword()) return;

    int choice;
    do {
        printf("\nOwner Interface\n");
        printf("1. View Total Earnings\n");
        printf("2. View All Customers\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewTotalEarnings();
                break;
            case 2:
                viewAllCustomers();
                break;
            case 3:
                printf("Exiting Owner Interface. Have a great day!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);
}

// Main Function
int main() {
    int choice;
        printf("Welcome to Our GOAT Hotel Management System!\n");
        printf("We are delighted to serve you.\n");
    do {
        printf("\n--- Hotel Management System ---\n");
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
                printf("Thank you for using the Hotel Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    // Free allocated memory for all customers
    for (int i = 0; i < customerCount; i++) {
        freeCustomerMemory(customers[i]);
    }
    free(customers);

    return 0;
}
