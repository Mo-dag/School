/*
 *  Calculate price using type casting
 *
 *  Samples:
 *  -
 */

#include <stdio.h>
#include <math.h>
int main() {
    int coffees;
    int discount;
    float total_price;
    float discounted_price;
    float discount_fraction;

    printf("Enter the number of coffees: ");
    scanf("%d", &coffees);

    printf("Enter the customer's discount percentage: ");
    scanf("%d", &discount);

    // Calculate total cost
    total_price = coffees * 35.0;

    // TODO
    discount_fraction = ((float)discount/100);
    discounted_price = round(total_price - discount_fraction * total_price);    
    printf("\nTotal cost before discount: %.2f kr\n", total_price);
    printf("Total cost after discount: %.2f kr\n", discounted_price);

    return 0;
}
