#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum ProductType {
    CLOTHING,
    FOOTWEAR,
    ELECTRONICS
};

union ProductDetails {
    int size;       
    float weight;   
};

struct Product {
    char name[100];
    float price;
    enum ProductType type;
    union ProductDetails details;
};

int main() {
    int numProducts;

    printf("Enter the number of products: ");
    scanf("%d", &numProducts);

    struct Product products[numProducts];

    for (int i = 0; i < numProducts; i++) {
        printf("\nEnter information for product %d:\n", i + 1);
        
        printf("Name: ");
        scanf("%s", products[i].name);
        
        printf("Price: ");
        scanf("%f", &products[i].price);

        printf("Type (0: Clothing, 1: Footwear, 2: Electronic): ");
        scanf("%d", (int*)&products[i].type);

        if (products[i].type == CLOTHING || products[i].type == FOOTWEAR) {
            printf("Size: ");
            scanf("%d", &products[i].details.size);
        } else if (products[i].type == ELECTRONICS) {
            printf("Weight: ");
            scanf("%f", &products[i].details.weight);
        }
    }

    char searchName[100];
    printf("\nEnter the name of the product to retrieve information: ");
    scanf("%s", searchName);

    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, searchName) == 0) {
            printf("\nProduct Information:\n");
            printf("Name: %s\n", products[i].name);
            printf("Price: %.2f\n", products[i].price);
            printf("Type: %d\n", products[i].type);
            if (products[i].type == CLOTHING || products[i].type == FOOTWEAR) {
                printf("Size: %d\n", products[i].details.size);
            } else if (products[i].type == ELECTRONICS) {
                printf("Weight: %.2f\n", products[i].details.weight);
            }
            break;
        }
    }

    return 0;
}
