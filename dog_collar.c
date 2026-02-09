#include <stdio.h>
#include <string.h>

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
        
        {

        printf("\t\t\tWARNING!!!*\n");
        printf("%s is currently %f away from home!.\n", d->name, d->limit + 2.0);
        printf("Alarm and GPS ACTIVATED. Press link to track.\n");
        printf("__GPS__\n\n");


        }
    }

}

int main(){


 struct Dog my_dog;

 while(1){
 printf("\t\tWelcome to the Dog Tracker Similator\n\n");
 setup_dog(&my_dog);
 printf("\t\tBefore we track down your dog would you like to...\n\n");
 printf("1. Simulate your dog's location manually\n \n\n\t or\n\n");
 printf("2. Use random a distance\n");
 printf("0. Exit(press 0 or any number above 2)\n");
 printf("---> ");

 scanf("%d",&choice);

 /*if(choice == 1){
    printf("\n\tNice choice. Enter %s's distance and lets see what happens :-)\n");
    printf("---> ");
    scanf("%f",my_dog.distance_from_home);

    
 }*/

 update_collar_state(&my_dog);
 dog_status(&my_dog);
 }

 printf("\n\t\t\tThank you for playing. Goodbye..\n\n");
 return 0;
}