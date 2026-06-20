/*
 *  Introduction to booleans and logic
 *
 *  Samples:
 *  -
 */
#include <stdbool.h>
#include <stdio.h>

int main() {

  int account_balance = 0;
  int purchase_cost = 0;
  float credit_factor = 0;
  float min_credit_factor = 0.3;

  printf("Enter account balance: ");
  scanf("%d", &account_balance);
  printf("Enter credit factor (0-1): ");
  scanf("%f", &credit_factor);
  printf("Enter cost of purchase: ");
  scanf("%d", &purchase_cost);
  
  // TODO Write your logic here.

  if(account_balance >= purchase_cost || (credit_factor > min_credit_factor && account_balance >= (purchase_cost * credit_factor))){
    printf("It is Ok\n");
  }
  else {printf("It is NOT OK\n");}

  return 0;
}
