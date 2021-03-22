#include <wiringPi.h>
#include <softTone.h>
#include <stdio.h>
#define lo    	1000
#define sh		500
typedef struct {
	int tone;
	int timer;
} SONG;

SONG song[] = {
	{261, lo},
	{293, sh},
	{329, lo}, 
	{349, sh}, 
	{391, lo}, 
	{440, sh}, 
	{493, lo},
	{523, sh}
	};

int main () {
	int i;
	printf ("Tone Test\n");
	
	if (wiringPiSetupGpio() == -1) {
		printf ("Failed\n");
		return 1;
	}

	softToneCreate (12);
	for (i = 0; i < sizeof(song) / sizeof(SONG); i++){
		softToneWrite (12, song[i].tone);
		printf ("%d\n", i + 1);
		delay (song[i].timer);
	}

	softToneWrite (12, 0);

	return 0;
}
