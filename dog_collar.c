#include <stdio.h>
#include <stdlib.h> // For rand() and srand()
#include <time.h> // For time() - used to seed the generator
#include "my_functions.h"

int main(){
 int choice;

 struct Dog my_dog;

 srand(time(NULL));

 setup_dog(&my_dog);// fix made to prevent name input reoccurrence.

 while(1){
 printf("\n\n\t\t<<<<<< Welcome to the Dog Tracker Similator >>>>>>\n\n"); // Edit made to improve UX
 printf("\t\tBefore we track down your dog would you like to...\n\n");
 printf("1. Simulate your dog's location manually\n \n\t or\n");
 printf("2. Use random a distance\n");
 printf("0. Exit(press 0 or any number above 2)\n\n");
 printf("---> ");

 scanf("%d",&choice);

 if(choice == 1){

    printf("\n\tNice choice. Enter %s's distance and lets see what happens :-)\n",my_dog.name);
    printf("---> ");
    scanf("%f",&my_dog.distance_from_home);

 }else if(choice == 2){
        /* This logic was developed with assistance from Gemini (Google, 2026)
        Prompt: "Give me the syntax for generating a random float number within
         a specific range (0 to limit + 5.0) for a dog collar simulation."
        */


    float random_scale = (float)rand() / (float)RAND_MAX;
    
    // 2. Scale to desired range (0 to limit + 5.0 for danger tests)
    float max_test_distance = my_dog.limit + 5.0;
    my_dog.distance_from_home = random_scale * max_test_distance;
    
    // Syntax for AI generated code ends here.

    printf("\n\t[RANDOM] %s's bearing is %.2f meters\n",my_dog.name, my_dog.distance_from_home);

    
 } else break;

 update_collar_state(&my_dog);
 dog_status(&my_dog);
 machine_state(collar_state);

 }

 printf("\n\t\t\tThank you for playing. Goodbye..\n\n");
 return 0;
}