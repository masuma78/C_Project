#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a medicine
typedef struct {
    int id;
    char name[100];
    float price;
    int quantity;
    char fullName[50];
	char email[50];
	char password[50];
	char username[50];
	char phone[50];
} Medicine, User;
// FILE *fp;
// fp = fopen("Users.dat","a");


// Function prototypes
void displayMenu();
void registerUser(User users[], int *count);
void loginUser(User users[], int count);
void viewProfile(User users[], int count);
void logoutUser(User users[], int count);
void addMedicine(Medicine medicines[], int *count);
void updateMedicine(Medicine medicines[], int count);
void deleteMedicine(Medicine medicines[], int *count);
void displayInventory(Medicine medicines[], int count);

int main() {
    system("color 0b");
    Medicine medicines[100]; // Array to store medicines
    int count = 0; // Number of medicines in inventory

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser(medicines, &count);
                break;
                
            case 2:
            
                loginUser(medicines, count);
                break;
            case 3:
            system("cls");
                viewProfile(medicines, count);
                break;
            case 4:
                logoutUser(medicines, count);
                break;
            case 5:
                addMedicine(medicines, &count);
                break;
            case 6:
                updateMedicine(medicines, count);
                break;
            case 7:
                deleteMedicine(medicines, &count);
                break;
            case 8:
                displayInventory(medicines, count);
                break;
            case 9:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 9);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n===== Medical Store Management System =====\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. View Profile\n");
    printf("4. Logout\n");
    printf("5. Add Medicine\n");
    printf("6. Update Medicine\n");
    printf("7. Delete Medicine\n");
    printf("8. Display Inventory\n");
    printf("9. Exit\n");
}

// Funtion to register a new user
void registerUser(User users[], int *count) {
    printf("\nEnter user details:\n");
    printf("Username: ");
    scanf("%s", users[*count].username);
    printf("Email: ");
    scanf("%s", users[*count].email);
    printf("Password: ");
    scanf("%s", users[*count].password);
    printf("Phone: ");
    scanf("%s", users[*count].phone);
    (*count)++;
    
}

// Function to login as an existing user
void loginUser(User users[], int count) {
    char username[50], password[50];
    printf("\nEnter the login : \n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful.\n");
            return;
        }
        printf("Invalid username or password. Please try again.\n");
        return;
    }

}

// Function to view the profile in user details
void viewProfile(User users[], int count) {
    char username[50], password[50];
    printf("\nEnter the username for view the Profile : \n");
    printf("Username: ");
    scanf("%s", username);
    
    
    for (int i = 0; i < count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("\nUser Details : \n");
            printf("Username: %s\n", users[i].username);
            printf("Email: %s\n", users[i].email);
            printf("Password: %s\n", users[i].password);
            printf("Phone: %s\n", users[i].phone);
            return;
       }
       printf("Invalid username or password. Please try again.\n");
       return;
  }
  
}

// Function to logout as an existing user
void logoutUser(User users[], int count) {
    char username[50], password[50];
    printf("\nEnter the username for logout : \n");
    printf("Username: ");
    scanf("%s", username);
    
    
    for (int i = 0; i < count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Logout successful.\n");
            return;
        }
        printf("Invalid username or password. Please try again.\n");
        return;
    }
    
}



// Function to add a new medicine
void addMedicine(Medicine medicines[], int *count) {
    FILE *file;

    file = fopen("Allmedicines.txt", "a"); // Open the file in append mode

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    printf("\nEnter medicine details:\n");
    printf("ID: ");
    scanf("%d", &medicines[*count].id);
    printf("Name: ");
    scanf("%s", medicines[*count].name);
    printf("Price: ");
    scanf("%f", &medicines[*count].price);
    printf("Quantity: ");
    scanf("%d", &medicines[*count].quantity);
    (*count)++;
    
    fprintf(file, "%d %s %.2f %d\n", medicines[*count].id, medicines[*count].name, medicines[*count].price, medicines[*count].quantity);
    fclose(file);
}

// Function to update an existing medicine
void updateMedicine(Medicine medicines[], int count) {
    int id;
    printf("\nEnter ID of the medicine to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (medicines[i].id == id) {
            printf("Enter new price: ");
            scanf("%f", &medicines[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &medicines[i].quantity);
            printf("Medicine updated successfully.\n");
            return;
        }
    }
    printf("Medicine with ID %d not found.\n", id);
}

// Function to delete a medicine
void deleteMedicine(Medicine medicines[], int *count) {
    int id;
    printf("\nEnter ID of the medicine to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (medicines[i].id == id) {
            // Move all elements after deleted element one position back
            for (int j = i; j < *count - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            (*count)--;
            printf("Medicine deleted successfully.\n");
            return;
        }
    }
    printf("Medicine with ID %d not found.\n", id);
}

// Function to display the inventory
void displayInventory(Medicine medicines[], int count) {
     FILE *file;

    file = fopen("AllMedicines.txt", "r"); // Open the file in append mode

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    printf("\nInventory:\n");
    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
    fprintf(file, "\n");
    fclose(file);
}