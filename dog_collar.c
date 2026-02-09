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

    printf("Enter pet's name :-)\n");
    printf("---> ");
    scanf("%s", d->name);
    printf("\n\t\tName save successful..\n\n");

    printf("Set maximum boundary distance (meters)");
    printf("---> ");
    scanf("%f", &d->limit);

    d->distance_from_home = 0.0;

    printf("\n\t\tBoundary confirmed. %s's tag is set to go...\n", d->name);
}
int main(){
 struct Dog my_dog;
 setup_dog(&my_dog);
 return 0;
}