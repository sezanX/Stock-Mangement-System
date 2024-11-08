#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int itemID;
    char itemName[50];
    int quantity;
    float price;
} Stock;

void addStock(FILE *file) {
    Stock stock;
    printf("Enter Item ID: ");
    scanf("%d", &stock.itemID);
    printf("Enter Item Name: ");
    scanf("%s", stock.itemName);
    printf("Enter Quantity: ");
    scanf("%d", &stock.quantity);
    printf("Enter Price: ");
    scanf("%f", &stock.price);

    fwrite(&stock, sizeof(Stock), 1, file);
    printf("Stock item added successfully.\n");
}

void viewStock(FILE *file) {
    int itemID;
    Stock stock;
    printf("Enter Item ID to view: ");
    scanf("%d", &itemID);

    rewind(file);
    while (fread(&stock, sizeof(Stock), 1, file)) {
        if (stock.itemID == itemID) {
            printf("Item ID: %d\n", stock.itemID);
            printf("Item Name: %s\n", stock.itemName);
            printf("Quantity: %d\n", stock.quantity);
            printf("Price: %.2f\n", stock.price);
            return;
        }
    }
    printf("Stock item not found.\n");
}

void updateStock(FILE *file) {
    int itemID;
    Stock stock;
    printf("Enter Item ID to update: ");
    scanf("%d", &itemID);

    FILE *tempFile = fopen("temp.dat", "wb+");
    if (tempFile == NULL) {
        printf("Unable to open temporary file.\n");
        return;
    }

    rewind(file);
    while (fread(&stock, sizeof(Stock), 1, file)) {
        if (stock.itemID == itemID) {
            printf("Enter new Item Name: ");
            scanf("%s", stock.itemName);
            printf("Enter new Quantity: ");
            scanf("%d", &stock.quantity);
            printf("Enter new Price: ");
            scanf("%f", &stock.price);
        }
        fwrite(&stock, sizeof(Stock), 1, tempFile);
    }

    fclose(file);
    fclose(tempFile);
    remove("stock.dat");
    rename("temp.dat", "stock.dat");
    file = fopen("stock.dat", "rb+");
    printf("Stock item updated successfully.\n");
}

void deleteStock(FILE *file) {
    int itemID;
    Stock stock;
    printf("Enter Item ID to delete: ");
    scanf("%d", &itemID);

    FILE *tempFile = fopen("temp.dat", "wb+");
    if (tempFile == NULL) {
        printf("Unable to open temporary file.\n");
        return;
    }

    rewind(file);
    while (fread(&stock, sizeof(Stock), 1, file)) {
        if (stock.itemID != itemID) {
            fwrite(&stock, sizeof(Stock), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);
    remove("stock.dat");
    rename("temp.dat", "stock.dat");
    file = fopen("stock.dat", "rb+");
    printf("Stock item deleted successfully.\n");
}

void listAllStocks(FILE *file) {
    Stock stock;
    rewind(file);
    printf("\nAll Stock Items:\n");
    printf("Item ID\tItem Name\tQuantity\tPrice\n");
    printf("--------------------------------------------------\n");
    while (fread(&stock, sizeof(Stock), 1, file)) {
        printf("%d\t%s\t%d\t%.2f\n", stock.itemID, stock.itemName, stock.quantity, stock.price);
    }
}

void generateLowStockReport(FILE *file) {
    int threshold;
    Stock stock;
    printf("Enter quantity threshold for low stock report: ");
    scanf("%d", &threshold);

    rewind(file);
    printf("\nLow Stock Items:\n");
    printf("Item ID\tItem Name\tQuantity\tPrice\n");
    printf("--------------------------------------------------\n");
    while (fread(&stock, sizeof(Stock), 1, file)) {
        if (stock.quantity < threshold) {
            printf("%d\t%s\t%d\t%.2f\n", stock.itemID, stock.itemName, stock.quantity, stock.price);
        }
    }
}

int main() {
    FILE *file;
    int choice;

    file = fopen("stock.dat", "rb+");
    if (file == NULL) {
        file = fopen("stock.dat", "wb+");
        if (file == NULL) {
            printf("Unable to open file.\n");
            return 1;
        }
    }

    while (1) {
        printf("\nStock Management System\n");
        printf("1. Add Stock Item\n");
        printf("2. View Stock Item\n");
        printf("3. Update Stock Item\n");
        printf("4. Delete Stock Item\n");
        printf("5. List All Stock Items\n");
        printf("6. Generate Low Stock Report\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(file);
                break;
            case 2:
                viewStock(file);
                break;
            case 3:
                updateStock(file);
                break;
            case 4:
                deleteStock(file);
                break;
            case 5:
                listAllStocks(file);
                break;
            case 6:
                generateLowStockReport(file);
                break;
            case 7:
                fclose(file);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
