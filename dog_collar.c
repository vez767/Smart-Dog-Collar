#include <stdio.h>
#include <string.h>

unsigned char collar_state = 0;

#define LED_PIN (1<<0)
#define SPEAKER_PIN (1<<1)
#define VIB_PIN (1<<2)
#define ALARM_PIN (1<<3) 

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


int main(){
 int choice;

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
 update_collar_state(&my_dog);
 }

 printf("\n\t\t\tThank you for playing. Goodbye..\n\n");
 return 0;
}