#include <ctype.h>
#include <stdio.h>
#include <string.h>
// strcspn : string complement span : använder jag den för att hitta första position av tecken jag välja.
// strcspn(strängnamn, "den tecken jag letar efter !");
// strcmp  : string compare : använder jag den för att jämföra 2 strängar innehåll. Den returnera 0 om de är lika.!
// fgets   : Jag använder den istället för : scanf. Den avsedd för text. Den tolerera mellanslag. 
// tolower : från ctype.h bib.  
const int MAX_INPUT_SIZE = 50; 


void pricing(char arr[], int *price);


int main() {
  char input[MAX_INPUT_SIZE]; //\0 är den 50 component av strängen.
  int amount = 0, price = 0, total = 0;

  printf(
      "Welcome to the new and improved coffe shop.\nOur new and improved "
      "system also accepts text as input.\nFirst select the product and then "
      "the number of items.\nAvailable products:\n- Coffee (45 kr)\n- Tea (40 "
      "kr)\n- Chocolate (50 kr)\n- Cinnamon bun (25 kr)\n");

  printf("Enter order: ");

  // TODO read input from standard input (stdin) using fgets
   
  fgets(input,50,stdin); //stdin == standard input :>
  // TODO remove new line character (\n) from the string
  // De vill att jag ta bort ENTER som man trycker i slutet av order.
  /*
  for(int i=0;i<50;i++){
    if(input[i]=='\n'){
      input[i]='\0';
      break;
    }
  }
  */
input[strcspn(input,"\n")]= '\0';
  // TODO Normalise input (make all characters same case)
  for(int i=0;i<MAX_INPUT_SIZE;i++){
    input[i]=tolower(input[i]);
  }
  // TODO
  // Coffe shop logic here. Use strcmp. NOTE: strcmp returns 0 if strings are equal. 
  // STRCMP för : string compare ! 

  pricing(input, &price);
  printf("How many do you want: \n");
  scanf("%d", &amount);
  // TODO Calculate total cost and print.
  total = price * amount;

  printf("Total cost : %d\n", total);
  printf("Thank you!\n");
  return 0;
}


void pricing(char *listing,int *price){
  if      (strcmp(listing,"coffee")==0)      {*price=45;}
  else if (strcmp(listing,"tea")==0)         {*price=40;}
  else if (strcmp(listing,"chocolate")==0)   {*price=50;}
  else if (strcmp(listing,"cinnamon bun")==0){*price=25;}
}
