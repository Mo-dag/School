// Avståndet räknas enligt Phythagoras. Avstånd = x²+y²
// Om avståndet <=1 , punkten ligger i circlen. Då : inCircle ++, inSquare ++ !


// I uppgiften : 2r is π/4
// Kvadratens sida är : 2r
// Cirkelns area är : π.r²
// Kvadratens area är : (2r)² >> 4r²
// Så : inCircle area / inSquare area >> π.r²/4r² >> π/4 
// Detta förklarar hållandet mellan Cirkelns area & Kvadratens area.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int main(void){
  int loop=100;
  int inCircleArea =0;
  int inSquareArea =0;
  srand((unsigned int)time(NULL));

  for(int i=0;i<loop;i++){
    // För att divisionen sker innan vi spara värde till variabeln, kommer jag att göra explicit casting. 
    double x = (double) rand() / RAND_MAX; // Rand max kommer från biblioteket : stdlib, den är max värde. På så sätt får vi ett tal i intervall mellan 0.0 till 1.0
    double y= (double) rand() / RAND_MAX;    
    //Phythagoras :
    if(x*x+y*y<=1){
      inCircleArea++;
    }
      inSquareArea++;

  }
  double pi= 4.0 *inCircleArea/inSquareArea;
  double real_pi = 4*atan(1); // Vi fick den från uppgiften, betyder vinkeln vars tangent är 1. alltså 45°.
  
  printf("pi : %lf\n",pi); 
  printf("real pi : %lf\n", real_pi);
  printf("Difference is : %lf\n", real_pi-pi);



  return 0;
}
