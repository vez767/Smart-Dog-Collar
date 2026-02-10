#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For rand() and srand()
#include <time.h> // For time() - used to seed the generator

unsigned char collar_state = 0;

#define LED_PIN (1<<0)
#define SPEAKER_PIN (1<<1)
#define VIB_PIN (1<<2)
#define ALARM_PIN (1<<3) 

 int choice;

struct Dog{
    char name[20];
    float distance_from_home;
    float limit;
};

void setup_dog(struct Dog *d){
    printf("\t\tDOG INITIALS MENU\n\n");

    printf("Please enter pet's name :-)\n");
    printf("---> ");
    scanf("%s", d->name);
    printf("\n\t\tName save successful..\n\n");

    printf("Set maximum boundary distance (meters)");
    printf("---> ");
    scanf("%f", &d->limit);

    d->distance_from_home = 0.0;

    printf("\n\t\tBoundary confirmed. %s's tag is set to go...\n", d->name);
}

void update_collar_state(struct Dog *d){
    collar_state = 0;

    if(d->distance_from_home < (d->limit - 2.0))  collar_state = 0;
    else if(d->distance_from_home >= (d->limit - 2.0) && d->distance_from_home < d->limit) collar_state =  LED_PIN;
    else if(d->distance_from_home >= d->limit && d->distance_from_home < (d->limit + 2.0)) collar_state = VIB_PIN | SPEAKER_PIN;
    else collar_state = collar_state | ALARM_PIN;
}

void dog_status(struct Dog *d){
    printf("\n\t\tChecking %s's Status...\n\n",d->name);

    if(collar_state == 0){

        printf("\t\t\t**NOTIFICATION**\n");
        printf("%s is currently within the safe zone.\n", d->name);

    }else{
        if(collar_state & LED_PIN){

        printf("\t\t\t**NOTIFICATION**\n");
        printf("%s is currently within the safe zone but is close to the boundary.\n", d->name);
        printf("...Warning light is already ON...\n\n");

        }if(collar_state &(VIB_PIN | SPEAKER_PIN)){

        printf("\t\t\tWARNING!!!*\n");
        printf("%s is currently out of the safe zone!.\n", d->name);
        printf("Correctional Vibration ACTIVATED. Mic Activated, Tap to speak.\n\n");

        }
        
        if(collar_state & ALARM_PIN){

        printf("\t\t\tWARNING!!!*\n");
        printf("%s is currently %.2f away from home!.\n", d->name, d->distance_from_home); //FIX: distance rounded up to 2 d.p and static distance corrected.
        printf("Alarm and GPS ACTIVATED. Press link to track.\n");
        printf("__GPS__\n\n");


        }
    }

}

int main(){


 struct Dog my_dog;

 srand(time(NULL));

 setup_dog(&my_dog);// fix made to prevent name input reoccurrence.

 while(1){
 printf("\n\tWelcome to the Dog Tracker Similator\n\n"); // Edit made to improve UX
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

 }

 printf("\n\t\t\tThank you for playing. Goodbye..\n\n");
 return 0;
}