#ifndef START_H_INCLUDED
#define START_H_INCLUDED

#include <iostream>
#include <allegro.h>
#include <cmath>
#include <ctime>

#define VX 1440
#define VY 900

#define FPS 14
#define FRAME_TIME 1000 / FPS

#define rows 10
#define cols 6

extern BITMAP *buffer;
extern BITMAP *moon;
extern BITMAP *light;
extern BITMAP *sea;
extern BITMAP *cloud;
extern BITMAP *title;
extern BITMAP *press;

void start_program();
int** create_matrix();
void initialize_matrix(int** matrix);
void free_matrix(int** matrix);
int** obtenerMatriz(int numero);
void TimeControl(int startTime);
void menu();


#endif // START_H_INCLUDED
