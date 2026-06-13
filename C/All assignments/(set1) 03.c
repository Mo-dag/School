#include <stdio.h>
#include <stdbool.h>
int main() {

    float pi = 3.1415926;
    int selection;
    float input;
    float result;
    //Radian = Degree * π/180

    //Degree = Radian * 180/π
    bool isRunning = true;
    while(isRunning){

        printf("Select\n1) For Deg to rad\n2) For Rad to deg\n> ");
        scanf("%d", &selection);
    // TODO
    if(selection == 1){
        printf("Please insert angle in deg : ");
        scanf("%f", &input);
        result = input * (pi/180);
        printf("Input angle in rad: %.4f\n", result);
        isRunning = false;
}
    else if(selection ==2){
        printf("Please insert angle in rad : ");
        scanf("%f", &input);
        result = input * (180/pi);
        printf("Input angle in deg: %.4f\n", result);
        isRunning = false;
    }

    else{continue;} // Continue hoppar över resten av koden i loopen och går direkt till nästa varv.
    }

	
	return 0;
}
