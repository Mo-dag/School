/*
 * Introduction to the Switch statement.
 */
#include <stdio.h>

int main() {
  int input;
  printf("Where can I find the following: \nMovies (1)\nBooks  "
         "(2)\nMusic  (3)\n>");
  scanf("%d", &input);

  // TODO you code here.
  switch (input){
    case 1:
    printf("Cinema, Netflix, etc.");
    break;

    case 2:
    printf("Library or book store.");
    break;

    case 3:
    printf("Spotify or sound cloud or apple music.");
    break;

    default:
    printf("%d does not correspond to a category in our list", input);
    break;
  }


  return 0;
}
