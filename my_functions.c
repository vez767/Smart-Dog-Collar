#include "my_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 unsigned char collar_state = 0;

 void setup_dog(struct Dog *d){
    printf("\t\tDOG INITIALS MENU\n\n");

    printf("Please enter pet's name :-)\n");
    printf("---> ");
    
    fgets(d->name, sizeof(d->name), stdin);
    char *ptr = d->name;
    while(*ptr != '\0'){
        if(*ptr == '\n'){
            *ptr ='\0';
        }
        ptr++;
    }
    printf("\n\t\tName save successful..\n\n");
 
   d->home.lat = 48.8584; // Eiffiel tower cordinates hardcoded for location datapacket demonstration
   d->home.lon = 2.2945;

   d->current_pos = d->home; // Initialize Current Position (Start at home)

   printf("GPS system initialized...\n");
   printf("Home set to %.4f, %.4f",d->home.lat, d-> home.lon);
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

 void machine_state(unsigned char state){
    printf("Dog collar state(8 bit):\t\t\t|Bits|(Note: N/F - No Function) \n");
    printf("\t\t|[7]\t|[6]\t|[5]\t|[4]\t|[3]\t\t|[2]\t\t|[1]\t\t|[0]\n");
    printf("\t\t|[NF]\t|[NF]\t|[NF]\t|[NF]\t|[ALARM]\t|[VIBRATION]\t|[SPEAKER]\t|[LED]\n");
    printf("\nCollar state: ");

    for(int i = 7; i>=0; i--){
       int print_state = (state >> i) & 1;
       printf("\t|  %d", print_state);
    }
    printf("\n\n");
 }

 // function to calculate distances from longitude and latitude coordinates
 float get_distance(Location a, Location b){ 
    float lat_diff = a.lat - b.lat;
    float long_diff = a.lon - b.lon;

    float h_dist = long_diff * 111000;
    float v_dist = lat_diff * 111000;

    float dist = sqrt((v_dist * v_dist) + (h_dist * h_dist)); //FIX: 

    return dist;
 }
 