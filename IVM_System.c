#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    char name[50];
    int quantity;
    float price;
};

void addItem(struct Item *items, int *size) {
    if (*size == MAX_ITEMS) {
        printf("Inventory is full.\n");
        return;
    }
 
    printf("Enter item name: ");
    scanf("%s", items[*size].name);
    printf("Enter quantity: ");
    scanf("%d", &items[*size].quantity);
    printf("Enter price: ");
    scanf("%f", &items[*size].price);

    (*size)++;
    printf("Item added successfully.\n");
}

void viewItems(struct Item *items, int size) {
    printf("Item Name\tQuantity\tPrice\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%d\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void updateItem(struct Item *items, int size) {
    int index;
    printf("Enter item index to update: ");
    scanf("%d", &index);

    if (index < 0 || index >= size) {
        printf("Invalid index.\n");
        return;
    }

    printf("Enter new quantity: ");
    scanf("%d", &items[index].quantity);
    printf("Enter new price: ");
    scanf("%f", &items[index].price);

    printf("Item updated successfully.\n");
}

void deleteItem(struct Item *items, int *size) {
    int index;
    printf("Enter item index to delete: ");
    scanf("%d", &index);

    if (index < 0 || index >= *size) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        items[i] = items[i + 1];
    }

    (*size)--;
    printf("Item deleted successfully.\n");
}

int main() {
    struct Item items[MAX_ITEMS];
    int size = 0;
    int choice;

    while (1) {
        printf("1. Add item\n");
        printf("2. View items\n");
        printf("3. Update item\n");
        printf("4. Delete item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(items, &size);
                break;
            case 2:
                viewItems(items, size);
                break;
            case 3:
                updateItem(items, size);
                break;
            case 4:
                deleteItem(items, &size);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}