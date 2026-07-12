#include <stdio.h>
#include <string.h>

void getProductName(char *product, const char *input);

int main() {
  char *test_string = "Price: 1.99, Product: Orange, Weight: 0.2,";
  char *test_string2 = "Price: 1.99, Product: Kiwi, Weight: 0.2,";
  char product_name[99];

  getProductName(product_name, test_string);
  printf("%s\n", product_name);

  getProductName(product_name, test_string2);
  printf("%s\n", product_name);

  return 0;
}

// TODO: Implement the function getProductName
// Hint: You should use strstr() and strchr()
void getProductName(char *product, const char *input) {
  // TODO"
  // Först skulle jag leta efter "product" i input
  // Sen, skulle jag hitta komma tecken för att den som följer efter namnet. 

  //strstr() returnerar en adress. Den skulle sparas i en pekare. 
  //Input är const char * → start bör också vara const char *.

    
  const char *start = strstr(input,"Product: ");
  const char *end = strchr(start,',');
  //start pekar på P in product, end pekar på komma tecknet, jag vill börja loopa från slutet av product då : 
  // jag flyttar start förbi texten "Product:"
  start = start + strlen("Product: ");
  // Nu kan Jag loopa:
  int cnt =0; 
  for(int i=0;i<end-start;i++){
    product[cnt]=start[i];
    cnt++;
  }
  product[cnt]='\0';


  
  }





