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



int main(){
    printf("Firmware Booting..\n");
    return 0;
}