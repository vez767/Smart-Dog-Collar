#include <stdio.h>
#include <stdlib.h> // For rand() and srand()
#include <time.h> // For time() - used to seed the generator
#include "my_functions.h"

int main(){
 int choice;
 char menu_buffer [10]; // buffer for menu input
 char lat_buffer[20];
 char long_buffer[20];

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

 
 fgets(menu_buffer,sizeof(menu_buffer), stdin);

 choice = atoi(menu_buffer);

 if(choice == 1){
   
       /* This logic was developed with assistance from Gemini (Google, 2026)
        Prompt: "Give me the syntax for limiting the user's geospaital input to a Micro-offset level from the specified base."
        */
  
      float lat_offset, lon_offset;

      printf("\n\t[GPS SIMULATOR] Fine-tuning local coordinates...\n");
      printf("\tHome Base is at 51.38540 N, 0.54840 E (Kent Area)\n\n");
        
       // 1. LATITUDE INPUT
      printf("\tLatitude (51.3854xx) - Enter the last 2 digits (e.g., 70): ");
      fgets(lat_buffer,sizeof(lat_buffer), stdin);

      lat_offset = atof(lat_buffer);
        
      // Engine Math: 51.3800 + (70 / 10000) = 51.3870
      my_dog.current_pos.lat = 51.38540 + (lat_offset / 1000000.0);

      // 2. LONGITUDE INPUT
      printf("\tLongitude (0.5484xx) - Enter the last 2 digits (e.g., 90): ");

      fgets(long_buffer,sizeof(long_buffer), stdin);

      lon_offset = atof(long_buffer);
        
      // Engine Math: 0.5400 + (90 / 10000) = 0.5490
      my_dog.current_pos.lon = 0.54840 + (lon_offset / 1000000.0);

                                     /* Syntax for AI generated code ends here.*/



      my_dog.distance_from_home = get_distance(my_dog.home, my_dog.current_pos);
        
      printf("\n\t%s's simulated coordinates: %.4f, %.4f\n", my_dog.name, my_dog.current_pos.lat, my_dog.current_pos.lon);
      printf("\tCalculated distance from home: %.2f meters\n", my_dog.distance_from_home);
    

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