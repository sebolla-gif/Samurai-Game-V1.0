#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <allegro.h>

#define WATER_SPEED 1
#define WAVE_AMPLITUDE 5 // Amplitud del movimiento vertical
#define WAVE_FREQUENCY 0.05 // Frecuencia del movimiento vertical

extern BITMAP *moon;
extern BITMAP *light;
extern BITMAP *sea;
extern BITMAP *cloud;
extern BITMAP *title;
extern BITMAP *press;

void destroy_all_maps();
void update_screen(BITMAP* buffer);
void ShowMap();
void ShowIntro();
void load_resources();

#endif // SCREEN_H_INCLUDED
