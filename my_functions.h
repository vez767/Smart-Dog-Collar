#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#define LED_PIN (1<<0)
#define SPEAKER_PIN (1<<1)
#define VIB_PIN (1<<2)
#define ALARM_PIN (1<<3) 

 extern unsigned char collar_state;

 typedef struct{
    float lat;
    float lon;
 }Location;

struct Dog{
    char name[20];
    float distance_from_home;
    float limit;
    Location current_pos;
    Location home;
};

void setup_dog(struct Dog *d);
void update_collar_state(struct Dog *d);
void dog_status(struct Dog *d);
void machine_state(unsigned char state);
float get_distance(Location a, Location b);

#endif
